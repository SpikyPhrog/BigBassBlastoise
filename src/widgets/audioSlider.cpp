#include "audioSlider.h"
#include "../eventStructs.h"
#include "../eventManager.h"

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
        float volume = data->data * 100;
        printf("%s \t %f\n", GetName().c_str(), volume);
        
        EventManager::GetInstance()->config->UpdateConfig(configSetting, std::to_string(data->data));

        music->setVolume(volume);
    }
}

void AudioSlider::SetMusic(std::shared_ptr<sf::Music> inMusic)
{
    music = inMusic;
}
