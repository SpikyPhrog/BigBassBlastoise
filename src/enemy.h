#pragma once
#include "stdafx.h"
#include "character.h"

class Enemy : public Character
{
public:
    Enemy(const sf::Vector2f& characterStartingPos, const sf::Font& font);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(const sf::Time& deltaTime) override;
    bool ProcessInput(const char& input);

    void SetWord(const char* inWord);
    const std::string GetWord();

    const int& GetWordSize() const;

    bool GetIsFocused() const { return bIsFocused; }
    void SetIsFocused(bool isFocused);
    bool GetIsCompleted() const { return bIsCompleted; }
    const char* GetCurrentLetter() const                        { return currentLetter; }
    const int& GetRewardDrop() const                            { return rewardDrop; }

    void Knockback();

    bool CheckIfColliding(std::shared_ptr<sf::RectangleShape> rect);

protected:
    void Kill();
    
private:
    std::unique_ptr<sf::Text> wordTextArray[10]                 {};
    float lastWordCharPosition                                  {0.f};
    size_t wordSize                                             {0};
    int currentIndex                                            {0};
    bool bIsCompleted                                           {false};
    bool bIsFocused                                             {false};
    char* currentLetter                                         {nullptr};
    char word[10]                                               {};
    int rewardDrop                                              {0};
};
