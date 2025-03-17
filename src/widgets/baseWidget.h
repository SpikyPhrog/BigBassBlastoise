#pragma once
#include "../stdafx.h"
#include "SFML/Graphics.hpp"

class BaseWidget : public sf::Drawable
{
public: 
    BaseWidget(std::shared_ptr<sf::RenderWindow> window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    virtual void SetPosition(const sf::Vector2f& newPosition) = 0;
    virtual const sf::Vector2f& GetPosition() = 0;
    virtual const sf::Vector2f& GetSize() = 0;
    virtual void update() = 0;

    void SetIsActive(bool newState);
    bool GetIsActive() const                                    {return bIsActive;} 

protected:
    std::shared_ptr<sf::RenderWindow> gameWindow                {nullptr};

private:
    bool bIsActive                                              {false};
};