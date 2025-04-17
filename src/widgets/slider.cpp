#include "slider.h"
#include "../math.h"
#include "../eventManager.h"

Slider::Slider(std::shared_ptr<sf::RenderWindow> window):
MenuWidget(window)
{
    sliderLine = std::make_shared<sf::RectangleShape>(sf::Vector2f{120.f, 25.f});
    sliderKnob = std::make_shared<sf::CircleShape>(15);

    sliderKnob->setFillColor(sf::Color::Red);
    float knobRadius = sliderKnob->getRadius();
    sliderKnob->setOrigin(sf::Vector2f(knobRadius, knobRadius));
}

void Slider::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(*sliderLine);
    target.draw(*sliderKnob);
}

void Slider::SetPosition(const sf::Vector2f & newPosition)
{
    sliderLine->setPosition(newPosition);
    AlignKnobPosition();
    
    startPoint.x = sliderLine->getPosition().x;
    endPoint.x = sliderLine->getPosition().x + sliderLine->getSize().x;
}

const sf::Vector2f& Slider::GetPosition()
{
    return sf::Vector2f{0.f, 0.f};
}

const sf::Vector2f& Slider::GetSize()
{
    return sliderLine->getSize();
}

void Slider::update()
{
    // (MouseX - CircleX)^2 + (MouseY - CircleY)^2 < CircleRadius^2 => within the radius of the circle
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*gameWindow);
    sf::Vector2f knobPosition = sliderKnob->getPosition();

    float formula = Maths::Power<float>(mousePosition.x - knobPosition.x) + Maths::Power<float>(mousePosition.y - knobPosition.y);
    if (formula < Maths::Power<float>(sliderKnob->getRadius()))
    {
        sliderKnob->setFillColor(HoveredColor);
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            float result = value;
            sliderKnob->setFillColor(ClickedColor);
            result = Maths::Clamp((float)mousePosition.x, startPoint.x, endPoint.x);
            value = Maths::Normalise(result, startPoint.x, endPoint.x);
            // sliderKnob->setPosition(sf::Vector2f(result, knobPosition.y));
            SetValue(value);
        }
    }
    else
    {
        sliderKnob->setFillColor(NormalColor);
    }
}

const std::string &Slider::GetName()
{
    return name;
}

void Slider::SetName(const std::string &newName)
{
    name = newName;
}

void Slider::AlignKnobPosition()
{
    float knobPosY = sliderLine->getPosition().y + (sliderLine->getSize().y * .5f);
    float knobPosX = sliderLine->getPosition().x + sliderKnob->getRadius() * .5f;

    sliderKnob->setPosition(sf::Vector2f(knobPosX, knobPosY));
    SetValue(value);
}

void Slider::SetValue(const float &inValue)
{
    value = inValue;
    float knobPosY = sliderLine->getPosition().y + (sliderLine->getSize().y / 2);
    float knobPosX = (inValue * (endPoint.x - startPoint.x)) + startPoint.x;
    sliderKnob->setPosition(sf::Vector2f(knobPosX, knobPosY));

    UI_Slider_Data data;
    data.data = inValue;

    void* dataPtr = &data;

    EventManager::GetInstance()->Broadcast(EventTypes::UI_Slider, dataPtr, Get());

    dataPtr = nullptr;
}

const std::shared_ptr<Slider>& Slider::Get()
{
    return self;
}

void Slider::SetSelf(std::shared_ptr<Slider> newSelf)
{
    self = newSelf;
}

void Slider::SetConfigSetting(const Configs &newConf)
{
    configSetting = newConf;
}
