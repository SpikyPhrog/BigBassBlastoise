#pragma once
#include "baseWidget.h"
#include "widgetConsts.h"



class VerticalBox : public BaseWidget
{
public:
    VerticalBox(const VBData& settings, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;
    void AddWidget(std::shared_ptr<BaseWidget> widgetToAdd);
    
private:    
    std::vector<std::shared_ptr<BaseWidget>> children {}; 
    std::unique_ptr<sf::RectangleShape> vbShape {nullptr};
    sf::Vector2f lastChildPosition;
    VBData vbSettings;
};