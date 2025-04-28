#include "horizontalBox.h"
#include "../logger.h"

HorizontalBox::HorizontalBox(const HBData& settings, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    hbShape = std::make_unique<sf::RectangleShape>(settings.size);
    hbSettings = settings;
    hbShape->setFillColor(sf::Color::Yellow);
    hbShape->setOutlineColor(sf::Color::Cyan);
    hbShape->setOutlineThickness(1.f);

    SetPosition(settings.position);
}

void HorizontalBox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    if (!hbShape)
    {
        return;
    }
    
    target.draw(*hbShape);

    if (children.size() > 0)
    {
        for (size_t i = 0; i < children.size(); i++)
        {
            target.draw(*children[i]);
        }
    }
}

void HorizontalBox::update()
{
    if (children.size() > 0)
    {
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->update();
        }   
    }
}

void HorizontalBox::SetPosition(const sf::Vector2f & newPosition)
{
    hbShape->setPosition(newPosition);
    SetChildrenPosition();
}

const sf::Vector2f& HorizontalBox::GetPosition()
{
    if (!hbShape)
    {
        Logger::Log(LoggerLevel::ERROR, "%s", "HB SHAPE IS NOT VALID!!!!!!");
        return sf::Vector2f(0.f, 0.f);
    }
    return hbShape->getPosition();
}

const sf::Vector2f & HorizontalBox::GetSize()
{
    
    if (!hbShape)
    {
        return sf::Vector2f(0.f, 0.f);
    }
    
    return hbShape->getSize();
}

void HorizontalBox::AddWidget(std::shared_ptr<BaseWidget> widgetToAdd)
{
    float widgetSize = widgetToAdd->GetSize().x;
    lastChildPosition.x += widgetSize;
    
    widgetToAdd->SetPosition(lastChildPosition);
    children.emplace_back(widgetToAdd);
}

void HorizontalBox::SetChildrenPosition()
{
    if (children.size() > 0)
    {
        sf::Vector2f lastElementPos {0.f, 0.f};
        float element_size = 0;
        
        for (auto child : children)
        {
            lastElementPos.y = hbShape->getPosition().y;
            lastElementPos.x = hbShape->getPosition().x + element_size + elementPadding;
            child->SetPosition(lastElementPos);
            element_size = child->GetSize().x;
        }   
    }
}
