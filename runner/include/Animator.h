#pragma once
#include "batch.hpp"

class Animator
{
	static constexpr float CHANGE_TIME = 0.2f;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite currentSprite;
	float animationTimer;
	bool isFirstFrame;

public:
	Animator() : animationTimer(0), isFirstFrame(true) {};
	void SetUp(const sf::Texture& sprite1, const sf::Texture& sprite2);
	void Animate(float deltatime) noexcept;
	sf::Sprite GetCurrentSprite() noexcept;
};