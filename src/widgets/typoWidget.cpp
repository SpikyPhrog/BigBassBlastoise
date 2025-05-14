#include "../assetManager.h"
#include "typoWidget.h"
#include "textWidget.h"
#include "../system.h"

TypoWidget::TypoWidget(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    errorsMessage = std::make_shared<TextWidget>(*assetManager->gameFont, window);
}


void TypoWidget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{   
    if (errorsMessage)
    {
        target.draw(*errorsMessage);
    }
    
}

void TypoWidget::SetPosition(const sf::Vector2f & newPosition)
{
    if (errorsMessage)
    {
        errorsMessage->SetPosition(newPosition);
    }   
}

const sf::Vector2f & TypoWidget::GetPosition()
{
    if (errorsMessage)
    {
        return errorsMessage->GetPosition();
    }
    
    return sf::Vector2f(0.f, 0.f); 
}

const sf::Vector2f & TypoWidget::GetSize()
{    
    if (errorsMessage)
    {
        return errorsMessage->GetSize();
    }
    
    return sf::Vector2f(0.f, 0.f);
}

void TypoWidget::update()
{
}

void TypoWidget::Update(void* data)
{   
    // std::string errorsString = "Errors: " + std::to_string(System::Get()->statManager->GetErrors());
    // errorsMessage->SetText(errorsString);
}
