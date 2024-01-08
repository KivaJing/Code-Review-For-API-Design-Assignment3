#include "player.h"
#include <iostream>

void Player::Setup(const sf::Texture& texture1, const sf::Texture& texture2)
{
	anim.SetUp(texture1, texture2);
}

void Player::Render(sf::RenderTarget& target)
{
	sf::Sprite temp = anim.GetCurrentTexture();
	temp.setPosition(position);
	temp.setScale(scale, scale);

	target.draw(temp);
}

void Player::Update(float deltatime)
{
	anim.Animate(deltatime);

	if (jump_timer > 0)
	{
		jump_timer -= deltatime;
		if (jump_timer >= jump_time * 0.5f)
		{
			position.y -= static_cast<float>(jump_height / (jump_time * 0.5f) * deltatime);
		}
		else
		{	
			position.y += static_cast<float>(jump_height / (jump_time * 0.5) * deltatime);
		}
	}
	else
	{
		jump_timer = 0;
		Landing();
	}
}

void Player::Jump()
{
	if (is_on_ground)
	{
		is_on_ground = false;
		jump_timer = jump_time;
	}
}

void Player::Landing()
{
	is_on_ground = true;
	position.y = 150;
}

sf::FloatRect Player::GetRect()
{
	sf::FloatRect temp{ position.x, position.y, scale * 100, scale * 200};	
	return temp;
}
