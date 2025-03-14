#pragma once
#include <memory>
#include "SFML/Graphics/Font.hpp"
#include "SFML/Audio.hpp"


class AssetManager
{

public:
    AssetManager(char** argv);
  
    std::shared_ptr<sf::Font> gameFont {nullptr};
    std::shared_ptr<sf::Music> mainMusic {nullptr};
};
