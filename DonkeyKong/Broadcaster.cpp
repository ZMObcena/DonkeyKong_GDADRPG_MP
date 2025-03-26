#include "Broadcaster.h"

void Broadcaster::AddObserver(EventKeys event, IEventListener* listener)
{
	this->observerMap[event].push_back(listener);
}

void Broadcaster::RemoveObserver(EventKeys event, IEventListener* listener)
{
	ObserverList* observerList = &this->observerMap[event];
	observerList->erase(std::remove(observerList->begin(), observerList->end(), listener), observerList->end());
	observerList->shrink_to_fit();
}

void Broadcaster::Broadcast(EventKeys event, Parameters params)
{
	for (int i = 0; i < this->observerMap[event].size(); i++)
	{
		this->observerMap[event][i]->OnEventTrigger(event, params);
	}
}

void Broadcaster::Broadcast(EventKeys event)
{
	Parameters params;
	for (int i = 0; i < this->observerMap[event].size(); i++)
	{
		this->observerMap[event][i]->OnEventTrigger(event, params);
	}
}
