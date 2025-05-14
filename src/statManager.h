#pragma once
#include "stdafx.h"

class StatManager
{
public:
    StatManager();

    int UpdateScoring(const int& modifier);
    int UpdateHealth(const int& modifier);
    
    void IncreaseErrors();
    void ResetErrorCount();
    const float& GetErrorCount() const;
    
    const int& GetLives() const;

    const float& GetAccuracy() const;

    void ResetStats();

    void CalculateAccuracy(const float& lettersCount);

private:
    int lives                                                   {3};
    int score                                                   {0};
    int multiplier                                              {1};
    float errors                                                {0};
    float accuracy                                              {0};
};