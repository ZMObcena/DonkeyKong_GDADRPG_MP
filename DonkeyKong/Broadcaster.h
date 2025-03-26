#pragma once

#include <unordered_map>
#include <vector>
#include "IEventListener.h"

typedef std::vector<IEventListener*> ObserverList;
typedef std::unordered_map<EventKeys, ObserverList> ObserverMap;

class Broadcaster
{
public:
	static Broadcaster* getInstance();
	void AddObserver(EventKeys event, IEventListener* listener);
	void RemoveObserver(EventKeys event, IEventListener* listener);
	void Broadcast(EventKeys event, Parameters params);
	void Broadcast(EventKeys event);

private:
	Broadcaster() {};
	Broadcaster(Broadcaster const&) {};
	Broadcaster& operator = (Broadcaster const&) {};

	static Broadcaster* sharedInstance;

	ObserverMap observerMap;
};

