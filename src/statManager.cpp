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
        GameManager::SetGameState(GameStates::GameOver);
        System::Get()->BroadcastEvent(EventTypes::GS_GameOver, NULL);
        return 0;
    }
    
    return lives;
}
