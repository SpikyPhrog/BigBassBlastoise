#pragma once
#include "baseWidget.h"

class Button;
class HorizontalBox;
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
    void ClearState(bool& newState);
    
private:
    void OnConfirm();
    void OnCancel();
    
private:    
    std::unique_ptr<HorizontalBox> buttonHB                     {nullptr};
    std::shared_ptr<Button> confirmButton                       {nullptr};
    std::shared_ptr<Button> cancelButton                        {nullptr};
    std::shared_ptr<TextWidget> message                         {nullptr};
};