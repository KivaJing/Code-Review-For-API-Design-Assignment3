#pragma once
#include "entity.h"

class Ground final: public Entity
{
	const sf::FloatRect floor = { 0.0f, 550.0f, 1280.0f, 15.0f };
	const sf::FloatRect barrierSize = { 1200.0f, 450.0f, 50.0f, 100.0f };
	const sf::Color barrier_color = { 200,200,200 };
	const sf::Vector2f m_Speed = { -400.0f, 0.0f };
	std::vector <Rect_entity> barriers;
	bool is_active = true;
	float add_barrier_time = 15.0f;
	float wait_time = 0.0f;

	void Move(float m_deltatime) override;
	void AddBarriers(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed);

public:
	void Setup();
	void Render(runner::PrimitiveBatch& batch) override;
	void Update(float m_deltatime) override;
	void Clear() override;
	sf::FloatRect Get_barrier(int index);
	int Get_Barrier_Quantity();
};