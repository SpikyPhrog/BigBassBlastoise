#include "SFML/Graphics.hpp"
#include "gameManager.h"
#include "assetManager.h"
#include "uiManager.h"
#include "eventManager.h"

int main(int argc, char** argv)
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode({800, 600}), "WEEEEEEEEEEEEEEEEEEEEEEE");
   
    std::shared_ptr<AssetManager> assetManager = std::make_shared<AssetManager>(argv);

    assetManager->mainMusic->play();

    std::shared_ptr<EventManager> eventManager = std::make_shared<EventManager>();
    std::shared_ptr<GameManager> gameManager = std::make_shared<GameManager>(assetManager, window);
    std::unique_ptr<UIManager> uiManager = std::make_unique<UIManager>(assetManager, window);

    EventManager::GetInstance()->Add(EventTypes::GS_GameOver, gameManager);
    EventManager::GetInstance()->Add(EventTypes::GS_Start, gameManager);

    sf::Clock deltaClock;

    // run the program as long as the window is open
    while (window->isOpen()) 
    {
        sf::Time deltaTime = deltaClock.restart();
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window->pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window->close();
            
            gameManager->inputUpdate(event->getIf<sf::Event::TextEntered>());
        }

        gameManager->update(deltaTime);
        uiManager->update();
        
        window->clear(sf::Color::Black);
        
        window->draw(*gameManager);
        window->draw(*uiManager);

        window->display();
    }
}