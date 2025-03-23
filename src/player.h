#pragma once
#include "stdafx.h"
#include "character.h"

class Player : public Character
{
public:
    Player(const sf::Vector2f& characterStartingPos, const sf::Font& font);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(const sf::Time& deltaTime) override;
};