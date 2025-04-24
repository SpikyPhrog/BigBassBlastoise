#include "playerHUDWidget.h"
#include "../statManager.h"
#include "../consts.h"
#include "playerScoreWidget.h"
#include "playerHealthWidget.h"
#include "../system.h"

PlayerHUD::PlayerHUD(const sf::Font &font, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    scoreWidget = std::make_shared<PlayerScoreWidget>(font, window);
    healthWidget = std::make_shared<PlayerHealthWidget>(font, window);

    System::Get()->AddEvent(EventTypes::UI_SCORE, scoreWidget);
    System::Get()->AddEvent(EventTypes::UI_LIVES, healthWidget);
}

void PlayerHUD::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    assert(scoreWidget != nullptr);
    assert(healthWidget != nullptr);

    target.draw(*scoreWidget);
    target.draw(*healthWidget);
}

void PlayerHUD::SetPosition(const sf::Vector2f &newPosition)
{
}

const sf::Vector2f& PlayerHUD::GetPosition()
{
    return sf::Vector2f(0.f, 0.f);
}

const sf::Vector2f& PlayerHUD::GetSize()
{
    return sf::Vector2f(0.f, 0.f);
}

void PlayerHUD::update()
{

}