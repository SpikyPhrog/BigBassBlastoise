#include "eventManager.h"
#include "eventListener.h"

std::shared_ptr<EventManager> EventManager::eventManager_ = nullptr;

EventManager::EventManager()
{
    config = std::make_unique<Config>();
}

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
    listeners.try_emplace(listener, eventType);
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
