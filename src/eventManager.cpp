#include "eventManager.h"
#include "eventListener.h"
#include "logger.h"

EventManager::EventManager()
{
}

void EventManager::Add(const EventTypes &eventType, std::shared_ptr<EventListener> listener)
{
    if (auto listenerSearch = listeners.find(eventType); listenerSearch != listeners.end())
    {
        if (listenerSearch->second == listener)
        {
            Logger::Log(LoggerLevel::ERROR, "%s %s %p", "Duplicate found for listener", GetStringEventTypes(eventType), listener.get());
            return;
        }
    }

    listeners.insert({eventType, listener});
}

void EventManager::Add(const EventTypes &eventType, std::shared_ptr<EventListener> listener, const Configs& config)
{
    Add(eventType, listener);
    events.try_emplace(config, eventType);
}

void EventManager::Remove(const EventTypes &eventType, std::shared_ptr<EventListener> listenerToRemove)
{
    if(listeners.size() > 0 )
    {
        for(auto it = listeners.begin(); it != listeners.end();)
        {
            if (it->second == listenerToRemove)
            {
                it = listeners.erase(it);
            }
        }
    }
}

void EventManager::Broadcast(const EventTypes &eventType, void* data)
{
    if(listeners.size() > 0 )
    {
        for (auto it = listeners.begin(); it != listeners.end(); ++it)
        {
            if (it->first == eventType)
            {
                it->second->Update(data);
            }
        }
    }
}

void EventManager::Broadcast(const EventTypes &eventType, void *data, std::shared_ptr<EventListener> listener)
{
    if(listeners.size() > 0 )
    {
        for (auto it = listeners.begin(); it != listeners.end(); ++it)
        {
            if (it->first == eventType && it->second == listener)
            {
                it->second->Update(data);
            }
        }
    }
}

const EventTypes &EventManager::GetEventType(const Configs &config)
{
    Logger::Log(LoggerLevel::DEBUG, "%s %s", "[GET EVENT TYPE] Config", GetStringConfigs(config));
    if (auto event = events.find(config); event != events.end())
    {
        return event->second;
    }

    return EventTypes::NONE;
}
