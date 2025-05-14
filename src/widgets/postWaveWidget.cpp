#include "postWaveWidget.h"
#include "verticalBox.h"
#include "../assetManager.h"
#include "../system.h"
#include "../gameManager.h"
#include "../logger.h"
#include "accuracyWidget.h"
#include "typoWidget.h"


PostWaveWidget::PostWaveWidget(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    VBData settings;
    settings.size = sf::Vector2f(300.f, 300.f);
    settings.padding = sf::Vector2f(50.f, 50.f);
    settings.position = sf::Vector2f(400.f, 100.f);
    
    vbMessages = std::make_unique<VerticalBox>(settings, window);

    accuracyWidget = std::make_shared<AccuracyWidget>(assetManager, window);
    errorsWidget = std::make_shared<TypoWidget>(assetManager, window);

    vbMessages->AddWidget(accuracyWidget);
    vbMessages->AddWidget(errorsWidget);

    System::Get()->AddEvent(EventTypes::UI_ACCURACY, accuracyWidget);
    System::Get()->AddEvent(EventTypes::UI_ERRORS, errorsWidget);
}


void PostWaveWidget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{   
    if (GameManager::GetGameState() != GameStates::GS_PostWaveComplete)
    {
        return;
    }
    
    if (vbMessages)
    {
        target.draw(*vbMessages);
    }
}

void PostWaveWidget::SetPosition(const sf::Vector2f & newPosition)
{
}

const sf::Vector2f & PostWaveWidget::GetPosition()
{
    return sf::Vector2f(0.f, 0.f); 
}

const sf::Vector2f & PostWaveWidget::GetSize()
{    
    return sf::Vector2f(0.f, 0.f);
}

void PostWaveWidget::update()
{
}
