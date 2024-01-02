#pragma once
#include "collision.h"
#include "entity.h"
class Player : public Entity
{
	sf::Texture frame1;
	sf::Texture frame2;
	sf::Vector2f position{ 200,100 };
	
	
	sf::Texture current_texture;
	float animationTimer=0;
	float changeTime=0.2;
	int currentFrame=1;
	float scale = 2;
	float jump_time = 1.5;
	float jump_timer= 0;
	float jump_height = 400;
	
	bool is_on_ground = false;

	void animate(float deltatime);
	
public:
	void setup();
	void render(PrimitiveBatch& batch);//not used
	void render(sf::RenderTarget& target);
	void update(float deltatime);
	void jump();
	void on_ground();
	
	sf::FloatRect get_rect();
};