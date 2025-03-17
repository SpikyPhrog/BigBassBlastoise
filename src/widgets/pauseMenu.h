#pragma once
#include "baseWidget.h"

class Button;
class VerticalBox;

class PauseMenu : public BaseWidget
{
public:
    PauseMenu(const sf::Font& font, std::shared_ptr<sf::RenderWindow> window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override;

private:
    void OnResumeClicked();
    void OnOptionsClicked();
    void OnQuitClicked();

private:
    std::shared_ptr<VerticalBox> buttonsVB                      {nullptr};
    std::shared_ptr<Button> resumeGameButton                    {nullptr};
    std::shared_ptr<Button> optionsButton                       {nullptr};
    std::shared_ptr<Button> quitButton                          {nullptr};
};