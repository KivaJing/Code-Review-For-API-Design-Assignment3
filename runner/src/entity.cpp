#include "entity.h"

void Entity::Move(float deltatime)
{
	for (auto& entity : entity_list)
	{
		entity.rect.left += entity.m_Speed.x * deltatime;
		entity.rect.top += entity.m_Speed.y * deltatime;

		if (entity.rect.left < 0 || entity.rect.left + entity.rect.width > screen_width)
		{
			entity.m_Speed.x *= -1;
		}
		if (entity.rect.top < 0 || entity.rect.top + entity.rect.height > screen_height)
		{
			entity.m_Speed.y *= -1;
		}
	}
}

void Entity::MoveToLeft(Rect_entity& entity, float deltatime)
{
	entity.rect.left += deltatime * entity.m_Speed.x;
	if (entity.rect.left + entity.rect.width < 0)
	{
		entity.rect.left = screen_width;
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
	Rect_entity temp{entity.rect, entity.is_hollow, entity.thickness, entity.color, entity.m_Speed};
	entity_list.push_back(temp);
}

void Entity::Clear()
{
	entity_list.clear();
}
