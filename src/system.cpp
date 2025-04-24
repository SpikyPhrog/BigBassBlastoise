#include "system.h"

std::shared_ptr<System> System::system_ = nullptr;

System::System()
{
    config = std::make_unique<Config>();
    eventManager = std::make_unique<EventManager>();
    statManager = std::make_unique<StatManager>();
}

std::shared_ptr<System> System::Get()
{  
    if (system_ == nullptr)
    {
        system_ = std::make_shared<System>();
    }
    
    return system_;
}

void System::AddEvent(const EventTypes &eventType, std::shared_ptr<EventListener> listener)
{
    eventManager->Add(eventType, listener);
}

void System::BroadcastEvent(const EventTypes &eventType, void *data)
{
    eventManager->Broadcast(eventType, data);
}

void System::BroadcastEvent(const EventTypes &eventType, void *data, std::shared_ptr<EventListener> listener)
{
    eventManager->Broadcast(eventType, data, listener);
}
