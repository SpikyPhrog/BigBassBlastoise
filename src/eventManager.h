#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "consts.h"

class EventListener;

class EventManager 
{
public:
    void Add(const EventTypes& eventType, std::shared_ptr<EventListener> listener);
    void Remove(const EventTypes& eventType, std::shared_ptr<EventListener> listenerToRemove);

    void Broadcast(const EventTypes& eventType, const int& data);

private:
    std::unordered_map<EventTypes, std::shared_ptr<EventListener>> listeners;
};