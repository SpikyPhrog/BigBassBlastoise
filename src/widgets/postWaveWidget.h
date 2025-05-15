#pragma once
#include "baseWidget.h"

class AssetManager;
class AccuracyWidget;
class BonusScoreWidget;
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
    std::unique_ptr<VerticalBox> vbMessages                     {nullptr};
    std::shared_ptr<AccuracyWidget> accuracyWidget              {nullptr};
    std::shared_ptr<BonusScoreWidget> bonusScoreMessage         {nullptr};
};