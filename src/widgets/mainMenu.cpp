#include "mainMenu.h"
#include "../gameManager.h"
#include "../system.h"

MainMenu::MainMenu(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window): 
BaseWidget(window)
{     
    VBData data;
    data.position = sf::Vector2f{300.f, 0.f};

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
    GameManager::SetGameState(GameStates::Start);
    
    UI_Data data;
    data.data = 3;

    void* dataPtr = &data;

    System::Get()->BroadcastEvent(EventTypes::UI_LIVES, dataPtr);
    System::Get()->BroadcastEvent(EventTypes::GS_Start, NULL);

    dataPtr = nullptr;
}

void MainMenu::OnOptionsClicked()
{
    GameManager::SetGameState(GameStates::Options);
}

void MainMenu::OnQuitClicked()
{
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
