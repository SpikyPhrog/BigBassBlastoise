#pragma once
#include "baseWidget.h"
#include "../consts.h"

class HorizontalBox : public BaseWidget
{
public:
    HorizontalBox(const HBData& settings, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update() override;
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;

    void AddWidget(std::shared_ptr<BaseWidget> widgetToAdd);

private:
    std::vector<std::shared_ptr<BaseWidget>> children           {}; 
    std::unique_ptr<sf::RectangleShape> hbShape                 {nullptr};
    sf::Vector2f lastChildPosition                              {0.f, 0.f};
    HBData hbSettings                                           {};
};
