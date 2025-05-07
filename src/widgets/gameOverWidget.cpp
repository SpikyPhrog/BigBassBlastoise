#include "gameOverWidget.h"
#include "textWidget.h"
#include "button.h"
#include "verticalBox.h"
#include "../gameManager.h"

GameOverWidget::GameOverWidget(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    float windowSizeX = window->getSize().x;
    float windowSizeY = window->getSize().y;
    sf::Vector2f size {windowSizeX, windowSizeY};
    background = std::make_unique<sf::RectangleShape>(size);
    background->setFillColor(sf::Color::Magenta);

    gameOverText = std::make_shared<TextWidget>(font, "Game Over", window);

    goBackButton = std::make_shared<Button>(font, "Main Menu", window);
    goBackButton->OnClick = std::bind(&GameOverWidget::GoToMainMenu, this);

    VBData settings;
    settings.position = sf::Vector2f(windowSizeX/2, 0);

    verticalBox = std::make_unique<VerticalBox>(settings, window);
    verticalBox->AddWidget(gameOverText);
    verticalBox->AddWidget(goBackButton);
}

void GameOverWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    assert(background != nullptr);
    assert(gameOverText != nullptr);
    assert(goBackButton != nullptr);
    assert(verticalBox != nullptr);

    target.draw(*background);
    target.draw(*verticalBox);
}

void GameOverWidget::SetPosition(const sf::Vector2f &newPosition)
{
    if (verticalBox)
    {
        verticalBox->SetPosition(newPosition);
    }
    
}

const sf::Vector2f &GameOverWidget::GetPosition()
{
    if (background)
    {
        return background->getPosition();
    }
    return sf::Vector2f(0.f, 0.f);    
}

const sf::Vector2f &GameOverWidget::GetSize()
{
    if (background)
    {
        return background->getSize();
    }
    return sf::Vector2f(0.f, 0.f);
}

void GameOverWidget::update()
{
    if (goBackButton)
    {
        goBackButton->update();
    }   
}

void GameOverWidget::GoToMainMenu()
{
    GameManager::SetGameState(GameStates::GS_MainMenu);
}
