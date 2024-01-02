#include"entity.h"

void Entity::Move(float deltatime)
{
	for (auto& entity : entity_list)
	{
		entity.rect.left += entity.speed.x * deltatime;
		entity.rect.top += entity.speed.y * deltatime;

		if (entity.rect.left < 0 || entity.rect.left + entity.rect.width > screen_width)
		{
			entity.speed.x *= -1;
		}
		if (entity.rect.top < 0 || entity.rect.top + entity.rect.height > screen_height)
		{
			entity.speed.y *= -1;
		}
	}
}

void Entity::Update(float deltatime)
{
	if (is_active && entity_list.size())
	{
		Move(deltatime);
	}
}

void Entity::Render(PrimitiveBatch& batch)
{
	if (is_active && !entity_list.empty())
	{
		for (const auto& entity : entity_list)
		{
			if (entity.is_hollow)
			{
				batch.draw_rectangle(entity.rect, entity.thickness, entity.color);
			}
			else
			{
				batch.draw_rectangle(entity.rect, entity.color);
			}
		}
	}
}

void Entity::Add_entity(Rect_entity entity)
{
	Rect_entity temp{entity.rect, entity.is_hollow, entity.thickness, entity.color, entity.speed};
	entity_list.push_back(temp);
}

void Entity::Clear()
{
	entity_list.clear();
}
