#include "ground.h"

Ground::Ground()
{
	sf::Vector2f position = {0.0f, 600.0f};

	while (position.x < 1280.0f)
	{
		position.x += 100.0f;
		float height = 10.0f;
		float width = rng.GetRandom(20.0f, 40.0f);
		entityManager.AddEntity({ { position.x, position.y, width, height }, false, 0.0f, barrier_color, m_Speed });
		entityManager.AddEntity({ { position.x + 40.0f, position.y + 50.0f, width, height }, false, 0.0f, barrier_color, m_Speed });
	}
	AddBarriers({ barrierSize, false, 0, barrier_color, { -400, 0 } });
}

void Ground::Render(runner::PrimitiveBatch& batch)
{	
	batch.draw_rectangle(floor, barrier_color);
	entityManager.RenderEntities(batch);

	for (const auto& barrier : barriers)
	{
		batch.draw_rectangle(barrier.rect, barrier.color);
	}
}

void Ground::Update(float m_deltatime)
{
	Move(m_deltatime);
	wait_time += m_deltatime;

	if (wait_time > add_barrier_time)
	{
		wait_time = 0;
		AddBarriers({barrierSize, false, 0, barrier_color, m_Speed});
	}
}

void Ground::Clear()
{
	wait_time = 0;
	barriers.clear();
	entityManager.ClearEntities();
}

sf::FloatRect Ground::GetBarrier(int index)
{
	if (index <= barriers.size()){
		return barriers[index].rect;
	}
	else{
		return { 0,0,0,0 };
	}
}

int Ground::GetBarrierQuantity() noexcept
{
	return static_cast<int>(barriers.size());
}

void Ground::Move(float m_deltatime)
{
	for (auto& barrier : barriers)
	{
		barrier.rect.left += m_deltatime * barrier.m_Speed.x;
		if (barrier.rect.left + barrier.rect.width < 0)
		{
			barrier.rect.left = entityManager.screen_width;
		}
	}
}

void Ground::AddBarriers(RectEntity barrier)
{
	barriers.emplace_back(barrier.rect, barrier.is_hollow, barrier.thickness, barrier.color, barrier.m_Speed);
}
