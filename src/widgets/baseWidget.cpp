#include "baseWidget.h"

BaseWidget::BaseWidget(std::shared_ptr<sf::RenderWindow> window)
{
    gameWindow = window;
}

void BaseWidget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}

void BaseWidget::SetIsActive(bool newState)
{
    bIsActive = newState;
}
