#include "optionsMenu.h"
#include "verticalBox.h"
#include "button.h"
#include "settingSliderOptionWidget.h"
#include "horizontalBox.h"
#include "../assetManager.h"
#include "../gameManager.h"

OptionsMenu::OptionsMenu(std::shared_ptr<AssetManager> inAssetManager, std::shared_ptr<sf::RenderWindow> window): 
BaseWidget(window)
{
    VBData settings;
    settings.position = sf::Vector2f(350.f, 100.f);

    assetManager = inAssetManager;

    buttonVB = std::make_unique<VerticalBox>(settings, window);
    backButton = std::make_shared<Button>(*assetManager->gameFont, "Back", window);
    backButton->OnClick = std::bind(&OptionsMenu::OnClickedBack, this);

    HBData hbSettings;
    hbSettings.position = settings.position;
    hbSettings.size = sf::Vector2f(400.f, 75.f);

    musicSliderOption = std::make_shared<SettingSliderOptionWidget>(assetManager, "Master Volume", hbSettings, window);
    musicSliderOption->SetSliderAudio(assetManager->mainMusic);

    musicSliderOption->SetSliderValue(.6f);

    testSliderOption = std::make_shared<SettingSliderOptionWidget>(assetManager, "Test Slider Option", hbSettings, window);

    buttonVB->AddWidget(musicSliderOption);
    buttonVB->AddWidget(testSliderOption);
    buttonVB->AddWidget(backButton);
}

void OptionsMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    if (buttonVB)
    {
        target.draw(*buttonVB);
    }
}

void OptionsMenu::SetPosition(const sf::Vector2f & newPosition)
{
}

const sf::Vector2f & OptionsMenu::GetPosition()
{
// TODO: insert return statement here
    return sf::Vector2f(0.f, 0.f);
}

const sf::Vector2f & OptionsMenu::GetSize()
{
// TODO: insert return statement here
    return sf::Vector2f(0.f, 0.f);
}

void OptionsMenu::update()
{
    if (buttonVB)
    {
        buttonVB->update();
    }
}

void OptionsMenu::OnClickedBack()
{
    GameManager::SetGameState(GameManager::GetPreviousGameState());
}

void OptionsMenu::OnVolumeSliderUpdate(const float &inValue)
{
    assert(assetManager != nullptr);
    assert(assetManager->mainMusic != nullptr);
    
    float newVal = 0;
    newVal = inValue * 100.f;
    printf("Setting the volume to %f\n", newVal);
    assetManager->mainMusic->setVolume(newVal);
}
