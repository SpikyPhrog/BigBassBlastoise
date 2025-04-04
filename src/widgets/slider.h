#pragma once
#include "baseWidget.h"
#include "../eventListener.h"

class Slider : public BaseWidget, public EventListener
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
    
private:
    void AlignKnobPosition();

protected:
    std::shared_ptr<sf::RectangleShape> sliderLine;
    std::shared_ptr<sf::CircleShape> sliderKnob;

    bool bIsClicked                                             {false};
    float value                                                 {0.f};
    sf::Vector2f startPoint                                     {0.f, 0.f};
    sf::Vector2f endPoint                                       {0.f, 0.f};
    sf::Color HoveredColor                                      {sf::Color::Green};
    sf::Color NormalColor                                       {sf::Color::Red};
    sf::Color ClickedColor                                      {sf::Color::Cyan};
};
