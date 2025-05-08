#pragma once

#include "baseWidget.h"
#include "../eventListener.h"

class AssetManager;
class TextWidget;

class AccuracyWidget : public BaseWidget, public EventListener
{
public:
    AccuracyWidget(std::shared_ptr<AssetManager>assetManager, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;
    void Update(void* inData) override;

private:
    std::shared_ptr<TextWidget> accuracyMessage;
};
