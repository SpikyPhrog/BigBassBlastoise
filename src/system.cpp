#include "system.h"

std::shared_ptr<System> System::system_ = nullptr;

std::random_device dev;
std::mt19937 rng(dev());

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

void System::AddEvent(const EventTypes &eventType, std::shared_ptr<EventListener> listener, const Configs &config)
{
    eventManager->Add(eventType, listener, config);
}

void System::BroadcastEvent(const EventTypes &eventType, void *data)
{
    eventManager->Broadcast(eventType, data);
}

void System::BroadcastEvent(const EventTypes &eventType, void *data, std::shared_ptr<EventListener> listener)
{
    eventManager->Broadcast(eventType, data, listener);
}

int System::GetRandomNumber(const int& rangeA, const int& rangeB)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(rangeA, rangeB);
    int randomNumber = dist(rng);

    return randomNumber;
}
