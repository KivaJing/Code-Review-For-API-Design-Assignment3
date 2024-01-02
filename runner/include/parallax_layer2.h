#pragma once

#include "entity.h"

class Layer2 final :public Entity
{
public:
	Layer2() = default;
	/*virtual void move(float deltatime);
	virtual void update(float deltatime);
	virtual void render(PrimitiveBatch& batch);
	virtual void add_entity(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed);*/
	void setup();
	void move(float deltatime) override;
};
