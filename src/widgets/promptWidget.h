#pragma once
#include "baseWidget.h"

class Button;
class HorizontalBox;
class VerticalBox;
class TextWidget;
class AssetManager;

class PromptWidget : public BaseWidget
{
public:
    PromptWidget(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override; 
    void update() override;
    
    void SetMessage(const std::string& msg);

private:
    void OnConfirm();
    void OnCancel();
    
private:    
    std::shared_ptr<HorizontalBox> buttonHB                     {nullptr};
    std::unique_ptr<VerticalBox> promptVB                       {nullptr};
    std::shared_ptr<Button> confirmButton                       {nullptr};
    std::shared_ptr<Button> cancelButton                        {nullptr};
    std::shared_ptr<TextWidget> message                         {nullptr};
};