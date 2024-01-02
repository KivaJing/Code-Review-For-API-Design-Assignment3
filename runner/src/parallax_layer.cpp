#include"parallax_layer.h"

void Layer::Setup(const LayerSetupParams& params)
{
    re.seed(rd());
    float left = 0;
    float top = 50;
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

void Layer::Move(float deltatime)
{
    for (auto& entity : entity_list)
    {
        entity.rect.left += deltatime * entity.speed.x;
        if (entity.rect.left < 0 || entity.rect.left + entity.rect.width < 0)
        {
            entity.rect.left = screen_width;
        }
    }
}
