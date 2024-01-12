#include "Animator.h"
#include <string_view>
#include <stdexcept>
#include <format>

using namespace std::literals::string_view_literals;

Animator::Animator()
{
	if (!sprite1.loadFromFile("assets/playerFrame1.png")) {

		throw(std::runtime_error(std::format("Unable to load texture: {}"sv)));
	}
	if (!sprite2.loadFromFile("assets/playerFrame2.png")) {

		throw(std::runtime_error(std::format("Unable to load texture: {}"sv)));
	}
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
	sf::Sprite temp;
	temp.setTexture(currentSprite);
	temp.setPosition(position);
	temp.setScale(scale, scale);
	target.draw(temp);
}

