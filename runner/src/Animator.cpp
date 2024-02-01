#include "Animator.h"
#include <string_view>
#include <stdexcept>
#include <format>

using namespace std::literals::string_view_literals;

Animator::Animator(std::string filePath1, std::string filePath2)
{
	if (!sprite1.loadFromFile(filePath1)) {
		throw std::runtime_error(std::format("Unable to load texture: {}"sv, filePath1));
	}
	if (!sprite2.loadFromFile(filePath2)) {
		throw std::runtime_error(std::format("Unable to load texture: {}"sv, filePath2));
	}
}

void Animator::Animate(float m_deltatime)
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

