#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "consts.h"
#include "config.h"

class EventListener;

class EventManager 
{
protected:
    static std::shared_ptr<EventManager> eventManager_;
    
public:
    EventManager();
    EventManager(EventManager& other) = delete;
    void operator=(const EventManager& other) = delete;
    static std::shared_ptr<EventManager> GetInstance();
    

    void Add(const EventTypes& eventType, std::shared_ptr<EventListener> listener);
    void Remove(const EventTypes& eventType, std::shared_ptr<EventListener> listenerToRemove);

    void Broadcast(const EventTypes& eventType, void* data);

    std::unique_ptr<Config> config                              {nullptr};

private:
    std::unordered_map<EventTypes, std::shared_ptr<EventListener>> listeners;
};