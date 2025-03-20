#include "verticalBox.h"

VerticalBox::VerticalBox(const VBData& settings, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    vbShape = std::make_unique<sf::RectangleShape>(settings.size);
    vbSettings = settings;
    SetPosition(settings.position);
    
    if (settings.bFullHeight)
    {
        float windowSizeY = window->getSize().y;
        vbShape->setSize(sf::Vector2f{settings.size.x, windowSizeY});
        SetPosition(sf::Vector2f{settings.position.x, 0});
    }
}

void VerticalBox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    assert(vbShape != nullptr);

    target.draw(*vbShape);

    if (children.size() > 0)
    {
        for (size_t i = 0; i < children.size(); i++)
        {
            assert(children[i] != nullptr);
            target.draw(*children[i]);
        }
    }
}

void VerticalBox::SetPosition(const sf::Vector2f &newPosition)
{
    assert(vbShape != nullptr);
    vbShape->setPosition(newPosition);
    
    SetChildrenPosition();
}

const sf::Vector2f &VerticalBox::GetPosition()
{
    return vbShape->getPosition();
}

void VerticalBox::update()
{
    if (children.size() > 0)
    {
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->update();
        }   
    }
}

void VerticalBox::AddWidget(std::shared_ptr<BaseWidget> widgetToAdd)
{
    children.emplace_back(widgetToAdd);
    SetChildrenPosition();
}

const sf::Vector2f &VerticalBox::GetSize()
{
    return vbShape->getSize();
}

void VerticalBox::SetChildrenPosition()
{
    if (children.size() > 0)
    {
        sf::Vector2f lastElementPos {0.f, 0.f};
        float lastChildPosY = 0;
        float element_size = 0;

        for (auto child : children)
        {
            assert(child != nullptr);
            lastElementPos.x = vbShape->getPosition().x - child->GetSize().x / 2;
            lastElementPos.y = vbShape->getPosition().y + lastChildPosY + element_size + elementPadding;
            child->SetPosition(lastElementPos);
            lastChildPosY = lastElementPos.y;
            element_size = child->GetSize().y;
        }  
    }
}
