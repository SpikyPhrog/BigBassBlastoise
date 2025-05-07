#pragma once
#include "stdafx.h"
#include "config.h"
#include "eventManager.h"
#include "statManager.h"
#include "eventTypes.h"
#include "configs.h"

class System
{
public:
    System();
    System(System& other) = delete;
    void operator=(const System& other) = delete;
    static std::shared_ptr<System> Get();

    void AddEvent(const EventTypes& eventType, std::shared_ptr<EventListener> listener);
    void AddEvent(const EventTypes& eventType, std::shared_ptr<EventListener> listener, const Configs& config);
    void BroadcastEvent(const EventTypes& eventType, void* data);
    void BroadcastEvent(const EventTypes& eventType, void* data, std::shared_ptr<EventListener> listener);

    std::unique_ptr<Config> config                              {nullptr};
    std::unique_ptr<EventManager> eventManager                  {nullptr};
    std::unique_ptr<StatManager> statManager                    {nullptr};
    
protected:
    static std::shared_ptr<System> system_;
};
