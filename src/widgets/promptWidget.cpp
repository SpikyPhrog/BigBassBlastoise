#include "promptWidget.h"
#include "button.h"
#include "horizontalBox.h"
#include "textWidget.h"
#include "verticalBox.h"
#include "../assetManager.h"
#include "../system.h"
#include "../gameManager.h"
#include "../logger.h"

PromptWidget::PromptWidget(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    HBData data;
    data.size = sf::Vector2f(400.f, 50.f);
    data.position = sf::Vector2f(window->getSize().x / 2, 0);

    VBData vbData;
    vbData.size = sf::Vector2f(400.f, 400.f);
    vbData.position = sf::Vector2f(window->getSize().x / 2, 0);

    promptVB = std::make_unique<VerticalBox>(vbData, window);
    
    buttonHB = std::make_shared<HorizontalBox>(data, window);

    confirmButton = std::make_shared<Button>(*assetManager->gameFont, "Confirm" ,window);
    cancelButton = std::make_shared<Button>(*assetManager->gameFont,"Cancel", window);
    message = std::make_shared<TextWidget>(*assetManager->gameFont, window);
    
    confirmButton->OnClick = std::bind(&PromptWidget::OnConfirm, this);
    cancelButton->OnClick = std::bind(&PromptWidget::OnCancel, this);
    
    buttonHB->AddWidget(confirmButton);
    buttonHB->AddWidget(cancelButton);
    
    promptVB->AddWidget(message);
    promptVB->AddWidget(buttonHB);
}

void PromptWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*promptVB);
}

void PromptWidget::SetPosition(const sf::Vector2f &newPosition)
{

}

const sf::Vector2f &PromptWidget::GetPosition()
{
    if (buttonHB)
    {
        return promptVB->GetPosition();
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

void PromptWidget::SetMessage(const std::string &msg)
{
    message->SetText(msg);
}

void PromptWidget::OnConfirm()
{
    System::Get()->config->SaveChanges();
    
    GameManager::SetGameState(GameManager::GetPreviousGameState());
}

void PromptWidget::OnCancel()
{
    System::Get()->config->RevertChanges();
    
    GameManager::SetGameState(GameManager::GetPreviousGameState());
}
