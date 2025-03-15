#include "player.h"
#include <iostream>

Player::Player(const sf::Vector2f& characterSize, const sf::Vector2f& characterStartingPos, const sf::Font& font):
Character(characterSize, characterStartingPos, font)
{
    characterShape->setFillColor(sf::Color::Green);

    std::string scoreString = "Score: " + std::to_string(score);
    std::string livesString = "Lives: " + std::to_string(lives);

    scoreText = std::make_unique<sf::Text>(font, scoreString, 25);
    livesText = std::make_unique<sf::Text>(font, livesString, 25);

    scoreText->setPosition(sf::Vector2f(0.f, 0.f));
    livesText->setPosition(sf::Vector2f(100.f, 0.f));
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Character::draw(target, states);
    target.draw(*scoreText);
    target.draw(*livesText);
}

void Player::update(const sf::Time& deltaTime)
{
}

void Player::UpdateScoring(float timeForWord)
{
    //multiplier + (timeFinishedWord - timeStartedWord) 
    score += (1 / timeForWord )* 10;
    std::string scoreString = "Score: " + std::to_string(score);
    
    scoreText->setString(scoreString);

    IncreaseLives();
}

void Player::IncreaseLives()
{
    /// TODO think of a better formula for this
    if (score % 100 == 0)
    {
        lives ++;
    }
    
    std::string livesString = "Lives: " + std::to_string(lives);
    livesText->setString(livesString);
}

void Player::DecreaseLives()
{
    if (lives > 0)
    {
        lives --;
        
        std::string livesString = "Lives: " + std::to_string(lives);
        livesText->setString(livesString);
        return;
    }
 
    std::cout << "GAME OVER \n";
    
}
