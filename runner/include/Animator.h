#pragma once
#include "batch.hpp"

class Animator
{
	static constexpr float change_time = 0.2f;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite currentSprite;
	float animationTimer = 0.0f;
	bool isFirstFrame = true;

public:
	void SetUp(const sf::Texture& sprite1, const sf::Texture& sprite2);
	void Animate(float m_deltatime) noexcept;
	void Render(sf::RenderTarget& target, sf::Vector2f position, float scale);
};