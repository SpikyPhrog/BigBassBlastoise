#pragma once
#include "baseWidget.h"

class TextWidget : public BaseWidget
{
public:
    TextWidget(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window);
    TextWidget(const sf::Font& font, const std::string& label, std::shared_ptr<sf::RenderWindow> window);

    void SetText(const std::string& inText);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update() override;
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;

    float textSizeWidget                                        {0.f};
private:
    std::unique_ptr<sf::Text> text                              {nullptr};
};