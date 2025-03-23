#include "playerScoreWidget.h"

PlayerScoreWidget::PlayerScoreWidget(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    scoreText = std::make_unique<sf::Text>(font, "Score: 0", 25);
    scoreText->setPosition(sf::Vector2f(0.f, 0.f));
}

void PlayerScoreWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    assert(scoreText != nullptr);
    
    target.draw(*scoreText);
}

void PlayerScoreWidget::SetPosition(const sf::Vector2f& newPosition)
{

}

const sf::Vector2f& PlayerScoreWidget::GetPosition()
{
    return sf::Vector2f(0.f,0.f);
}

const sf::Vector2f& PlayerScoreWidget::GetSize()
{
    return sf::Vector2f(0.f,0.f);
}

void PlayerScoreWidget::update()
{

}

void PlayerScoreWidget::Update(const int& data)
{
    std::string score = "Score: " + std::to_string(data);
    scoreText->setString(score);
}
