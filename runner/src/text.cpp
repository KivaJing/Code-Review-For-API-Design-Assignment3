#include "text.h"
#include <iostream>

Text::Text()
{
	font.loadFromFile("assets/fonts.ttf");
}

void Text::Render(PrimitiveBatch& batch)
{
}

void Text::Render(sf::RenderTarget& target)
{
	if (score_value != 0)
	{
		score.setString("score:"+std::to_string(score_value));
		
		score.setFont(font);
		target.draw(score);
	}

       for (int i = 0; i <text_data.size(); i++)
		{
		   sf::Text temp;
		   temp.setString(text_data[i].content);
		   temp.setFillColor(text_data[i].color);
		   temp.setScale(text_data[i].scale, text_data[i].scale);
		   temp.setFont(font);
		   temp.setPosition(text_data[i].position);
		   target.draw(temp);
		
		}
}

void Text::set_score(long value)
{
	score_value = value;
}

void Text::Update(float deltatime)
{
	
}

void Text::add_text(std::string text, sf::Vector2f position,float scale)
{
	
	Text_data temp;
	temp.color = sf::Color::Black;
	temp.content = text;
	temp.scale = static_cast<float>(scale);
	temp.position = position;
	text_data.push_back(temp);
	
	return ;
}

void Text::Clear()
{
	text_data.clear();
}
