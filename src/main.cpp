#include "SFML/Graphics.hpp"
#include "gameManager.h"
#include "assetManager.h"
#include "uiManager.h"

int main(int argc, char** argv)
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode({800, 600}), "WEEEEEEEEEEEEEEEEEEEEEEE");
   
    AssetManager assetManager(argv);

    // assetManager.mainMusic->play();

    std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>(assetManager, window);
    std::unique_ptr<UIManager> uiManager = std::make_unique<UIManager>(assetManager, window);

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
        
        window->draw(*uiManager);
        window->draw(*gameManager);

        window->display();
    }
}