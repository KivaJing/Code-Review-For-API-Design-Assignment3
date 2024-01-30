#pragma once
#include "batch.hpp"

class Animator
{
	static constexpr float change_time = 0.2f;
	sf::Texture sprite1;
	sf::Texture sprite2;
	sf::Texture currentSprite;
	float animationTimer = 0.0f;
	bool isFirstFrame = true;

public:
	Animator() noexcept;
	void Animate(float m_deltatime);
	void Render(sf::RenderTarget& target, sf::Vector2f position, float scale);
};