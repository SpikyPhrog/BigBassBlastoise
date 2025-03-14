#include "uiManager.h"
#include "assetManager.h"
#include "widgets/mainMenu.h"
#include "widgets/pauseMenu.h"
#include "widgets/optionsMenu.h"
#include "gameManager.h"

UIManager::UIManager(const AssetManager& assetManager, std::shared_ptr<sf::RenderWindow> window)
{
    mainMenu = std::make_shared<MainMenu>(*assetManager.gameFont, window);
    pauseMenu = std::make_shared<PauseMenu>(*assetManager.gameFont, window);
    optionsMenu = std::make_shared<OptionsMenu>(assetManager, window);
}

void UIManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!mainMenu || !pauseMenu || !optionsMenu)
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
    
}
