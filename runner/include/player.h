#pragma once
#include "Animator.h"

class Player
{
	static constexpr float scale = 2.0f;
	static constexpr float duration = 1.5f;
	static constexpr float jump_height = 400.0f;
	static constexpr float landingPositionY = 150.0f;
	static const sf::Vector2f size;
	sf::Vector2f position = {200.0f, 150.0f};
	float jump_timer = 0;
	bool is_on_ground = true;
	Animator anim{"assets/playerFrame1.png", "assets/playerFrame2.png"};

public:
	void Render(sf::RenderTarget& target);
	void Update(float m_deltatime) noexcept;
	void Jump() noexcept;
	void Landing() noexcept;
	sf::FloatRect GetRect();
};