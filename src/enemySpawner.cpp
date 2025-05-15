#include "enemySpawner.h"
#include <random>
#include "consts.h"
#include "system.h"
#include "gameManager.h"

// std::random_device dev;
// std::mt19937 rng(dev());

EnemySpawner::EnemySpawner(std::shared_ptr<AssetManager> inAssetManager, std::shared_ptr<sf::RenderWindow> inWindow, std::shared_ptr<Player> inPlayer)
{
    player = inPlayer;
    window = inWindow;
    assetManager = inAssetManager;
    enemyList.reserve(enemiesSpawnedPerRound);

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
        if (!bHasBroadcastedEvents)
        {
            BroadcastStatEvents();
        }
        
        GameManager::SetGameState(GameStates::GS_PostWaveComplete);

        // run timer
        if (clock.getElapsedTime() >= timeBetweenWaves)
        {
            GameManager::SetGameState(GameStates::GS_Start);
            enemiesDefeated = 0;
    
            // restart the wave
            SpawnWave();
            bHasBroadcastedEvents = false;
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
        bool check1 = currentEnemy->ProcessInput(input);
        bool check2 = false;

        if (!check1)
        {
            check2 = currentEnemy->ProcessInput(ReverseInputCapitolisation(input));
        }
        
        if (!check1 && !check2)
        {
            System::Get()->statManager->IncreaseErrors();
        }
        
        if (currentEnemy->GetIsCompleted())
        {
            UI_Data data;
            data.data = System::Get()->statManager->UpdateScoring(currentEnemy->GetRewardDrop());

            void* dataPtr = &data;

            System::Get()->BroadcastEvent(EventTypes::UI_SCORE, dataPtr);  
            DestroyEnemy();

            dataPtr = nullptr;
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
    assert(enemy != nullptr);
    
    currentEnemy = enemy;

    UI_Data data;
    data.data = System::Get()->statManager->UpdateHealth(-1);

    void* dataPtr = &data;

    System::Get()->BroadcastEvent(EventTypes::UI_LIVES, dataPtr);
    DestroyEnemy();

    dataPtr = nullptr;
}

void EnemySpawner::DestroyEnemy()
{
    if (enemyList.size() <= 0)
    {
        return;
    }
    currentEnemy->SetIsFocused(false);
    currentEnemy = nullptr;
    enemyList.erase(enemyList.begin() + currentEnemyIndex);
    currentEnemyIndex = 0;
    ++enemiesDefeated;
    clock.restart();
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
    for (int i = 0; i < enemiesSpawnedPerRound; i++)
    {
        std::unordered_set<std::string>::iterator it = assetManager->dictionary.begin();
        const float& StartX = window->getSize().x;
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(sf::Vector2f(StartX, i * 50), *assetManager->gameFont);
        int randomId = System::Get()->GetRandomNumber(1, assetManager->GetDictionarySize() - 1);

        std::advance(it, randomId);
        
        std::string randomWord = *it;
        
        enemy->SetWord(randomWord.c_str());
        enemyList.emplace_back(enemy);
        spawnedLettersCount += enemyList[i]->GetWordSize();
    }
}

void EnemySpawner::BroadcastStatEvents()
{    
    System::Get()->statManager->CalculateAccuracy(spawnedLettersCount);
    
    int acc = System::Get()->statManager->GetAccuracy();

    if (acc > 95)
    {
        UI_Data bonusScoreData;
        UI_Data scoreData;
        int bonusScore = acc * System::Get()->GetRandomNumber(10, 50);

        Logger::Log(LoggerLevel::DEBUG, "si", "Bonus score: ", bonusScore);

        bonusScoreData.data = bonusScore;
        scoreData.data = System::Get()->statManager->UpdateScoring(bonusScore);

        void* bonusDataPtr = &bonusScoreData;
        void* scoreDataPtr = &scoreData;

        System::Get()->BroadcastEvent(EventTypes::UI_BONUSSCORE, bonusDataPtr);  
        System::Get()->BroadcastEvent(EventTypes::UI_SCORE, scoreDataPtr);  

        bonusDataPtr = nullptr;
        scoreDataPtr = nullptr;
    }
    
    UI_Data accuracyData;
    accuracyData.data = acc;

    void* dataPtr = &accuracyData;
    System::Get()->statManager->ResetErrorCount();

    System::Get()->BroadcastEvent(EventTypes::UI_ACCURACY, dataPtr);

    dataPtr = nullptr;
    bHasBroadcastedEvents = true;
}

void EnemySpawner::Reset()
{
    currentEnemy->SetIsFocused(false);
    currentEnemy = nullptr;
    currentEnemyIndex = 0;
    enemiesDefeated = 0;
    enemyList.clear();

    UI_Data data;
    data.data = 0;

    void* dataPtr = &data;

    System::Get()->BroadcastEvent(EventTypes::UI_SCORE, dataPtr);  
    
    dataPtr = nullptr;
}

void EnemySpawner::Start()
{
    SpawnWave();
}
