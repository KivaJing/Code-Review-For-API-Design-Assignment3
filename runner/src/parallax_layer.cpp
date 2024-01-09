#include "parallax_layer.h"

void Layer::Setup(const LayerSetupParams& params)
{
    re.seed(rd());
    float left = 0.0f;
    float top = 50.0f;
    while (left < screen_width)
    {
        left += params.minWidth + widthRange(re) * (params.maxWidth - params.minWidth);
        float height = params.minHeight + heightRange(re) * (params.maxHeight - params.minHeight);
        float width = params.minWidth + widthRange(re) * (params.maxWidth - params.minWidth);
        sf::Color temp_color = {
            static_cast<sf::Uint8>(colorRange(re)),
            255,
            static_cast<sf::Uint8>(colorRange(re))
        };
        Add_entity({ { left, top - height + 500, width, height }, params.isHollow, 5, temp_color, { -params.speedX, 0 } });
    }
}

void Layer::Move(float m_deltatime)
{
    for (auto& entity : entity_list)
    {
        MoveToLeft(entity, m_deltatime);
    }
}
