#include "player.h"

void Player::Setup(const sf::Texture& sprite1, const sf::Texture& sprite2)
{
	anim.SetUp(sprite1, sprite2);
}

void Player::Render(sf::RenderTarget& target)
{
	sf::Sprite temp = anim.GetCurrentSprite();
	temp.setPosition(position);
	temp.setScale(scale, scale);
	target.draw(temp);
}

void Player::Update(float m_deltatime)
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
