#pragma once
#include "baseWidget.h"

class AssetManager;
class AccuracyWidget;
class TypoWidget;
class VerticalBox;

class PostWaveWidget: public BaseWidget
{
public:
    PostWaveWidget(std::shared_ptr<AssetManager> assetManager, std::shared_ptr<sf::RenderWindow> window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;

private:
    std::unique_ptr<VerticalBox> vbMessages;
    std::shared_ptr<AccuracyWidget> accuracyWidget;
    std::shared_ptr<TypoWidget> errorsWidget;
};