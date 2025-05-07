#include "audioSlider.h"
#include "../eventStructs.h"
#include "../system.h"
#include "../logger.h"

AudioSlider::AudioSlider(std::shared_ptr<sf::RenderWindow> window):
Slider(window)
{
}

void AudioSlider::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Slider::draw(target, states);
}

void AudioSlider::SetPosition(const sf::Vector2f &newPosition)
{
    Slider::SetPosition(newPosition);
}

const sf::Vector2f &AudioSlider::GetPosition()
{
    return Slider::GetPosition();
}

const sf::Vector2f &AudioSlider::GetSize()
{
    return Slider::GetSize();
}

void AudioSlider::update()
{
    Slider::update();
}

void AudioSlider::Update(void *inData)
{
    UI_Slider_Data* data = nullptr;
    if (inData != nullptr)
    {
        data = static_cast<UI_Slider_Data*>(inData);
    }
    
    if (data != nullptr && music != nullptr)
    {           
        float volume = 0;
        float value = 0;

        if (data->configString[0] != '\0') // check if string is empty
        {
            value = std::stof(data->configString);            
            volume = value * 100;
        }
        else
        {
            value = data->data;
            volume = data->data * 100;
        }

        float knobPosY = sliderLine->getPosition().y + (sliderLine->getSize().y / 2);
        float knobPosX = (value * (endPoint.x - startPoint.x)) + startPoint.x;
        sliderKnob->setPosition(sf::Vector2f(knobPosX, knobPosY));

        Logger::Log(LoggerLevel::DEBUG, "sf",GetName().c_str(), volume);

        System::Get()->config->UpdateConfig(configSetting, std::to_string(data->data));

        music->setVolume(volume);
    }
}

void AudioSlider::SetMusic(std::shared_ptr<sf::Music> inMusic)
{
    music = inMusic;
}
