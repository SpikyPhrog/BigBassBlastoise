#include "bonusScoreWidget.h"
#include "textWidget.h"
#include "../assetManager.h"
#include "../system.h"
#include "../eventStructs.h"

BonusScoreWidget::BonusScoreWidget(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    bonusScoreMessage = std::make_shared<TextWidget>(*assetManager->gameFont, window);
}


void BonusScoreWidget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{   
    if (bonusScoreMessage)
    {
        target.draw(*bonusScoreMessage);
    }
}

void BonusScoreWidget::SetPosition(const sf::Vector2f & newPosition)
{
    if (bonusScoreMessage)
    {
        bonusScoreMessage->SetPosition(newPosition);
    }    
}

const sf::Vector2f & BonusScoreWidget::GetPosition()
{
    if (bonusScoreMessage)
    {
        return bonusScoreMessage->GetPosition();
    }
    
    return sf::Vector2f(0.f, 0.f); 
}

const sf::Vector2f & BonusScoreWidget::GetSize()
{   
    if (bonusScoreMessage)
    {
        return bonusScoreMessage->GetSize();
    }

    return sf::Vector2f(0.f, 0.f);
}

void BonusScoreWidget::update()
{
}

void BonusScoreWidget::Update(void* inData)
{
    UI_Data* data = nullptr;

    if (inData != NULL)
    {
        data = static_cast<UI_Data*>(inData);
    }
    
    if (data != nullptr)
    {
        std::string bonusScoreString = "Bonus score: " + std::to_string(data->data);
        bonusScoreMessage->SetText(bonusScoreString);
        
    }
}
