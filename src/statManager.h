#pragma once
#include "stdafx.h"

class StatManager
{
public:
    StatManager();

    static int UpdateScoring(const int& modifier);
    static int UpdateHealth(const int& modifier);

private:
    static int lives;
    static int score;
    int multiplier                                              {1};
};