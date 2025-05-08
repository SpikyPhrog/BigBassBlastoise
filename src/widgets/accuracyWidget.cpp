#include "../assetManager.h"
#include "accuracyWidget.h"
#include "textWidget.h"
#include "../system.h"
#include "../eventStructs.h"
#include "../logger.h"

AccuracyWidget::AccuracyWidget(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    accuracyMessage = std::make_shared<TextWidget>(*assetManager->gameFont, window);
}


void AccuracyWidget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{   
    if (accuracyMessage)
    {
        target.draw(*accuracyMessage);
    }
}

void AccuracyWidget::SetPosition(const sf::Vector2f & newPosition)
{
    if (accuracyMessage)
    {
        accuracyMessage->SetPosition(newPosition);
    }    
}

const sf::Vector2f & AccuracyWidget::GetPosition()
{
    if (accuracyMessage)
    {
        return accuracyMessage->GetPosition();
    }
    
    return sf::Vector2f(0.f, 0.f); 
}

const sf::Vector2f & AccuracyWidget::GetSize()
{   
    if (accuracyMessage)
    {
        return accuracyMessage->GetSize();
    }

    return sf::Vector2f(0.f, 0.f);
}

void AccuracyWidget::update()
{
}

void AccuracyWidget::Update(void* inData)
{
    UI_Data* data = nullptr;

    if (inData != NULL)
    {
        data = static_cast<UI_Data*>(inData);
    }
    
    if (data != nullptr)
    {
        Logger::Log(LoggerLevel::DEBUG, "s", "Received an event??");
        std::string accuracyString = "Accuracy: " + std::to_string(data->data);
        accuracyMessage->SetText(accuracyString);
    }
}
