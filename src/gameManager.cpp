#include "gameManager.h"
#include "enemySpawner.h"
#include "assetManager.h"

GameStates GameManager::gameState = GameStates::MainMenu;
GameStates GameManager::previousGameState = GameStates::MainMenu;

GameManager::GameManager(std::shared_ptr<AssetManager> inAssetManager, std::shared_ptr<sf::RenderWindow> inWindow)
{
    float windowWidth = inWindow->getSize().x;
    float windowHeight = inWindow->getSize().y;

    sf::Vector2f playerStartPos {0.f, windowHeight/2};
    
    playerChar = std::make_shared<Player>(playerStartPos, *inAssetManager->gameFont);
    enemySpawner = std::make_unique<EnemySpawner>(inAssetManager, inWindow, playerChar);
    gameState = GameStates::MainMenu;
}

void GameManager::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    if (gameState == GameStates::Start)
    {
        target.draw(*enemySpawner);
        target.draw(*playerChar);
    }
}

void GameManager::inputUpdate(const sf::Event::TextEntered* input)
{
    // checking the lower letter would be:
    // if(input->unicode < 90)
    // char += 32 => would return lowercase letter
    if (!input || gameState != GameStates::Start)
    {
        return;
    }
    
    if (input->unicode == 27)
    {
        gameState = GameStates::Paused;
    }
    

    if(input->unicode < 128)
    {
        enemySpawner->ProcessInput(input->unicode);
    }
}

void GameManager::update(const sf::Time &deltaTime)
{
    if (gameState == GameStates::Start && gameState != GameStates::GameOver)
    {
        playerChar->SetPosition(enemySpawner->GetEnemyPos());
        enemySpawner->update(deltaTime);
    }   
}

// void GameManager::StartGame()
// {
//     gameState = GameStates::Start;
// }

const GameStates& GameManager::GetGameState()
{
    return gameState;
}

const GameStates& GameManager::GetPreviousGameState()
{
    return previousGameState;
}

void GameManager::SetGameState(const GameStates & newState)
{
    GameStates tempPrevState = gameState;

    gameState = newState;

    previousGameState = tempPrevState;
}