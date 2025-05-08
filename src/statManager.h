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
    const int& GetErrors() const;
    const int& GetAccuracy() const;

    void CalculateAccuracy();

private:
    int lives                                                   {3};
    int score                                                   {0};
    int multiplier                                              {1};
    int errors                                                  {0};
    int accuracy                                                {0};
};