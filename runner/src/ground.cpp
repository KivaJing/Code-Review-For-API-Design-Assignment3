#include "ground.h"

void Ground::Setup()
{
	Rect_entity temp;
	float left = 0;
	float top = 600;
		
	while (left < screen_width)
	{
		left += 100;
		float height = 10;
		float width = (rand() / float(RAND_MAX) * 20) + 20;
		Add_entity({ { left,top ,width,height }, false, 0, barrier_color, { -400, 0 } });
		Add_entity({ { left + 40,top + 50,width,height }, false, 0, barrier_color, { -400,0 } });
	}
	AddBarriers(barrierSize, false, 0, barrier_color, { -400,0 });
}

void Ground::Render(PrimitiveBatch& batch)
{
	if (is_active && !entity_list.empty())
	{
		for (const auto& entity : entity_list)
		{
			batch.draw_rectangle(entity.rect, entity.color);
		}
	}

	if (!barriers.empty())
	{
		batch.draw_rectangle(floor, barrier_color);

		for (const auto& barrier : barriers)
		{
			batch.draw_rectangle(barrier.rect, barrier.color);
		}
	}
}

void Ground::Update(float deltatime)
{
	if (is_active && entity_list.size())
	{
		Move(deltatime);
	}

	wait_time += deltatime;

	if (wait_time > add_barrier_time)
	{
		wait_time = 0;
		{
			AddBarriers(barrierSize, false, 0, barrier_color, { -500, 0 });
		}
	}
}

void Ground::Clear()
{
	entity_list.clear();
	barriers.clear();
}

sf::FloatRect Ground::get_barrier(int index)
{
	if (index <= barriers.size())
	{
		return barriers[index].rect;
	}
	else return {0,0,0,0};
}

int Ground::get_barrier_quantaty()
{
	return static_cast<int>( barriers.size());
}

void Ground::Move(float deltatime)
{
	for (auto& entity : entity_list)
	{
		entity.rect.left += deltatime * entity.speed.x;
		if (entity.rect.left + entity.rect.width < 0)
		{
			entity.rect.left = screen_width;
		}
	}

	for (auto& barrier : barriers)
	{
		barrier.rect.left += deltatime * barrier.speed.x;
		if (barrier.rect.left + barrier.rect.width < 0)
		{
			barrier.rect.left = screen_width;
		}
	}
}

void Ground::AddBarriers(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed)
{
	barriers.emplace_back(rect, is_hollow, thickness, color, speed);
}
