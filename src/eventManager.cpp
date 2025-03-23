#include "eventManager.h"
#include "eventListener.h"

void EventManager::Add(const EventTypes &eventType, std::shared_ptr<EventListener> listener)
{
    listeners.insert({eventType, listener});
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

void EventManager::Broadcast(const EventTypes &eventType, const int &data)
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
