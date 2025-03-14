#include "pauseMenu.h"
#include "button.h"
#include "verticalBox.h"
#include "../gameManager.h"

PauseMenu::PauseMenu(const sf::Font & font, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    VBData settings;

    buttonsVB = std::make_shared<VerticalBox>(settings, window);
    resumeGameButton = std::make_shared<Button>(font, "Resume", window);
    optionsButton = std::make_shared<Button>(font, "Options", window);
    quitButton = std::make_shared<Button>(font, "Quit", window);

    resumeGameButton->OnClick = std::bind(&PauseMenu::OnResumeClicked, this);
    optionsButton->OnClick = std::bind(&PauseMenu::OnOptionsClicked, this);
    quitButton->OnClick = std::bind(&PauseMenu::OnQuitClicked, this);

    buttonsVB->AddWidget(resumeGameButton);
    buttonsVB->AddWidget(optionsButton);
    buttonsVB->AddWidget(quitButton);
}

void PauseMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    if (GameManager::GetGameState() != GameStates::Paused)
    {
        return;
    }
    
    if (buttonsVB)
    {
        target.draw(*buttonsVB);
    }
    
}

void PauseMenu::SetPosition(const sf::Vector2f & newPosition)
{
}

const sf::Vector2f & PauseMenu::GetPosition()
{
    if (buttonsVB)
    {
        return buttonsVB->GetPosition();
    }

    return sf::Vector2f(0.f, 0.f); 
}

const sf::Vector2f & PauseMenu::GetSize()
{
    if (buttonsVB)
    {
        return buttonsVB->GetSize();
    }
    
    return sf::Vector2f(0.f, 0.f);
}

void PauseMenu::update()
{
    if (buttonsVB)
    {
        buttonsVB->update();
    }
}

void PauseMenu::OnResumeClicked()
{
    GameManager::SetGameState(GameStates::Start);
}

void PauseMenu::OnOptionsClicked()
{
    GameManager::SetGameState(GameStates::Options);
}

void PauseMenu::OnQuitClicked()
{
    if (gameWindow)
    {
        gameWindow->close();
    }
}
