#include "assetManager.h"
#include "tools/cpp/runfiles/runfiles.h"
#include <iostream>

using bazel::tools::cpp::runfiles::Runfiles;

/// 
/// WHEN ADDING A NEW TYPE OF ASSET, MAKE SURE TO DEFINE IT IN THE BUILD FILE!!!!   
///

AssetManager::AssetManager(char** argv)
{
    std::string error;
    std::unique_ptr<Runfiles> runfiles(Runfiles::Create(argv[0], &error));

    std::string fontPath = "assets/fonts/SalmonFont.otf";
    std::string musicPath = "assets/music/BMB.mp3";

    if (runfiles != nullptr)
    {
        fontPath = runfiles->Rlocation("__main__/src/" + fontPath); 
        musicPath = runfiles->Rlocation("__main__/src/" + musicPath);
    }

    gameFont = std::make_shared<sf::Font>(fontPath);
    mainMusic = std::make_shared<sf::Music>(musicPath);

    mainMusic->setLooping(true);
}
