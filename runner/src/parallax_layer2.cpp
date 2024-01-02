#include "parallax_layer2.h"

void Layer2::setup()
{
	rect_entity temp;
	float left = 0;
	float top = 50;
	while (left < screen_width)
	{
		left += 100;
		float height = (rand() / float(RAND_MAX) * 200) + 100;
		float width = (rand() / float(RAND_MAX) * 200) + 50;
		sf::Color temp_color = { static_cast<sf::Uint8>(rand() % (255 - 0)), 255,static_cast<sf::Uint8>(rand() % (255 - 0)) };
		add_entity({ left,top - height + 500,width,height }, true, 5, temp_color, { -200, 0 });
	}
}

void Layer2::move(float deltatime)
{
	for (int i = 0; i < entity_list.size(); i++)
	{
		entity_list[i].rect.left += deltatime * entity_list[i].speed.x;
		if (entity_list[i].rect.left +entity_list[i].rect.width< 0)
		{
			entity_list[i].rect.left = screen_width;
		}
	}
}
