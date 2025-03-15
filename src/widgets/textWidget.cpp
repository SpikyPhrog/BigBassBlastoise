#include "textWidget.h"

TextWidget::TextWidget(const sf::Font & font, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    text = std::make_unique<sf::Text>(font);
    text->setFillColor(sf::Color::Blue);
}

TextWidget::TextWidget(const sf::Font & font, const std::string & label, std::shared_ptr<sf::RenderWindow> window):
BaseWidget(window)
{
    text = std::make_unique<sf::Text>(font);
    text->setString(label);
    text->setFillColor(sf::Color::Blue);

    textSizeWidget = label.length() * 11;
    text->setOrigin(sf::Vector2f(0.f, 0.f));
}

void TextWidget::SetText(const std::string & inText)
{
    if (text)
    {
        text->setString(inText);
        textSizeWidget = inText.length() * 11;
    }
}

void TextWidget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    if (text)
    {
        target.draw(*text);
    }
}

void TextWidget::update()
{
}

void TextWidget::SetPosition(const sf::Vector2f & newPosition)
{
    assert(text != nullptr);
    // printf("Current text position: %f \t %f, new position; %f \t %f \n", text->getPosition().x, text->getPosition().y, newPosition.x, newPosition.y);
    text->setPosition(newPosition);
}

const sf::Vector2f& TextWidget::GetPosition()
{
    if (text)
    {
        return text->getPosition();
    }
    return sf::Vector2f(0.f, 0.f);
}

const sf::Vector2f& TextWidget::GetSize()
{
    if (text)
    {
        return sf::Vector2f(textSizeWidget , text->getCharacterSize());
    }
    return sf::Vector2f(0.f, 0.f);
}
