#include"parallax_layer1.h"
//
//void Layer1::move(float deltatime)
//{
//}
//
//void Layer1::update(float deltatime)
//{
//}
//
//void Layer1::render(PrimitiveBatch& batch)
//{
//}
//
//void Layer1::add_entity(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed)
//{
//}

void Layer1::setup()
{
	rect_entity temp;
	float left = 0;
	float top = 50;
	while (left < screen_width)
	{
		left += 50;
		float height = (rand() / float(RAND_MAX) * 100) + 50;
		float width = (rand() / float(RAND_MAX) * 100) + 20;
		sf::Color temp_color = { static_cast<sf::Uint8>(rand() % (255 - 0)), 255,static_cast<sf::Uint8>( rand() % (255 - 0) )};
		add_entity({ left,top-height+500,width,height }, false, 0, temp_color, { -100, 0 });
	}
}

void Layer1::move(float deltatime)
{
	for (int i = 0; i < entity_list.size(); i++)
	{
		entity_list[i].rect.left += deltatime * entity_list[i].speed.x;
		if (entity_list[i].rect.left < 0)
		{
			entity_list[i].rect.left = screen_width;
		}
	}
}
