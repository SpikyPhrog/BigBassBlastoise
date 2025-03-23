#include "enemy.h"
#include <iostream>
#include "consts.h"

Enemy::Enemy(const sf::Vector2f& characterStartingPos, const sf::Font& font):
Character(characterStartingPos, font)
{
    characterShape->setSize(sf::Vector2f(enemyCharacterSize, enemyCharacterSize));
    characterShape->setFillColor(sf::Color::Blue);
    
    rewardDrop = enemyRewardDrop;

    for (size_t i = 0; i < 10; i++)
    {
        wordTextArray[i] = std::make_unique<sf::Text>(font, "", textSize);
    }
    
    lastWordCharPosition += characterPos.x;
}

void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    if (bIsCompleted)
    {
        return;
    }
    
    Character::draw(target, states);
    for (size_t i = 0; i < 10; i++)
    {
        target.draw(*wordTextArray[i]);
    }
}

void Enemy::update(const sf::Time& deltaTime)
{
    characterPos.x -= enemyMovementSpeed * 4 * deltaTime.asSeconds();
    characterShape->setPosition(characterPos);

    lastWordCharPosition = characterPos.x;
    for (size_t i = 0; i < wordSize; i++)
    {
        wordTextArray[i]->setPosition(sf::Vector2f(lastWordCharPosition, characterPos.y));
        lastWordCharPosition += 8;
    }
    
}

void Enemy::SetWord(const char* inWord)
{
    size_t i; 
    for (i = 0; i < 10; i++)
    {
        if (inWord[i] != '\0')
        {
            word[i] = inWord[i];
            wordTextArray[i]->setString(inWord[i]);
            wordTextArray[i]->setPosition(sf::Vector2(lastWordCharPosition, characterPos.y));
            lastWordCharPosition += 8;
        }
        else
        {
            break;
        }
    }

    wordSize = i;
    currentLetter = &word[0];
}

const std::string Enemy::GetWord()
{
    std::string characterWord;
    for (size_t i = 0; i < wordSize; i++)
    {
        characterWord += word[i];
    }

    return characterWord;
}

void Enemy::ProcessInput(const char& input)
{
    if (!bIsFocused)
    {
        return;
    }

    if (currentLetter[currentIndex] == input)
    {
        Knockback();
        wordTextArray[currentIndex]->setFillColor(sf::Color::Red);
        ++currentIndex;

        if (currentIndex == wordSize)
        {
            SetIsFocused(false);
            Kill();
        }
    }
}

void Enemy::SetIsFocused(bool isFocused)
{
    bIsFocused = isFocused;
}

void Enemy::Knockback()
{
    characterPos.x += 10;
    characterShape->setPosition(characterPos);
}

bool Enemy::CheckIfColliding(std::shared_ptr<sf::RectangleShape> rect)
{
    if (!rect)
    {
        return false;
    }

    if (characterShape->getPosition().x <= rect->getPosition().x + rect->getSize().x)
    {
        return true;
    }

    return false;
}

void Enemy::Kill()
{
    bIsCompleted = true;
    currentLetter = nullptr;
}
