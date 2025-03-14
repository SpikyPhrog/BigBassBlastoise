#include "mainMenu.h"
#include "../gameManager.h"

MainMenu::MainMenu(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window): 
BaseWidget(window)
{     
    VBData data;
    data.size = sf::Vector2f {400.f, 0.f};
    data.position = sf::Vector2f{300.f, 0.f};
    data.bFullHeight = true;

    buttonVB = std::make_shared<VerticalBox>(data, window);
    playButton = std::make_shared<Button>(font, "Play", window);
    optionsButton = std::make_shared<Button>(font, "Options", window);
    quitButton = std::make_shared<Button>(font, "Quit", window);

    playButton->OnClick = std::bind(&MainMenu::OnPlayClicked, this);
    optionsButton->OnClick = std::bind(&MainMenu::OnOptionsClicked, this);
    quitButton->OnClick = std::bind(&MainMenu::OnQuitClicked, this);

    buttonVB->AddWidget(playButton);
    buttonVB->AddWidget(optionsButton);
    buttonVB->AddWidget(quitButton);
}

void MainMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    if (GameManager::GetGameState() == GameStates::Start)
    {
        return;
    }
    
    if (buttonVB)
    {
        target.draw(*buttonVB);
    }
    
}

const sf::Vector2f & MainMenu::GetPosition()
{
    if (buttonVB)
    {
        return buttonVB->GetPosition();
    }
    
    return sf::Vector2f{0.f, 0.f};
}

void MainMenu::update()
{
    if (GameManager::GetGameState() == GameStates::Start)
    {
        return;
    }
    
    if (buttonVB)
    {
        buttonVB->update();
    }
    
}

void MainMenu::OnPlayClicked()
{
    std::cout << "Play Pressed\n";
    // GameManager::StartGame();
    GameManager::SetGameState(GameStates::Start);
}

void MainMenu::OnOptionsClicked()
{
    std::cout << "Options pressed\n";
    GameManager::SetGameState(GameStates::Options);
}

void MainMenu::OnQuitClicked()
{
    std::cout << "Quit Pressed\n";
    if (gameWindow)
    {
        gameWindow->close();
    }
    
}

const sf::Vector2f & MainMenu::GetSize()
{
    if (buttonVB)
    {
        return buttonVB->GetSize();
    }
    
    return sf::Vector2f(0.f, 0.f);
}
