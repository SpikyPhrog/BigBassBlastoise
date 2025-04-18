#include "optionsMenu.h"
#include "verticalBox.h"
#include "button.h"
#include "settingSliderOptionWidget.h"
#include "horizontalBox.h"
#include "../assetManager.h"
#include "../gameManager.h"
#include "../eventManager.h"

OptionsMenu::OptionsMenu(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window): 
BaseWidget(window)
{
    VBData settings;
    settings.position = sf::Vector2f(350.f, 100.f);

    buttonVB = std::make_unique<VerticalBox>(settings, window);
    backButton = std::make_shared<Button>(*assetManager->gameFont, "Back", window);
    backButton->OnClick = std::bind(&OptionsMenu::OnClickedBack, this);

    HBData hbSettings;
    hbSettings.position = settings.position;
    hbSettings.size = sf::Vector2f(400.f, 75.f);

    musicSliderOption = std::make_shared<SettingSliderOptionWidget>(assetManager, "Master Volume", hbSettings, window);
    musicSliderOption->SetSliderConfig(Configs::MasterVolume);
    musicSliderOption->SetSliderAudio(assetManager->mainMusic);

    std::string masterVolumeValue = EventManager::GetInstance()->config->GetConfig(Configs::MasterVolume);
    musicSliderOption->SetSliderValue(std::stof(masterVolumeValue));

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
    return sf::Vector2f(0.f, 0.f);
}

const sf::Vector2f & OptionsMenu::GetSize()
{
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
    // Check for unsaved changes
    if(EventManager::GetInstance()->config->GetAnyChangesMade())
    {
        GameManager::SetGameStateToPrompt();
    }
}