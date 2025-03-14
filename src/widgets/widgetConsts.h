#pragma once
constexpr float elementPadding {20.f};

struct HBData
{
    sf::Vector2f size {0.f, 0.f};
    sf::Vector2f position {0.f, 0.f};
    sf::Vector2f padding {0.f, 0.f};
};

struct VBData 
{
    sf::Vector2f size {0.f, 0.f};
    sf::Vector2f position {0.f, 0.f};
    sf::Vector2f padding {0.f, 0.f};
    bool bIsFullscreen {false};
    bool bFullHeight {false};
    bool bFullWidth {false};
};