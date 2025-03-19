#include "enemySpawner.h"
#include <random>
#include "consts.h"

std::random_device dev;
std::mt19937 rng(dev());

EnemySpawner::EnemySpawner(std::shared_ptr<AssetManager> inAssetManager, std::shared_ptr<sf::RenderWindow> inWindow, std::shared_ptr<Player> inPlayer)
{
    player = inPlayer;
    window = inWindow;
    assetManager = inAssetManager;
    enemyList.reserve(enemiesSpawnedPerRound);

    SpawnWave();

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

    if(enemiesDefeated >= enemiesSpawnedPerRound)
    {
        // run timer
        if (clock.getElapsedTime() >= timeBetweenWaves)
        {
            enemiesDefeated = 0;
    
            // restart the wave
            SpawnWave();
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
            if (enemyList[i]->GetCurrentLetter() != nullptr && (input == *enemyList[i]->GetCurrentLetter() || ReverseInputCapitolisation(input) == *enemyList[i]->GetCurrentLetter()))
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
        currentEnemy->ProcessInput(ReverseInputCapitolisation(input));

        if (currentEnemy->GetIsCompleted())
        {
            DestroyEnemy();
            
            // award player
            if (player)
            {
                player->UpdateScoring(score);
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
    assert(player != nullptr);
    assert(enemy != nullptr);
    
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
    ++enemiesDefeated;
    clock.reset();
}

char EnemySpawner::ReverseInputCapitolisation(const char &input)
{
    char reverseInput = 0;
    // check if its a capital letter
    if (input >= 65 && input <= 90)
    {
        reverseInput = input + 32;
    }
    
    // check if its a lowercase letter
    if (input >= 97 && input <= 122)
    {
        reverseInput = input - 32;
    }
    
    return reverseInput;
}

void EnemySpawner::SpawnWave()
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, assetManager->GetDictionarySize());
    std::unordered_set<std::string>::iterator it = assetManager->dictionary.begin();

    for (int i = 0; i < enemiesSpawnedPerRound; i++)
    {
        const float& StartX = window->getSize().x;
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(sf::Vector2f(StartX, i * 50), *assetManager->gameFont);
        int randomId = dist(rng);

        std::advance(it, randomId);

        std::string randomWord = *it;
        enemy->SetWord(randomWord.c_str());
        enemyList.emplace_back(enemy);
    }
}
