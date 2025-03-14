#include "character.h"

Character::Character(const sf::Vector2f &characterSize, const sf::Vector2f& characterStartingPos, const sf::Font& font)
{
    characterShape.setSize(characterSize);
    characterShape.setPosition(characterStartingPos);
    characterShape.setFillColor(sf::Color::Blue);
    characterPos = characterStartingPos;
    characterFont = font;
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(characterShape);
}

void Character::update(const sf::Time& deltaTime)
{
}

void Character::SetPosition(const sf::Vector2f &newPos)
{
    characterShape.setPosition(newPos);
}


