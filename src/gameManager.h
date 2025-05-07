#pragma once
#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "player.h"
#include "enemy.h"
#include "enemySpawner.h"
#include "eventListener.h"
#include "gameStates.h"

class AssetManager;

class GameManager : public sf::Drawable, public EventListener
{

public:
    GameManager(std::shared_ptr<AssetManager> inAssetManager, std::shared_ptr<sf::RenderWindow> inWindow);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void inputUpdate(const sf::Event::TextEntered* input);
    void update(const sf::Time& deltaTime);

    // static void StartGame();
    static const GameStates& GetGameState();
    static const GameStates& GetPreviousGameState();
    static void SetGameState(const GameStates& newState);
    static void SetGameStateToPrompt();

    void Update(void* inData) override;

private:
    std::shared_ptr<EnemySpawner> enemySpawner                  {nullptr};
    std::shared_ptr<Player> playerChar                          {nullptr};

    static GameStates gameState;
    static GameStates previousGameState;
};