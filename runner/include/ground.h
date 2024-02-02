#pragma once
#include "entity.h"
#include "RNG.h"

class Ground
{
	inline static sf::FloatRect floor = { 0.0f, 550.0f, 1280.0f, 15.0f };	
	inline static sf::FloatRect barrierSize = { 1200.0f, 450.0f, 50.0f, 100.0f };
	inline static sf::Color barrier_color = { 200,200,200 };
	inline static sf::Vector2f m_Speed = { -400.0f, 0.0f };
	std::vector <RectEntity> barriers;
	float add_barrier_time = 15.0f;
	float wait_time = 0.0f;
	RandomNumberGenerator rng;
	EntityManager entityManager;

	void Move(float m_deltatime);
	void AddBarriers(RectEntity barrier);

public:
	Ground();
	void Render(runner::PrimitiveBatch& batch);
	void Update(float m_deltatime);
	void Clear();
	sf::FloatRect GetBarrier(int index);
	int GetBarrierQuantity() noexcept;
};