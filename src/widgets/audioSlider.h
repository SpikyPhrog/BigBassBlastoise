#pragma once
#include "slider.h"
#include "SFML/Audio.hpp"

class AudioSlider : public Slider
{
public:
    AudioSlider(std::shared_ptr<sf::RenderWindow> window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        
    void SetPosition(const sf::Vector2f& newPosition) override;
    const sf::Vector2f& GetPosition() override;
    const sf::Vector2f& GetSize() override;
    void update() override; 
    void Update(void* inData) override;

    void SetMusic(std::shared_ptr<sf::Music> inMusic);

private:
    std::shared_ptr<sf::Music> music                            {nullptr};
};
