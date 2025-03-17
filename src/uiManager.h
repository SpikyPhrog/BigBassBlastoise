#pragma once
#include "SFML/Graphics.hpp"

class AssetManager;
class MainMenu;
class PauseMenu;
class OptionsMenu;

class UIManager : public sf::Drawable
{
public:
    UIManager(const AssetManager& assetManager, std::shared_ptr<sf::RenderWindow> window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();

private:
    std::shared_ptr<MainMenu> mainMenu                          {nullptr};
    std::shared_ptr<PauseMenu> pauseMenu                        {nullptr};
    std::shared_ptr<OptionsMenu> optionsMenu                    {nullptr};
};