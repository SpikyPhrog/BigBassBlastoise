#include "playerHealthWidget.h"
#include "../consts.h"

PlayerHealthWidget::PlayerHealthWidget(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    std::string lives = "Lives: " + std::to_string(playerStartHealth);
    livesText = std::make_unique<sf::Text>(font, lives, 25);
    livesText->setPosition(sf::Vector2f(100.f, 0.f));
}

void PlayerHealthWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    assert(livesText != nullptr);
    
    target.draw(*livesText);
}

void PlayerHealthWidget::SetPosition(const sf::Vector2f& newPosition)
{

}

const sf::Vector2f& PlayerHealthWidget::GetPosition()
{
    return sf::Vector2f(0.f,0.f);
}

const sf::Vector2f& PlayerHealthWidget::GetSize()
{
    return sf::Vector2f(0.f,0.f);
}

void PlayerHealthWidget::update()
{

}

void PlayerHealthWidget::Update(const int& data)
{
    assert(livesText != nullptr);

    std::string lives = "Lives: " + std::to_string(data);
    
    livesText->setString(lives);
}
