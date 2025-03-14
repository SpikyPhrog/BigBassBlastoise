#pragma once
#include "stdafx.h"
#include "enemy.h" // Has SFML/Graphics.hpp -> Drawable.hpp#
#include "player.h"
#include "SFML/System/Time.hpp"

class EnemySpawner : public sf::Drawable
{
public:
    EnemySpawner(const sf::Font& font, std::shared_ptr<Player> inPlayer);

    void update(const sf::Time& deltaTime);
    void ProcessInput(const char& input);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    const sf::Vector2f& GetEnemyPos() { return currentEnemyPos; }

private:
    void DamagePlayer(std::shared_ptr<Enemy> enemy);
    void DestroyEnemy();

private:
    std::vector<std::shared_ptr<Enemy>> enemyList{};
    std::shared_ptr<Enemy> currentEnemy;
    int currentEnemyIndex {0};
    sf::Vector2f currentEnemyPos {0.f, 0.f};
    
    // To calculate the elapsed time from the start of the word to the end of it
    float timeForWord {0.f};
    sf::Clock clock;
    std::shared_ptr<sf::RectangleShape> HitLine {nullptr};

    std::shared_ptr<Player> player {nullptr};
};