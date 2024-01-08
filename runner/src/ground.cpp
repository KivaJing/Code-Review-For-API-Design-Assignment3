#include "ground.h"
#include <random>

void Ground::Setup()
{
	sf::Vector2f position = {0.0f, 600.0f};
	std::random_device rd;
	std::default_random_engine re(rd());
	std::uniform_real_distribution<float> widthDistribution(20.0f, 40.0f);

	while (position.x < screen_width)
	{
		position.x += 100.0f;
		float height = 10.0f;
		float width = widthDistribution(re);
		Add_entity({ { position.x, position.y, width, height }, false, 0.0f, barrier_color, m_Speed });
		Add_entity({ { position.x + 40.0f, position.y + 50.0f, width, height }, false, 0.0f, barrier_color, m_Speed });
	}
	AddBarriers(barrierSize, false, 0, barrier_color, { -400, 0 });
}

void Ground::Render(PrimitiveBatch& batch)
{	
	if (is_active && !entity_list.empty())
	{
		batch.draw_rectangle(floor, barrier_color);

		for (const auto& entity : entity_list)
		{
			batch.draw_rectangle(entity.rect, entity.color);
		}
	}

	if (!barriers.empty())
	{
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
		AddBarriers(barrierSize, false, 0, barrier_color, m_Speed);
	}
}

void Ground::Clear()
{
	entity_list.clear();
	barriers.clear();
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

void Ground::Move(float deltatime)
{
	for (auto& entity : entity_list)
	{
		MoveToLeft(entity, deltatime);
	}

	for (auto& barrier : barriers)
	{
		MoveToLeft(barrier, deltatime);
	}
}

void Ground::AddBarriers(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed)
{
	barriers.emplace_back(rect, is_hollow, thickness, color, speed);
}
