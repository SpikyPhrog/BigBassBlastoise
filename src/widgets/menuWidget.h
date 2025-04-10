#pragma once
#include "baseWidget.h"

class MenuWidget : public BaseWidget
{
public:
    MenuWidget(std::shared_ptr<sf::RenderWindow> window);

    bool CheckWidgetChange();
    
protected:
    bool bWasChanged                                            {false};
};
