#pragma once
constexpr float elementPadding                                  {20.f};
constexpr float enemyCharacterSize                              {50.f};
constexpr float playerCharacterSize                             {75.f};
constexpr float defaultCharacterSize                            {50.f};
constexpr float enemyMovementSpeed                              {10.f};
constexpr int textSize                                          {20};
struct HBData
{
    sf::Vector2f size                                           {0.f, 0.f};
    sf::Vector2f position                                       {0.f, 0.f};
    sf::Vector2f padding                                        {0.f, 0.f};
};

struct VBData 
{
    sf::Vector2f size                                           {0.f, 0.f};
    sf::Vector2f position                                       {0.f, 0.f};
    sf::Vector2f padding                                        {0.f, 0.f};
    bool bIsFullscreen                                          {false};
    bool bFullHeight                                            {false};
    bool bFullWidth                                             {false};
};