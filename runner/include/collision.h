#pragma once
#include "batch.hpp"

namespace Collision
{
    sf::FloatRect SumRect(const sf::FloatRect& A, const sf::FloatRect& B);
    bool LineToLine(const sf::Vector2f& A_from, const sf::Vector2f& A_to, const sf::Vector2f& B_from, const sf::Vector2f& B_to) noexcept;
    bool CheckLineIntersection(const sf::Vector2f& a_from, const sf::Vector2f& a_to, const sf::FloatRect& rect);
    bool Collide(const sf::FloatRect& A_from, const sf::FloatRect& A_to, const sf::FloatRect& B);
}
