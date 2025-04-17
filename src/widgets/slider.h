#pragma once
#include "menuWidget.h"
#include "../eventListener.h"
#include "../configs.h"

class Slider : public MenuWidget, public EventListener
{
public:
    Slider(std::shared_ptr<sf::RenderWindow> window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;

    const float& GetValue() { return value; }
    void SetValue(const float& inValue);
    
    const std::string& GetName();
    void SetName(const std::string& newName);
    const std::shared_ptr<Slider>& Get();
    void SetSelf (std::shared_ptr<Slider> newSelf);
    void SetConfigSetting(const Configs& newConf);

private:
    void AlignKnobPosition();

    std::string name {"Base slider class"};

protected:
    std::shared_ptr<sf::RectangleShape> sliderLine              {nullptr};
    std::shared_ptr<sf::CircleShape> sliderKnob                 {nullptr};

    std::shared_ptr<Slider> self                                {nullptr};

    bool bIsClicked                                             {false};
    float value                                                 {0.f};
    sf::Vector2f startPoint                                     {0.f, 0.f};
    sf::Vector2f endPoint                                       {0.f, 0.f};
    sf::Color HoveredColor                                      {sf::Color::Green};
    sf::Color NormalColor                                       {sf::Color::Red};
    sf::Color ClickedColor                                      {sf::Color::Cyan};

    // ODDLY SPECIFIC, might need to be removed if this is to be abstracted

    Configs configSetting                                       {Configs::None};
};
