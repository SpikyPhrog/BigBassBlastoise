#pragma once
#include "baseWidget.h"
#include "button.h"
#include "verticalBox.h"

class MainMenu : public BaseWidget 
{
public:
    MainMenu(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void SetPosition(const sf::Vector2f& newPosition) override {};
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;

private: 
    void OnPlayClicked();
    void OnOptionsClicked();
    void OnQuitClicked();

private:
    std::shared_ptr<Button> playButton                          {nullptr};
    std::shared_ptr<Button> optionsButton                       {nullptr};
    std::shared_ptr<Button> quitButton                          {nullptr};
    std::shared_ptr<VerticalBox> buttonVB                       {nullptr};
};
