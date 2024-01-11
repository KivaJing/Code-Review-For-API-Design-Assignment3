#pragma once
#include "batch.hpp"

namespace Collision
{
	inline sf::FloatRect SumRect(const sf::FloatRect& A, const sf::FloatRect& B)
	{
		constexpr float scaleFactor = 0.25f;
		constexpr float widthFactor = 0.5f;

		float temp_left = B.left - scaleFactor * A.width;
		float temp_top = B.top - scaleFactor * A.height;
		float temp_width = B.width + widthFactor * A.width;
		float temp_height = B.height + widthFactor * A.height;

		return { temp_left, temp_top, temp_width, temp_height };
	}

	inline bool LineToLine(const sf::Vector2f& A_from, const sf::Vector2f& A_to, const sf::Vector2f& B_from, const sf::Vector2f& B_to) noexcept
	{
		auto [Ax1, Ay1] = A_from;
		auto [Ax2, Ay2] = A_to;
		auto [Bx1, By1] = B_from;
		auto [Bx2, By2] = B_to;

		float ua = 0;
		float ub = 0;

		ua = (((Bx2 - Bx1) * (Ay1 - By1)) - (By2 - By1) * (Ax1 - Bx1)) / ((By2 - By1) * (Ax2 - Ax1) - ((Bx2 - Bx1) * (Ay2 - Ay1)));

		if (ua >= 1 || ua <= 0)
		{
			return false;
		}

		ub = ((Ax2 - Ax1) * (Ay1 - By1) - (Ay2 - Ay1) * (Ax1 - Bx1)) / ((By2 - By1) * (Ax2 - Ax1) - (Bx2 - Bx1) * (Ay2 - Ay1));

		if (ub >= 1 || ub <= 0)
		{
			return false;
		}

		return true;
	}

	inline bool CheckLineIntersection(const sf::Vector2f& a_from, const sf::Vector2f& a_to, const sf::FloatRect& rect)
	{
		return LineToLine(a_from, a_to, { rect.left, rect.top }, { rect.left + rect.width, rect.top }) ||
			LineToLine(a_from, a_to, { rect.left, rect.top }, { rect.left, rect.top + rect.height }) ||
			LineToLine(a_from, a_to, { rect.left + rect.width, rect.top }, { rect.left + rect.width, rect.top + rect.height }) ||
			LineToLine(a_from, a_to, { rect.left + rect.width, rect.top + rect.height }, { rect.left + rect.width, rect.top + rect.height });
	}

	inline bool Collide(const sf::FloatRect& A_from, const sf::FloatRect& A_to, const sf::FloatRect& B)
	{
		sf::Vector2f a_from = { A_from.left, A_from.top };
		sf::Vector2f a_to = { A_to.left, A_to.top };
		sf::FloatRect enlarged = SumRect(A_from, B);

		if (CheckLineIntersection(a_from, a_to, enlarged))
		{
			return true;
		}

		if (a_from.x > enlarged.left && a_from.x < enlarged.left + enlarged.width)
		{
			if (a_from.y > enlarged.top && a_from.y < enlarged.top + enlarged.height)
			{
				return true;
			}
		}
		return false;
	}
}