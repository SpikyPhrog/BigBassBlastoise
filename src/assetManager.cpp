#include "assetManager.h"
#include "tools/cpp/runfiles/runfiles.h"
#include <iostream>
#include <fstream>
#include <windows.h>

std::string getPath()
{
    char buffer[_MAX_PATH];
    GetModuleFileName(NULL, buffer, _MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    return std::string(buffer).substr(0, pos); 
}

using bazel::tools::cpp::runfiles::Runfiles;

/// 
/// WHEN ADDING A NEW TYPE OF ASSET, MAKE SURE TO DEFINE IT IN THE BUILD FILE!!!!   
///

AssetManager::AssetManager(char** argv)
{
    std::string error;
    std::unique_ptr<Runfiles> runfiles(Runfiles::Create(argv[0], &error));

    std::string fontPath = getPath() + "\\assets/fonts/SalmonFont.otf";
    std::string musicPath = getPath() + "\\assets/music/BMB.mp3";
    std::string dictionaryPath = getPath() + "\\assets/dict/dictionary.txt";


    if (runfiles != nullptr)
    {
        fontPath = runfiles->Rlocation("__main__/src/" + fontPath); 
        musicPath = runfiles->Rlocation("__main__/src/" + musicPath);
        dictionaryPath = runfiles->Rlocation("__main__/src/" + dictionaryPath);
    }

    gameFont = std::make_shared<sf::Font>(fontPath);
    mainMusic = std::make_shared<sf::Music>(musicPath);

    LoadDictionary(dictionaryPath);

    mainMusic->setLooping(true);
}

void AssetManager::LoadDictionary(const std::string& path)
{
    std::string line;
    std::ifstream dictFile (path);

    assert(dictFile.is_open() != false);

    if (dictFile.is_open())
    {
        while (std::getline(dictFile, line))
        {
            // add files to collection
            dictionary.insert(line);
            dictionarySize++;
        }
        dictFile.close();
    }
}
