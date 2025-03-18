#include "character.h"
#include "consts.h"

Character::Character(const sf::Vector2f& characterStartingPos, const sf::Font& font)
{
    characterShape = std::make_unique<sf::RectangleShape>(sf::Vector2f(defaultCharacterSize, defaultCharacterSize));
    characterShape->setPosition(characterStartingPos);
    characterShape->setFillColor(sf::Color::Blue);
    characterPos = characterStartingPos;
    characterFont = font;
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*characterShape);
}

void Character::update(const sf::Time& deltaTime)
{
}

void Character::SetPosition(const sf::Vector2f &newPos)
{
    if (characterShape)
    {
        characterShape->setPosition(newPos);
    }
}

const sf::Vector2f &Character::GetPosition() const
{
    if (characterShape)
    {
        return characterShape->getPosition();
    }
    
    return sf::Vector2f(0.f, 0.f);
}
