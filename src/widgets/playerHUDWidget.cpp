#include "playerHUDWidget.h"
#include "../consts.h"

PlayerHUD::PlayerHUD(const sf::Font &font, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    std::string scoreString = "Score: " + std::to_string(0);
    std::string livesString = "Lives: " + std::to_string(0);

    scoreText = std::make_unique<sf::Text>(font, scoreString, 25);
    livesText = std::make_unique<sf::Text>(font, livesString, 25);

    scoreText->setPosition(sf::Vector2f(0.f, 0.f));
    livesText->setPosition(sf::Vector2f(100.f, 0.f));
}

void PlayerHUD::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    assert(scoreText != nullptr);
    assert(livesText != nullptr);

    target.draw(*scoreText);
    target.draw(*livesText);
}

void PlayerHUD::SetPosition(const sf::Vector2f &newPosition)
{
}

const sf::Vector2f &PlayerHUD::GetPosition()
{
    return sf::Vector2f(0.f, 0.f);
    // TODO: insert return statement here
}

const sf::Vector2f &PlayerHUD::GetSize()
{
    // TODO: insert return statement here
    return sf::Vector2f(0.f, 0.f);
}

void PlayerHUD::update()
{

}
