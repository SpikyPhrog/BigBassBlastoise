#pragma once
#include "eventStructs.h"

#include "SFML/System/Time.hpp"
#include "SFML/System/Vector2.hpp"
constexpr float elementPadding                                  {20.f};
constexpr float enemyCharacterSize                              {50.f};
constexpr float playerCharacterSize                             {75.f};
constexpr float defaultCharacterSize                            {50.f};
constexpr float enemyMovementSpeed                              {10.f};
constexpr int textSize                                          {20};
constexpr int amountWaves                                       {5};
constexpr int enemiesSpawnedPerRound                            {7};
constexpr int enemyRewardDrop                                   {100};
constexpr int playerStartHealth                                 {3};
constexpr sf::Time timeBetweenWaves                             {sf::seconds(3.f)};

constexpr const char* fontFilePath                              {"assets/fonts/SalmonFont.otf"}; 
constexpr const char* musicFilePath                             {"assets/music/BMB.mp3"}; 
constexpr const char* dictionaryFilePath                        {"assets/dict/dictionary.txt"};
constexpr const char* configFilePath                            {"conf.cfg"};
constexpr const char* defaultConfigs                            {
                                                                "MasterVolume=.1f;\n"
                                                                "Name=Jeff;\n"
                                                                };

struct HBData
{
    sf::Vector2f size                                           {0.f, 0.f};
    sf::Vector2f position                                       {0.f, 0.f};
    sf::Vector2f padding                                        {0.f, 0.f};
};

struct VBData : HBData 
{
    bool bIsFullscreen                                          {false};
    bool bFullHeight                                            {false};
    bool bFullWidth                                             {false};
};

enum class EventTypes 
{
    UI_SCORE,
    UI_LIVES,
    UI_Slider,

    GS_GameOver,
    GS_Start,
};

enum class Configs
{
    MasterVolume,
    Name,
};