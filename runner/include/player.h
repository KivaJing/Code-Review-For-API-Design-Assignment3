#pragma once
#include "entity.h"
#include "Animator.h"

class Player final: public Entity
{
	static constexpr float scale = 2.0f;
	static constexpr float duration = 1.5f;
	static constexpr float jump_height = 400.0f;
	static constexpr float landingPositionY = 150.0f;
	const sf::Vector2f size = {100.0f, 200.0f};

	sf::Vector2f position = {200.0f, 150.0f};
	float jump_timer = 0;
	bool is_on_ground = true;
	Animator anim;

public:
	void Setup(const sf::Texture& sprite1, const sf::Texture& sprite2);
	void Render(sf::RenderTarget& target);
	void Update(float m_deltatime);
	void Jump() noexcept;
	void Landing() noexcept;
	sf::FloatRect GetRect();
};