#pragma once
#include "baseWidget.h"
#include "../eventListener.h"
#include "SFML/Graphics/Text.hpp"

class PlayerHealthWidget : public BaseWidget, public EventListener
{
public:
    PlayerHealthWidget(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;
    void Update(const int& data) override;

private:
    std::unique_ptr<sf::Text> livesText                         {nullptr};
};