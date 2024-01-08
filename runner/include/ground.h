#pragma once
#include "entity.h"

class Ground : public Entity
{
	const sf::FloatRect floor = { 0,550,1280,15 };
	const sf::FloatRect barrierSize = { 1200,450,50,100 };
	const sf::Color barrier_color = { 200,200,200 };

	std::vector <Rect_entity> barriers;
	bool is_active = true;
	float add_barrier_time = 15;
	float wait_time = 0;

	void Move(float deltatime) override;
	void AddBarriers(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed);

public:
	Ground() : is_active(true), add_barrier_time(15), wait_time(0) {}
	void Setup();
	void Render(PrimitiveBatch& batch) override;
	void Update(float deltatime) override;
	void Clear() override;
	sf::FloatRect get_barrier(int index);
	int get_barrier_quantaty();
};