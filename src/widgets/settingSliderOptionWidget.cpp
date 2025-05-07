#include "settingSliderOptionWidget.h"
#include "textWidget.h"
#include "horizontalBox.h"
#include "audioSlider.h"
#include "../assetManager.h"
#include "../system.h"

SettingSliderOptionWidget::SettingSliderOptionWidget(std::shared_ptr<AssetManager> assetManager, const std::string& inLabelText, const HBData& hbSettings, std::shared_ptr<sf::RenderWindow> window, const Configs& config):
BaseWidget(window)
{
    label = std::make_shared<TextWidget>(*assetManager->gameFont, inLabelText, window);
    slider = std::make_shared<AudioSlider>(window);
    slider->SetSelf(slider);
    SetSliderName(inLabelText);

    System::Get()->AddEvent(EventTypes::UI_Slider, slider, config);

    SetSliderConfig(config);

    settings = hbSettings;

    optionsHB = std::make_unique<HorizontalBox>(hbSettings, window);
    optionsHB->AddWidget(label);
    optionsHB->AddWidget(slider);
}

void SettingSliderOptionWidget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    if (optionsHB)
    {
        target.draw(*optionsHB);
    }
}

void SettingSliderOptionWidget::update()
{
    optionsHB->update();
}

void SettingSliderOptionWidget::SetPosition(const sf::Vector2f & newPosition)
{
    optionsHB->SetPosition(newPosition);
}

const sf::Vector2f & SettingSliderOptionWidget::GetPosition()
{
    return settings.position;
}

const sf::Vector2f & SettingSliderOptionWidget::GetSize()
{
    return settings.size;
}

void SettingSliderOptionWidget::SetSliderValue(const float &inValue)
{
    if (!slider)
    {
        return;
    }
    
    slider->SetValue(inValue);
}

void SettingSliderOptionWidget::SetSliderAudio(std::shared_ptr<sf::Music> inAudio)
{
    if (!slider)
    {
        return;
    }
    slider->SetMusic(inAudio);
}

void SettingSliderOptionWidget::SetSliderName(const std::string &newName)
{
    if (!slider)
    {
        return;
    }
    slider->SetName(newName);
}

void SettingSliderOptionWidget::SetSliderConfig(const Configs &conf)
{
    if (!slider)
    {
        return;
    }

    slider->SetConfigSetting(conf);    
}
