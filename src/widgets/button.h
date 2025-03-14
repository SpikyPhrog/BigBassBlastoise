#pragma once
#include <functional>
#include "baseWidget.h"

class Button : public BaseWidget
{
public:
    Button(const sf::Font& inFont, const std::string& label, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update() override;
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void SetLabel(const std::string& label);
    void SetSize(const sf::Vector2f& newSize);

    const sf::Vector2f& GetSize() const {return buttonSize; }
    
    std::function<void()> OnClick;

protected:

private:
    sf::Font font;
    sf::RectangleShape buttonShape;
    sf::Vector2f buttonSize;
    std::unique_ptr<sf::Text> buttonText;
    sf::Color HoveredColor {sf::Color::Red};
    sf::Color NormalColor {sf::Color::Blue};
    sf::Color ClickedColor {sf::Color(10, 195, 230)};
    bool bTriggeredOnce {false};
};