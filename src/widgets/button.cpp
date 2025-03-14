#include "button.h"

Button::Button(const sf::Font& inFont, const std::string& label, std::shared_ptr<sf::RenderWindow> window)
: BaseWidget(window)
{
    font = inFont;
    buttonText = std::make_unique<sf::Text>(font);
    buttonText->setString(label);
    buttonText->setCharacterSize(24);
    buttonText->setFillColor(sf::Color::Green);
    SetSize(sf::Vector2f(100.f, 50.f));
    buttonShape.setFillColor(NormalColor);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(buttonShape);
    target.draw(*buttonText);
}

void Button::update()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*gameWindow);

    if (mousePos.x > buttonShape.getPosition().x && 
        mousePos.x < buttonShape.getPosition().x + buttonSize.x &&
        mousePos.y < buttonShape.getPosition().y + buttonSize.y &&
        mousePos.y > buttonShape.getPosition().y)
    {
        buttonShape.setFillColor(HoveredColor);
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            buttonShape.setFillColor(ClickedColor);
            
            if (OnClick && !bTriggeredOnce)
            {
                OnClick();
                bTriggeredOnce = true;
            }
        }
        else
        {
            bTriggeredOnce = false;
        }
    }
    else
    {
        buttonShape.setFillColor(NormalColor);
    }
}

void Button::SetPosition(const sf::Vector2f& newPosition)
{
    buttonShape.setPosition(newPosition);
    buttonText->setPosition(newPosition);
}

const sf::Vector2f &Button::GetPosition()
{
    return buttonShape.getPosition();
}

const sf::Vector2f &Button::GetSize()
{
    return buttonShape.getSize();
}

void Button::SetLabel(const std::string& label)
{
    buttonText->setString(label);
}

void Button::SetSize(const sf::Vector2f& newSize)
{
    buttonSize = newSize;
    buttonShape.setSize(buttonSize);
}
