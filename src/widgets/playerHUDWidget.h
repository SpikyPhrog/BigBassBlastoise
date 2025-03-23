#pragma once
#include "baseWidget.h"

class PlayerScoreWidget;
class EventManager;
class PlayerHealthWidget;

class PlayerHUD : public BaseWidget
{
public:
    PlayerHUD(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<EventManager> inEventManager);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;

private:
    std::shared_ptr<PlayerScoreWidget> scoreWidget              {nullptr};
    std::shared_ptr<PlayerHealthWidget> healthWidget            {nullptr};
};