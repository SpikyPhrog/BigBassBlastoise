#include "statManager.h"
#include "gameManager.h"
#include "consts.h"
#include "system.h"


StatManager::StatManager()
{
}

int StatManager::UpdateScoring(const int& modifier)
{
    //multiplier + (timeFinishedWord - timeStartedWord) 
    score += modifier;
    return score;
}

int StatManager::UpdateHealth(const int &modifier)
{
    lives += modifier;

    if (lives <= 0)
    {
        GameManager::SetGameState(GameStates::GS_GameOver);
        System::Get()->BroadcastEvent(EventTypes::GSE_GameOver, NULL);
        return 0;
    }
    
    return lives;
}

void StatManager::IncreaseErrors()
{
    errors++;
}

void StatManager::ResetErrorCount()
{
    errors = 0;
}

const float &StatManager::GetErrorCount() const
{
    return errors;
}

const float &StatManager::GetAccuracy() const
{
    return accuracy;
}

void StatManager::CalculateAccuracy(const float& lettersCount)
{
    accuracy = ((lettersCount - errors) / lettersCount) * 100;
}

const int &StatManager::GetLives() const
{
    return lives;
}

void StatManager::ResetStats()
{
    score = 0;
    errors = 0;
    accuracy = 0;
    lives = 3;
}
