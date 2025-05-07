#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "eventTypes.h"
#include "configs.h"

class EventListener;

class EventManager 
{
public:
    EventManager();

    void Add(const EventTypes& eventType, std::shared_ptr<EventListener> listener);
    void Add(const EventTypes& eventType, std::shared_ptr<EventListener> listener, const Configs& config);
    void Remove(const EventTypes& eventType, std::shared_ptr<EventListener> listenerToRemove);

    void Broadcast(const EventTypes& eventType, void* data);
    void Broadcast(const EventTypes& eventType, void* data, std::shared_ptr<EventListener> listener);

    // std::pair<Configs, EventTypes> GetEventType(const Configs& config);
    const EventTypes& GetEventType(const Configs& config);
    
private:
    std::unordered_map<EventTypes, std::shared_ptr<EventListener>> listeners;
    std::unordered_map<Configs, EventTypes> events;
};