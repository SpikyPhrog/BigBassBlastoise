#include "menuWidget.h"

MenuWidget::MenuWidget(std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{

}

bool MenuWidget::CheckWidgetChange()
{
    return bWasChanged;
}
