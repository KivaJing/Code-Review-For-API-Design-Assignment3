#include"entity.h"




void Entity::move(float deltatime)
{
	for (int i = 0; i < entity_list.size(); i++)
	{
		entity_list[i].rect.left += entity_list[i].speed.x * deltatime;
		entity_list[i].rect.top += entity_list[i].speed.y * deltatime;
		if (entity_list[i].rect.left<0 || entity_list[i].rect.left + entity_list[i].rect.width > screen_width)
		{
			entity_list[i].speed.x *= -1;
		}
		if (entity_list[i].rect.top<0 || entity_list[i].rect.top + entity_list[i].rect.height>screen_height)
		{
			entity_list[i].speed.y *= -1;
		}

	}
}

void Entity::update(float deltatime)
{
	if (is_active && entity_list.size())
	{
		move(deltatime);
	}
}

void Entity::render(PrimitiveBatch& batch)
{
	if (is_active&&entity_list.size())
	{
		for (int i = 0; i < entity_list.size(); i++)
		{
			if (entity_list[i].is_hollow)
			{
				batch.draw_rectangle(entity_list[i].rect, entity_list[i].thickness, entity_list[i].color);
			}
			else
			{
				batch.draw_rectangle(entity_list[i].rect, entity_list[i].color);
			}
		}
	}
}

void Entity::add_entity(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed)
{
	rect_entity temp;
	temp.rect = rect;
	temp.is_hollow = is_hollow;
	temp.thickness = thickness;
	temp.color = color;
	temp.speed = speed;
	entity_list.push_back(temp);
}

void Entity::clear()
{
	entity_list.clear();
}
