#include "TextManager.h"
#include <string_view>
#include <stdexcept>
#include <format>

using namespace std::literals::string_view_literals;

void TextManager::LoadFontFile(const std::string& filePath) {
	if (!m_font.loadFromFile(filePath)) {
		throw std::runtime_error(std::format("Unable to load font: {}"sv, filePath));
	}
}

sf::Text TextManager::SetText(std::string textSentence, int size, sf::Color color, float positionX, float positionY)
{
	sf::Text text;
	text.setFont(m_font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(positionX, positionY);
	text.setString(textSentence);
	return text;
}
