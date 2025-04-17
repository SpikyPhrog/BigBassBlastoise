#pragma once
#include "SFML/Graphics.hpp"

class AssetManager;
class MainMenu;
class PauseMenu;
class OptionsMenu;
class GameOverWidget;
class PlayerHUD;
class PromptWidget;

class UIManager : public sf::Drawable
{
public:
    UIManager(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();

private:
    std::shared_ptr<MainMenu> mainMenu                          {nullptr};
    std::shared_ptr<PauseMenu> pauseMenu                        {nullptr};
    std::shared_ptr<OptionsMenu> optionsMenu                    {nullptr};
    std::shared_ptr<GameOverWidget> gameOverWidget              {nullptr};
    std::shared_ptr<PlayerHUD> playerHUD                        {nullptr};
    std::shared_ptr<PromptWidget> promptWidget                  {nullptr};
};