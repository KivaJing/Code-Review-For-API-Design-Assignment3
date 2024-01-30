#include "player.h"

void Player::Render(sf::RenderTarget& target)
{
	anim.Render(target, position, scale);
}

void Player::Update(float m_deltatime) noexcept
{
	anim.Animate(m_deltatime);

	if (jump_timer > 0)
	{
		jump_timer -= m_deltatime;
		if (jump_timer >= duration * 0.5f)
		{
			position.y -= jump_height / (duration * 0.5f) * m_deltatime;
		}
		else
		{	
			position.y += jump_height / (duration * 0.5f) * m_deltatime;
		}
	}
	else
	{
		jump_timer = 0;
		Landing();
	}
}

void Player::Jump() noexcept
{
	if (is_on_ground)
	{
		is_on_ground = false;
		jump_timer = duration;
	}
}

void Player::Landing() noexcept
{
	is_on_ground = true;
	position.y = landingPositionY;
}

sf::FloatRect Player::GetRect()
{
	sf::FloatRect temp{ position.x, position.y, scale * size.x, scale * size.y};	
	return temp;
}
