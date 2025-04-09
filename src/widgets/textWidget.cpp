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

    textWidgetSize = label.length() * 11;
    text->setOrigin(sf::Vector2f(0.f, 0.f));
}

void TextWidget::SetText(const std::string & inText)
{
    if (text)
    {
        text->setString(inText);
        textWidgetSize = inText.length() * 11;
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
        return sf::Vector2f(textWidgetSize , text->getCharacterSize());
    }
    return sf::Vector2f(0.f, 0.f);
}

void TextWidget::CenterOrigin()
{
    if (text)
    {
        text->setOrigin(sf::Vector2f(textWidgetSize/2, textWidgetSize/2));
    }
    
}
