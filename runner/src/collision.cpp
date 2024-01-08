#include "collision.h"
#include <iostream>

sf::FloatRect Collision::sum_rect(const sf::FloatRect& A, const sf::FloatRect& B)
{
	float temp_left = B.left - scaleFactor * A.width;
	float temp_top = B.top - scaleFactor * A.height;
	float temp_width = B.width + widthFactor * A.width;
	float temp_height = B.height + widthFactor * A.height;

	return { temp_left,temp_top,temp_width,temp_height };
}

bool Collision::line_to_line(const sf::Vector2f& A_from, const sf::Vector2f& A_to, const sf::Vector2f& B_from, const sf::Vector2f& B_to) noexcept
{
	float ua = 0;
	float ub = 0;
	ua = (((B_to.x - B_from.x) * (A_from.y - B_from.y)) - (B_to.y - B_from.y) * (A_from.x - B_from.x)) / ((B_to.y - B_from.y) * (A_to.x - A_from.x) - ((B_to.x - B_from.x) * (A_to.y - A_from.y)));

	if (ua >= 1 || ua <= 0)
	{
		return false;
	}
	ub = ((A_to.x - A_from.x) * (A_from.y - B_from.y) - (A_to.y - A_from.y) * (A_from.x - B_from.x)) / ((B_to.y - B_from.y) * (A_to.x - A_from.x) - (B_to.x - B_from.x) * (A_to.y - A_from.y));
	if (ub >= 1 || ub <= 0)
	{
		return false;
	}

	return true;
}

bool Collision::collision(const sf::FloatRect& A_from, const sf::FloatRect& A_to, const sf::FloatRect& B)
{
	sf::FloatRect enlarged;
	sf::Vector2f a_from = { A_from.left,A_from.top };
	sf::Vector2f a_to = { A_to.left,A_to.top };

	enlarged = sum_rect(A_from, B);

	if (line_to_line(a_from, a_to, { enlarged.left,enlarged.top }, { enlarged.left + enlarged.width,enlarged.top }))
	{
		return true;
	}

	if (line_to_line(a_from, a_to, { enlarged.left,enlarged.top }, { enlarged.left ,enlarged.top + enlarged.height }))
	{
		return true;
	}

	if (line_to_line(a_from, a_to, { enlarged.left + enlarged.width,enlarged.top }, { enlarged.left + enlarged.width,enlarged.top + enlarged.height }))
	{
		return true;
	}

	if (line_to_line(a_from, a_to, { enlarged.left + enlarged.width,enlarged.top + enlarged.height }, { enlarged.left + enlarged.width,enlarged.top + enlarged.height }))
	{
		return true;
	}

	if (a_from.x > enlarged.left && a_from.x < enlarged.left + enlarged.width)
	{
		if (a_from.y > enlarged.top && a_from.y < enlarged.top + enlarged.width)
		{
			return true;
		}
	}
	return false;
}
