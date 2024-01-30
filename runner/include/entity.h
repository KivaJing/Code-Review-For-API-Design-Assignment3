#pragma once
#include "batch.hpp"
#include <vector>

struct Rect_entity
{
	sf::FloatRect rect = { 100.0f, 100.0f, 100.0f, 100.0f };
	bool is_hollow = true;
	float thickness = 1.0f;
	sf::Color color = sf::Color::Red;
	sf::Vector2f m_Speed = { 0.0f, 0.0f };
};

class SingleEntity
{
	static constexpr float screen_width = 1280.0f;
	static constexpr float screen_height = 720.0f;

public:
	Rect_entity entity;

	void Move(float m_deltatime);
	void Update(float m_deltatime);
	void Render(runner::PrimitiveBatch& batch) const;
};

class EntityManager
{
private:
	std::vector<SingleEntity> entity_list;

public:
	static constexpr float screen_width = 1280.0f;
	static constexpr float screen_height = 720.0f;
	void AddEntity(const Rect_entity& entity);
	void ClearEntities();
	void UpdateEntities(float m_deltatime);
	void RenderEntities(runner::PrimitiveBatch& batch);
};