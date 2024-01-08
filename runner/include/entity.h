#pragma once
#include "batch.hpp"
#include <vector>
using namespace runner;

class Entity
{
protected:
	static constexpr float screen_width = 1280.0f;
	static constexpr float screen_height = 720.0f;

	struct Rect_entity
	{
		sf::FloatRect rect = { 100.0f, 100.0f, 100.0f, 100.0f };
		bool is_hollow = true;
		float thickness = 1.0f;
		sf::Color color = sf::Color::Red;
		sf::Vector2f m_Speed = { 0.0f, 0.0f };
	};

private:
	bool is_active = true;

public:
	std::vector <Rect_entity> entity_list;
	virtual void Move(float deltatime);
	void MoveToLeft(Rect_entity& entity, float deltatime);
	virtual void Update(float deltatime);
	virtual void Render(PrimitiveBatch& batch);
	virtual void Add_entity(Rect_entity entity);
	virtual void Clear();
};