#include "settingSliderOptionWidget.h"
#include "textWidget.h"
#include "horizontalBox.h"
#include "slider.h"
#include "../assetManager.h"

SettingSliderOptionWidget::SettingSliderOptionWidget(std::shared_ptr<AssetManager> assetManager, const std::string& inLabelText, const HBData& hbSettings, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    label = std::make_shared<TextWidget>(*assetManager->gameFont, inLabelText, window);
    slider = std::make_shared<Slider>(window);

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