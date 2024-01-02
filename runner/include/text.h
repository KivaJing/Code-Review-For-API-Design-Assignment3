#pragma once
#include "entity.h"

class Text final :public Entity
{
	sf::Font font;
	
	sf::Text score;
	struct Text_data
	{
		sf::Color color;
		sf::Vector2f position;
		float scale= 0;
		sf::String content;

	};
	std::vector<Text_data> text_data;
	long score_value = 0;
public:
	Text() ;
	void render(PrimitiveBatch& batch); 
	void render(sf::RenderTarget& target) ;
	void set_score(long value);
	void update(float deltatime) override;
	void add_text(std::string text, sf::Vector2f position,float scale=30);
	void clear() override;
};