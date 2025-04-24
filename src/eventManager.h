#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "consts.h"

class EventListener;

class EventManager 
{
public:
    EventManager();

    void Add(const EventTypes& eventType, std::shared_ptr<EventListener> listener);
    void Remove(const EventTypes& eventType, std::shared_ptr<EventListener> listenerToRemove);

    void Broadcast(const EventTypes& eventType, void* data);
    void Broadcast(const EventTypes& eventType, void* data, std::shared_ptr<EventListener> listener);

private:
    std::unordered_map<std::shared_ptr<EventListener>, EventTypes> listeners;
};