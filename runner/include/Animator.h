#pragma once
#include "batch.hpp"

class Animator
{
	const float CHANGE_TIME = 0.2f;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite currentSprite;
	float animationTimer = 0;
	bool isFirstFrame = true;

public:
	void SetUp(const sf::Texture& sprite1, const sf::Texture& sprite2);
	void Animate(float deltatime);
	sf::Sprite GetCurrentSprite();
};