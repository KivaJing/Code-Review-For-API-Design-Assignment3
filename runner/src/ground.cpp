#include "ground.h"

void Ground::Setup()
{
	Add_entity({ floor, false, 1, barrier_color, { 0,0 } });


	Rect_entity temp;
	float left = 0;
	float top = 600;
		
	while (left < screen_width)
	{
		left += 100;
		float height = 10;
		float width = (rand() / float(RAND_MAX) * 20) + 20;
		Add_entity({ { left,top ,width,height }, false, 0, barrier_color, { -400, 0 } });//doted lines lower than ground
		Add_entity({ { left + 40,top + 50,width,height }, false, 0, barrier_color, { -400,0 } });
	}
	add_barriers(barrier, false, 0, barrier_color, { -400,0 });
}

void Ground::draw_barriers(PrimitiveBatch& batch)
{
	if (is_active && barriers.size())
	{
		for (int i = 0; i < entity_list.size(); i++)
		{
			if (barriers[i].is_hollow)
			{
				batch.draw_rectangle(barriers[i].rect, barriers[i].thickness, barriers[i].color);
			}
			else
			{
				batch.draw_rectangle(barriers[i].rect, barriers[i].color);
			}
		}
	}
}

void Ground::Render(PrimitiveBatch& batch)
{
	if (is_active && entity_list.size())
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
		for (int i = 0; i < barriers.size(); i++)
		{
			if (barriers[i].is_hollow)
			{
				batch.draw_rectangle(barriers[i].rect, barriers[i].thickness, barriers[i].color);
			}
			else
			{
				batch.draw_rectangle(barriers[i].rect, barriers[i].color);
			}
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
			add_barriers(barrier, false, 0, barrier_color, { -500, 0 });
		}
	}
}

void Ground::Clear()
{
	entity_list.clear();
	barriers.clear();
}

sf::FloatRect Ground::get_ground()
{
	return floor;
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
	for (int i = 0; i < entity_list.size(); i++)
	{
		entity_list[i].rect.left += deltatime * entity_list[i].speed.x;
		if (entity_list[i].rect.left + entity_list[i].rect.width < 0)
		{
			entity_list[i].rect.left = screen_width;
		}
	}
	for (int i = 0; i < barriers.size(); i++)
	{
		barriers[i].rect.left += deltatime * barriers[i].speed.x;
		if (barriers[i].rect.left + barriers[i].rect.width < 0)
		{
			barriers[i].rect.left = screen_width;
		}
	}//1200, 350, 200, 200
}

void Ground::add_barriers(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed)
{
	Rect_entity temp;
	temp.rect = rect;
	temp.is_hollow = is_hollow;
	temp.thickness = thickness;
	temp.color = color;
	temp.speed = speed;
	barriers.push_back(temp);
}
