#include "gameOverWidget.h"
#include "textWidget.h"

GameOverWidget::GameOverWidget(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    float windowSizeX = window->getSize().x;
    float windowSizeY = window->getSize().y;
    sf::Vector2f size {windowSizeX, windowSizeY};
    background = std::make_unique<sf::RectangleShape>(size);
    background->setFillColor(sf::Color::Magenta);

    gameOverText = std::make_unique<TextWidget>(font, "Game Over", window);
    gameOverText->SetPosition(sf::Vector2f(windowSizeX/2, windowSizeY/2));
    gameOverText->CenterOrigin();
}

void GameOverWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    assert(background != nullptr);
    assert(gameOverText != nullptr);

    target.draw(*background);
    gameOverText->draw(target, states);
}

void GameOverWidget::SetPosition(const sf::Vector2f &newPosition)
{
}

const sf::Vector2f &GameOverWidget::GetPosition()
{
    if (background)
    {
        return background->getPosition();
    }
    return sf::Vector2f(0.f, 0.f);    
}

const sf::Vector2f &GameOverWidget::GetSize()
{
    if (background)
    {
        return background->getSize();
    }
    return sf::Vector2f(0.f, 0.f);
}

void GameOverWidget::update()
{
}
