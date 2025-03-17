#pragma once
#include <memory>
#include "SFML/Graphics/Font.hpp"
#include "SFML/Audio.hpp"
#include <unordered_set>

class AssetManager
{

public:
    AssetManager(char** argv);
    /// Decide on whether to use set or vector for the dictoionary
    // define the dictionary
  
    std::shared_ptr<sf::Font> gameFont                          {nullptr};
    std::shared_ptr<sf::Music> mainMusic                        {nullptr};
    std::unordered_set<std::string> dictionary                  {};
    const int& GetDictionarySize() const                        {return dictionarySize;}

private:
    int dictionarySize                                          {0};
    void LoadDictionary(const std::string& path);
};
