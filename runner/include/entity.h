#pragma once
#include"batch.hpp"
#include <vector>
using namespace runner;
class Entity
{protected:
	struct rect_entity
	{
		sf::FloatRect rect = {100,100,100,100};
		bool is_hollow=true;
		float thickness=1;
		sf::Color color=sf::Color::Red;
		sf::Vector2f speed = {0,0};
	};
	const float screen_width = 1280;
	const float screen_height = 720;
private:
	

	bool is_active = true;
public:
	
	std::vector <rect_entity> entity_list;
	virtual void move(float deltatime);
	Entity()=default;
	virtual void update(float deltatime);
	virtual void render(PrimitiveBatch&batch);
	virtual void add_entity(const sf::FloatRect& rect, bool is_hollow, const float thickness, const sf::Color& color, sf::Vector2f speed);
	virtual void clear();
};