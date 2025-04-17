#include "uiManager.h"
#include "assetManager.h"
#include "widgets/mainMenu.h"
#include "widgets/pauseMenu.h"
#include "widgets/optionsMenu.h"
#include "widgets/gameOverWidget.h"
#include "widgets/playerHUDWidget.h"
#include "widgets/promptWidget.h"
#include "gameManager.h"
#include "eventManager.h"

UIManager::UIManager(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window)
{
    mainMenu = std::make_shared<MainMenu>(*assetManager->gameFont, window);
    pauseMenu = std::make_shared<PauseMenu>(*assetManager->gameFont, window);
    optionsMenu = std::make_shared<OptionsMenu>(assetManager, window);
    gameOverWidget = std::make_shared<GameOverWidget>(*assetManager->gameFont, window);
    playerHUD = std::make_shared<PlayerHUD>(*assetManager->gameFont, window);    
    promptWidget = std::make_unique<PromptWidget>(assetManager, window);
}

void UIManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!mainMenu || !pauseMenu || !optionsMenu || !gameOverWidget || !playerHUD || !promptWidget)
    {
        return;
    }
    
    switch (GameManager::GetGameState())
    {
    case GameStates::Paused:
        target.draw(*pauseMenu);
        break;
    
    case GameStates::MainMenu:
        target.draw(*mainMenu); 
        break;
    
    case GameStates::Options:
        target.draw(*optionsMenu);
        break;

    case GameStates::GameOver:
        target.draw(*gameOverWidget);
        break;

    case GameStates::Start:
        target.draw(*playerHUD);
        break;
    case GameStates::PromptSettings:
        target.draw(*promptWidget);
        break;
    }
}

void UIManager::update()
{
    if (mainMenu && GameManager::GetGameState() == GameStates::MainMenu)
    {
        mainMenu->update();
    }

    if (pauseMenu && GameManager::GetGameState() == GameStates::Paused)
    {
        pauseMenu->update();
    }

    if (optionsMenu && GameManager::GetGameState() == GameStates::Options)
    {
        optionsMenu->update();
    }
    
    if (gameOverWidget && GameManager::GetGameState() == GameStates::GameOver)
    {
        gameOverWidget->update();
    }

    if (playerHUD && GameManager::GetGameState() == GameStates::Start)
    {
        playerHUD->update();
    }
    
    if (promptWidget && GameManager::GetGameState() == GameStates::PromptSettings)
    {
        promptWidget->update();
    }
    
}
