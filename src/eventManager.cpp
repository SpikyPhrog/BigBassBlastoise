#include "eventManager.h"
#include "eventListener.h"

std::shared_ptr<EventManager> EventManager::eventManager_ = nullptr;

std::shared_ptr<EventManager> EventManager::GetInstance()
{
    if(eventManager_ == nullptr)
    {
        eventManager_ = std::make_shared<EventManager>();
    }

    return eventManager_;
}

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
 