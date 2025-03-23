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