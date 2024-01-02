#pragma once
#include"batch.hpp"

using namespace runner;
class Collision
{
	
	sf::FloatRect sum_rect(sf::FloatRect A, sf::FloatRect B);
	bool line_to_line(sf::Vector2f A_from, sf::Vector2f A_to, sf::Vector2f B_from, sf::Vector2f B_to);
	//A is moving object, B is static object
public:
	bool collision(sf::FloatRect A_from, sf::FloatRect A_to, sf::FloatRect B);
};