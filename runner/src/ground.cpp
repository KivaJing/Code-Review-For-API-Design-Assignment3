#include "ground.h"

Ground::Ground()
{
	sf::Vector2f position = {0.0f, 600.0f};

	while (position.x < screen_width)
	{
		position.x += 100.0f;
		float height = 10.0f;
		float width = rng.GetRandomFloat(20.0f, 40.0f);
		Add_entity({ { position.x, position.y, width, height }, false, 0.0f, barrier_color, m_Speed });
		Add_entity({ { position.x + 40.0f, position.y + 50.0f, width, height }, false, 0.0f, barrier_color, m_Speed });
	}
	AddBarriers({ barrierSize, false, 0, barrier_color, { -400, 0 } });
}

void Ground::Render(runner::PrimitiveBatch& batch)
{	
	batch.draw_rectangle(floor, barrier_color);

	for (const auto& entity : entity_list)
	{
		batch.draw_rectangle(entity.rect, entity.color);
	}

	for (const auto& barrier : barriers)
	{
		batch.draw_rectangle(barrier.rect, barrier.color);
	}
}

void Ground::Update(float m_deltatime)
{
	if (is_active && entity_list.size())
	{
		Move(m_deltatime);
	}

	wait_time += m_deltatime;

	if (wait_time > add_barrier_time)
	{
		wait_time = 0;
		AddBarriers({barrierSize, false, 0, barrier_color, m_Speed});
	}
}

void Ground::Clear()
{
	entity_list.clear();
	barriers.clear();
	wait_time = 0;
}

sf::FloatRect Ground::Get_barrier(int index)
{
	if (index <= barriers.size())
	{
		return barriers[index].rect;
	}
	else return {0,0,0,0};
}

int Ground::Get_Barrier_Quantity()
{
	return static_cast<int>(barriers.size());
}

void Ground::Move(float m_deltatime)
{
	for (auto& entity : entity_list)
	{
		SingleEntityMove(entity, m_deltatime);
	}

	for (auto& barrier : barriers)
	{
		SingleEntityMove(barrier, m_deltatime);
	}
}

void Ground::AddBarriers(Rect_entity barrier)
{
	barriers.emplace_back(barrier.rect, barrier.is_hollow, barrier.thickness, barrier.color, barrier.m_Speed);
}
