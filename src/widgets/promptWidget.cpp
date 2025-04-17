#include "promptWidget.h"
#include "button.h"
#include "horizontalBox.h"
#include "textWidget.h"
#include "../assetManager.h"
#include "../eventManager.h"
#include "../gameManager.h"

PromptWidget::PromptWidget(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    HBData data;
    data.size = sf::Vector2f(400.f, 400.f);
    data.position = sf::Vector2f(window->getSize().x / 2, window->getSize().y);

    buttonHB = std::make_unique<HorizontalBox>(data, window);
    confirmButton = std::make_shared<Button>(*assetManager->gameFont, "Confirm" ,window);
    cancelButton = std::make_shared<Button>(*assetManager->gameFont,"Cancel", window);
    message = std::make_shared<TextWidget>(*assetManager->gameFont, window);

    confirmButton->OnClick = std::bind(&PromptWidget::OnConfirm, this);
    cancelButton->OnClick = std::bind(&PromptWidget::OnCancel, this);

    buttonHB->AddWidget(confirmButton);
    buttonHB->AddWidget(cancelButton);
}

void PromptWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*buttonHB);
    target.draw(*message);
}

void PromptWidget::SetPosition(const sf::Vector2f &newPosition)
{

}

const sf::Vector2f &PromptWidget::GetPosition()
{
    if (buttonHB)
    {
        return buttonHB->GetPosition();
    }
    
    return sf::Vector2f(0.f, 0.f);
}

const sf::Vector2f &PromptWidget::GetSize()
{
    if (buttonHB)
    {
        return buttonHB->GetSize();
    }
    
    return sf::Vector2f(0.f, 0.f);
}

void PromptWidget::update()
{
    if (buttonHB)
    {
        buttonHB->update();
    }
    
}

void PromptWidget::ClearState(bool &newState)
{
    newState = false;
}

void PromptWidget::OnConfirm()
{
    EventManager::GetInstance()->config->SaveChanges();
    
    GameManager::SetGameState(GameManager::GetPreviousGameState());
}

void PromptWidget::OnCancel()
{
    EventManager::GetInstance()->config->RevertChanges();
    
    GameManager::SetGameState(GameManager::GetPreviousGameState());
}
