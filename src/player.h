#pragma once
#include "stdafx.h"
#include "character.h"

class Player : public Character
{
public:
    Player(const sf::Vector2f& characterSize, const sf::Vector2f& characterStartingPos, const sf::Font& font);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(const sf::Time& deltaTime) override;

    void UpdateScoring(float timeForWord);

    void IncreaseLives();
    void DecreaseLives();

private:
    int lives                                                   {3};
    int score                                                   {0};
    int multiplier                                              {1};
    std::unique_ptr<sf::Text> scoreText                         {nullptr};
    std::unique_ptr<sf::Text> livesText                         {nullptr};
    
    
};