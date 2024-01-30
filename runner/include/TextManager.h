#pragma once
#include <unordered_map>
#include "batch.hpp"

class TextManager
{
	sf::Font m_font;
	std::unordered_map<std::string, sf::Text> m_text;

public:
	void LoadFontFile(const std::string& filePath);
	sf::Text SetText(std::string textSentence, int size, sf::Color color, float positionX, float positionY);
};