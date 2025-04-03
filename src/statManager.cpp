#include "statManager.h"
#include "gameManager.h"
#include "eventManager.h"
#include "consts.h"

int StatManager::lives = 3;
int StatManager::score = 0;

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
        GameManager::SetGameState(GameStates::GameOver);
        EventManager::GetInstance()->Broadcast(EventTypes::GS_GameOver, NULL);
        return 0;
    }
    
    return lives;
}
