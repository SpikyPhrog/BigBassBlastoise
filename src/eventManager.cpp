#include "eventManager.h"
#include "eventListener.h"

EventManager::EventManager()
{
}

void EventManager::Add(const EventTypes &eventType, std::shared_ptr<EventListener> listener)
{
    listeners.insert({listener, eventType});
}

void EventManager::Remove(const EventTypes &eventType, std::shared_ptr<EventListener> listenerToRemove)
{
    if(listeners.size() > 0 )
    {
        for(auto it = listeners.begin(); it != listeners.end();)
        {
            if (it->first == listenerToRemove)
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
            if (it->second == eventType)
            {
                it->first->Update(data);
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
            if (it->second == eventType && it->first == listener)
            {
                it->first->Update(data);
            }
        }
    }
}
