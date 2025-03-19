#pragma once
#include "baseWidget.h"

class TextWidget;

class GameOverWidget : public BaseWidget
{
public:
    GameOverWidget(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    void SetPosition(const sf::Vector2f& newPosition);
    const sf::Vector2f& GetPosition();
    const sf::Vector2f& GetSize();
    void update();

private:
    std::unique_ptr<sf::RectangleShape> background              {nullptr};
    std::unique_ptr<TextWidget> gameOverText                    {nullptr};
};