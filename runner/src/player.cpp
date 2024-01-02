#include "player.h"
#include <iostream>

void Player::animate(float deltatime)
{
	animationTimer += deltatime;
	if (animationTimer >= changeTime)
	{
		animationTimer = 0;
		if (currentFrame == 1)
		{
			currentFrame = 2;
		
			current_texture = frame2;
			
		}
		else
		{
			currentFrame = 1;
			
			current_texture = frame1;
		}
	}
}

void Player::Setup()
{
	frame1.loadFromFile("assets/playerFrame1.png");
	frame2.loadFromFile("assets/playerFrame2.png");
	
	current_texture = frame1;
	
}

void Player::Render(PrimitiveBatch& batch)
{//not used
}

void Player::Render(sf::RenderTarget& target)
{
	
	sf::Sprite temp;
	temp.setTexture(current_texture);
	
	temp.setPosition(position);
	temp.setScale(scale, scale);

	target.draw(temp);
	
	
}

void Player::Update(float deltatime)
{
	animate(deltatime);

	if (jump_timer > 0)
	{
	jump_timer -= deltatime;
		if (jump_timer >= jump_time * 0.5)
		{//jumping
		
			float y= position.y;
			y-=static_cast<float>(jump_height / (jump_time * 0.5) * deltatime);
			
			position.y = y;
		}
		else
		{//falling
			
			float y = position.y;
			y += static_cast<float>(jump_height / (jump_time * 0.5) * deltatime);
		
			position.y = y;
		}

	}
	else
	{
		jump_timer = 0;
		on_ground();
	}
}

void Player::jump()
{
	if (is_on_ground)
	{
is_on_ground = false;
	jump_timer = jump_time;
}
	
}

void Player::on_ground()
{
	is_on_ground = true;
	
	position.y = 150;
}



sf::FloatRect Player::get_rect()
{
	sf::FloatRect temp;
	
	temp.left = position.x;
	temp.top = position.y;
	temp.width = static_cast<float>(100*scale);
		temp.height = static_cast<float>(200*scale);
		
	return temp;
}
