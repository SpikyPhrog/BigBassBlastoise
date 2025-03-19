#include "assetManager.h"
#include "tools/cpp/runfiles/runfiles.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "consts.h"

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

    std::string fontPath = getPath() + "\\" + fontFilePath;
    std::string musicPath = getPath() + "\\" + musicFilePath;
    std::string dictionaryPath = getPath() + "\\" + dictionaryFilePath;


    if (runfiles != nullptr)
    {
        std::string runfilesPath = "__main__/src/";
        fontPath = runfiles->Rlocation(runfilesPath + fontFilePath); 
        musicPath = runfiles->Rlocation(runfilesPath + musicFilePath);
        dictionaryPath = runfiles->Rlocation(runfilesPath + dictionaryFilePath);
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
