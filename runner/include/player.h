#pragma once
#include "collision.h"
#include "entity.h"
#include "Animator.h"

class Player : public Entity
{
	const float scale = 2.0f;
	const float jump_time = 1.5f;
	const float jump_height = 400.0f;

	sf::Vector2f position{ 200,100 };	
	float jump_timer = 0;
	bool is_on_ground = false;
	Animator anim;

public:
	void Setup(const sf::Texture& texture1, const sf::Texture& texture2);
	void Render(sf::RenderTarget& target);
	void Update(float deltatime);
	void Jump();
	void Landing();
	
	sf::FloatRect GetRect();
};