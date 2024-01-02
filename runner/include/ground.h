#pragma once
#include"entity.h"
class Ground : public Entity
{
	sf::FloatRect floor = { 0,550,1280,15 };
	sf::FloatRect barrier = { 1200,450,50,100 };
	sf::Color barrier_color = { 200,200,200 };
	//sf::Color floor_color = { 200,200,200 };
	//float speed = -150;
	void move(float deltatime) override;
	void add_barriers(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed);
	std::vector <rect_entity> barriers;
	bool is_active = true;
	float add_barrier_time = 15;
	float wait_time = 0;
public:
	Ground() = default;
	void setup();
	void draw_barriers(PrimitiveBatch& batch);
	void render(PrimitiveBatch& batch) override;
	void update(float deltatime) override;
	void clear() override;
	sf::FloatRect get_ground();
	sf::FloatRect get_barrier(int index);
	int get_barrier_quantaty();
};