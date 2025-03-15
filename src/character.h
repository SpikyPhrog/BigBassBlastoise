#pragma once
#include "SFML/Graphics.hpp"
#include "stdafx.h"

class Character : public sf::Drawable
{
public:
    Character(const sf::Vector2f& characterSize, const sf::Vector2f& characterStartingPos, const sf::Font& font);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual void update(const sf::Time& deltaTime);

    void SetPosition(const sf::Vector2f& newPos);
    const sf::Vector2f& GetPosition() const;
    
protected:
    std::unique_ptr<sf::RectangleShape> characterShape;

    sf::Vector2f characterPos;
    sf::Font characterFont;
};