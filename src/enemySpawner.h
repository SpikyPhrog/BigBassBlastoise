#pragma once
#include "stdafx.h"
#include "enemy.h" // Has SFML/Graphics.hpp -> Drawable.hpp#
#include "player.h"
#include "assetManager.h"
#include "SFML/System/Time.hpp"


class EnemySpawner : public sf::Drawable
{
public:
    EnemySpawner(std::shared_ptr<AssetManager> inAssetManager, std::shared_ptr<sf::RenderWindow> inWindow, std::shared_ptr<Player> inPlayer);

    void update(const sf::Time& deltaTime);
    void ProcessInput(const char& input);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    const sf::Vector2f& GetEnemyPos() { return currentEnemyPos; }

    void Reset();
    void Start();
    
private:
    void DamagePlayer(std::shared_ptr<Enemy> enemy);
    void DestroyEnemy();
    char ReverseInputCapitolisation(const char& input);

    void SpawnWave();

private:
    std::vector<std::shared_ptr<Enemy>> enemyList               {};
    std::shared_ptr<Enemy> currentEnemy                         {nullptr};
    std::shared_ptr<sf::RectangleShape> HitLine                 {nullptr};
    std::shared_ptr<Player> player                              {nullptr};
    std::shared_ptr<AssetManager> assetManager                  {nullptr};
    std::shared_ptr<sf::RenderWindow> window                    {nullptr};
    int currentEnemyIndex                                       {0};
    int enemiesDefeated                                         {0};
    sf::Vector2f currentEnemyPos                                {0.f, 0.f};
    float score                                                 {0};
    // To calculate the elapsed time from the start of the word to the end of it
    float timeForWord                                           {0.f};
    sf::Clock clock;
};