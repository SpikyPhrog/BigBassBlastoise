#include "player.h"
#include <iostream>
#include "gameManager.h"
#include "consts.h"

Player::Player(const sf::Vector2f& characterStartingPos, const sf::Font& font):
Character(characterStartingPos, font)
{
    characterShape->setFillColor(sf::Color::Green);
    characterShape->setSize(sf::Vector2f(playerCharacterSize, playerCharacterSize));
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Character::draw(target, states);
}

void Player::update(const sf::Time& deltaTime)
{
}

void Player::UpdateScoring(float timeForWord)
{
    //multiplier + (timeFinishedWord - timeStartedWord) 
    score += (1 / timeForWord )* 10;
    std::string scoreString = "Score: " + std::to_string(score);
    
    // scoreText->setString(scoreString);

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
    // livesText->setString(livesString);
}

void Player::DecreaseLives()
{
    if (lives > 0)
    {
        lives --;
        
        std::string livesString = "Lives: " + std::to_string(lives);
        // livesText->setString(livesString);
        return;
    }
    
    GameManager::SetGameState(GameStates::GameOver);
}
