#include "Animator.h"

void Animator::SetUp(const sf::Texture& frame1, const sf::Texture& frame2)
{
	sprite1.setTexture(frame1);
	sprite2.setTexture(frame2);
}

void Animator::Animate(float m_deltatime) noexcept
{
	animationTimer += m_deltatime;
	if (animationTimer >= change_time)
	{
		animationTimer = 0;
		currentSprite = isFirstFrame ? sprite2 : sprite1;
		isFirstFrame = !isFirstFrame;
	}
}

void Animator::Render(sf::RenderTarget& target, sf::Vector2f position, float scale)
{
	currentSprite.setPosition(position);
	currentSprite.setScale(scale, scale);
	target.draw(currentSprite);
}

