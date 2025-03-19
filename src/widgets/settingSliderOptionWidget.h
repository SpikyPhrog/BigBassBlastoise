#pragma once
#include "baseWidget.h"
#include "horizontalBox.h"

class TextWidget;
class Slider;
class AssetManager;


class SettingSliderOptionWidget : public BaseWidget
{
public:
    SettingSliderOptionWidget(std::shared_ptr<AssetManager> assetManager, const std::string& inLabelText, const HBData& hbSettings, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update() override;
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    
private:
    HBData settings; 
    std::shared_ptr<Slider> slider                              {nullptr};
    std::shared_ptr<TextWidget> label                           {nullptr};
    std::unique_ptr<HorizontalBox> optionsHB                    {nullptr};
};