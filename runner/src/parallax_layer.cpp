#include "parallax_layer.h"

Layer::Layer()
{
    GenerateBackground({ 20,120,50,150,150, false });
    GenerateBackground({ 50,250,100,300,250, true });
}

void Layer::GenerateBackground(const LayerSetupParams& params)
{
    float left = 0.0f;

    while (left < screen_width)
    {
        float width = rng.GetRandom(params.minWidth, params.maxWidth);
        left += width;
        float height = rng.GetRandom(params.minHeight, params.maxHeight);
        sf::Color temp_color = { rng.GetRandomInt(0, 255),
            255,
            rng.GetRandomInt(0, 255)
        };
        AddEntity({ { left, top - height + 500.0f, width, height }, params.isHollow, 5, temp_color, { -params.speedX, 0 } });
    }
}
