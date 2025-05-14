#include "uiManager.h"
#include "assetManager.h"
#include "widgets/mainMenu.h"
#include "widgets/pauseMenu.h"
#include "widgets/optionsMenu.h"
#include "widgets/gameOverWidget.h"
#include "widgets/playerHUDWidget.h"
#include "widgets/promptWidget.h"
#include "widgets/postWaveWidget.h"
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
    promptWidget->SetMessage("There are unsaved changes, do you want to save them?");
    postWaveWidget = std::make_unique<PostWaveWidget>(assetManager, window);
}

void UIManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!mainMenu || !pauseMenu || !optionsMenu || !gameOverWidget || !playerHUD || !promptWidget)
    {
        return;
    }
    
    switch (GameManager::GetGameState())
    {
    case GameStates::GS_Paused:
        target.draw(*pauseMenu);
        break;
    
    case GameStates::GS_MainMenu:
        target.draw(*mainMenu); 
        break;
    
    case GameStates::GS_Options:
        target.draw(*optionsMenu);
        break;

    case GameStates::GS_GameOver:
        target.draw(*gameOverWidget);
        break;

    case GameStates::GS_PostWaveComplete:
        target.draw(*postWaveWidget);
    
    case GameStates::GS_Start:
        target.draw(*playerHUD);
        break;
        
    case GameStates::GS_PromptSettings:
        target.draw(*promptWidget);
        break;
}
}

void UIManager::update()
{
    if (mainMenu && GameManager::GetGameState() == GameStates::GS_MainMenu)
    {
        mainMenu->update();
    }

    if (pauseMenu && GameManager::GetGameState() == GameStates::GS_Paused)
    {
        pauseMenu->update();
    }

    if (optionsMenu && GameManager::GetGameState() == GameStates::GS_Options)
    {
        optionsMenu->update();
    }
    
    if (gameOverWidget && GameManager::GetGameState() == GameStates::GS_GameOver)
    {
        gameOverWidget->update();
    }

    if (playerHUD && GameManager::GetGameState() == GameStates::GS_Start)
    {
        playerHUD->update();
    }
    
    if (promptWidget && GameManager::GetGameState() == GameStates::GS_PromptSettings)
    {
        promptWidget->update();
    }

    if (postWaveWidget && GameManager::GetGameState() == GameStates::GS_PostWaveComplete)
    {
        postWaveWidget->update();
    }
    
}
