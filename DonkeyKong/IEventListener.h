#pragma once

#include <unordered_map>
#include <iostream>

enum class EventKeys {
	Test,
	Application_Quit,
	Application_Pause,
};

typedef std::unordered_map<std::string, void*> Parameters;

class IEventListener
{
public:
	virtual void OnEventTrigger(EventKeys eventName, Parameters params) = 0;
};