#pragma once
#include "baseWidget.h"

class VerticalBox;
class Button;
class SettingSliderOptionWidget;
class AssetManager;

class OptionsMenu : public BaseWidget
{
public:
    OptionsMenu(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;

private:
    void OnClickedBack();

private:
    std::unique_ptr<VerticalBox> buttonVB                       {nullptr};
    std::shared_ptr<Button> backButton                          {nullptr};
    std::shared_ptr<SettingSliderOptionWidget> musicSliderOption{nullptr};
    std::shared_ptr<SettingSliderOptionWidget> testSliderOption {nullptr};
};