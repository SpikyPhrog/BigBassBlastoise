#pragma once
#include "stdafx.h"

class StatManager
{
public:
    StatManager();

    int UpdateScoring(const int& modifier);
    int UpdateHealth(const int& modifier);
    void IncreaseErrors();
    void ResetErrors();
    
private:
    int lives                                                   {3};
    int score                                                   {0};
    int multiplier                                              {1};
    int errors                                                  {0};
};