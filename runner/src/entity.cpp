#include "entity.h"

void Entity::Move(float m_deltatime)
{
	for (auto& entity : entity_list)
	{
		entity.rect.left += entity.m_Speed.x * m_deltatime;
		entity.rect.top += entity.m_Speed.y * m_deltatime;

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

void Entity::MoveToLeft(Rect_entity& entity, float m_deltatime)
{
	entity.rect.left += m_deltatime * entity.m_Speed.x;
	if (entity.rect.left + entity.rect.width < 0)
	{
		entity.rect.left = screen_width;
	}
}

void Entity::Update(float m_deltatime)
{
	if (is_active && entity_list.size())
	{
		Move(m_deltatime);
	}
}

void Entity::Render(runner::PrimitiveBatch& batch)
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
	entity_list.emplace_back(entity.rect, entity.is_hollow, entity.thickness, entity.color, entity.m_Speed);
}

void Entity::Clear()
{
	entity_list.clear();
}
