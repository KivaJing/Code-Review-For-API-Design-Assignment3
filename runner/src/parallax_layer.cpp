#include "parallax_layer.h"

void Layer::Setup(const LayerSetupParams& params)
{
    float left = 0.0f;

    while (left < screen_width)
    {
        float width = rng.GetRandomFloat(params.minWidth, params.maxWidth);
        left += width;
        float height = rng.GetRandomFloat(params.minHeight, params.maxHeight);
        sf::Color temp_color = {
            static_cast<sf::Uint8>(rng.GetRandomInt(0, 255)),
            255,
            static_cast<sf::Uint8>(rng.GetRandomInt(0, 255))
        };
        Add_entity({ { left, top - height + 500.0f, width, height }, params.isHollow, 5, temp_color, { -params.speedX, 0 } });
    }
}

void Layer::Move(float m_deltatime)
{
    for (auto& entity : entity_list)
    {
        MoveToLeft(entity, m_deltatime);
    }
}
