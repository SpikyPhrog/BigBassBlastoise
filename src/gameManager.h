#pragma once
#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "player.h"
#include "enemy.h"
#include "enemySpawner.h"

class AssetManager;

enum class GameStates
{
    MainMenu,
    Options,
    Start,
    Paused,
    GameOver
};

class GameManager : public sf::Drawable
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
private:
    std::unique_ptr<EnemySpawner> enemySpawner                  { nullptr };
    std::shared_ptr<Player> playerChar                          { nullptr };

    static GameStates gameState;
    static GameStates previousGameState;
};