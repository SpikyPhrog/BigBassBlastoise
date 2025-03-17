#include "enemySpawner.h"
#include <random>

EnemySpawner::EnemySpawner(const sf::Font& font, std::shared_ptr<Player> inPlayer)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,6);
    int counter = 97;

    player = inPlayer;

    std::string::iterator it;
    for (int i = 0; i < 5; i++)
    {
        float x = 700 + (i * 10);
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(sf::Vector2f(50.f, 50.f), sf::Vector2f(x, i * 50), font);
        std::string testChar = "anana";
        char enemyChar = counter;
        counter ++;
        it = testChar.insert(testChar.begin(), enemyChar);
        enemy->SetWord(testChar.c_str());
        enemyList.emplace_back(enemy);
    }

    // switch the size to be screen height
    HitLine = std::make_shared<sf::RectangleShape>(sf::Vector2f{50.f, 600.f});
    HitLine->setPosition(sf::Vector2f{50.f, 0.f});
}

void EnemySpawner::update(const sf::Time & deltaTime)
{
    for (size_t i = 0; i < enemyList.size(); i++)
    {
        enemyList[i]->update(deltaTime);
        
        if (enemyList[i]->CheckIfColliding(HitLine))
        {
            DamagePlayer(enemyList[i]);    
        }
    }
}

void EnemySpawner::ProcessInput(const char & input)
{
    // To setup the currentEnemy we need to check if its null
    if (currentEnemy == nullptr)
    {
        for (size_t i = 0; i < enemyList.size(); i++)
        {
            if (enemyList[i]->GetCurrentLetter() != nullptr && input == *enemyList[i]->GetCurrentLetter())
            {
                enemyList[i]->SetIsFocused(true);
                currentEnemy = enemyList[i];
                currentEnemyIndex = i;
                currentEnemyPos.y = currentEnemy->GetPosition().y;
                break;       
            }
        }
    }
    
    // we must check if its not null, in case the top check has set it to something
    if (currentEnemy != nullptr)
    {    
        currentEnemy->ProcessInput(input);

        if (currentEnemy->GetIsCompleted())
        {
            DestroyEnemy();
            sf::Time time = clock.restart();
            timeForWord = time.asSeconds();
            
            // award player
            if (player)
            {
                player->UpdateScoring(timeForWord);
            }      
        }
    }
    
}

void EnemySpawner::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for (size_t i = 0; i < enemyList.size(); i++)
    {
        if (enemyList[i] == nullptr)
        {
            return;
        }
        enemyList[i]->draw(target, states);
    } 
}

void EnemySpawner::DamagePlayer(std::shared_ptr<Enemy> enemy)
{
    if(!player)
    {
        std::cout << "PlayerNotFound\n"; 
        return;
    }
    if (!enemy)
    {
        std::cout << "Enemy is null\n";
        return;
    }
    
    currentEnemy = enemy;

    DestroyEnemy();
    player->DecreaseLives();
}

void EnemySpawner::DestroyEnemy()
{
    currentEnemy->SetIsFocused(false);
    currentEnemy = nullptr;
    enemyList.erase(enemyList.begin() + currentEnemyIndex);
    currentEnemyIndex = 0;
}
