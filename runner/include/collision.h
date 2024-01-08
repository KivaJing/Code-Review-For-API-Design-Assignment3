#pragma once
#include "batch.hpp"

constexpr float scaleFactor = 0.25f;
constexpr float widthFactor = 0.5f;

class Collision
{
	sf::FloatRect sum_rect(const sf::FloatRect& A, const sf::FloatRect& B);
	bool line_to_line(const sf::Vector2f& A_from, const sf::Vector2f& A_to, const sf::Vector2f& B_from, const sf::Vector2f& B_to) noexcept;

public:
	bool collision(const sf::FloatRect& A_from, const sf::FloatRect& A_to, const sf::FloatRect& B);
};