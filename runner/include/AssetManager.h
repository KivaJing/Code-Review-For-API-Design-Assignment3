#pragma once
#include <unordered_map>
#include "batch.hpp"

class AssetManager
{
	sf::Font m_font;
	std::unordered_map<std::string, sf::Texture> m_textures;
	std::vector<std::string> m_order;
	std::unordered_map<std::string, sf::Text> m_text;

public:
	void LoadFontFile(const std::string& filePath);
	sf::Text SetText(std::string textSentence, int size, sf::Color color, float positionX, float positionY);
	const sf::Texture& GetTexture(std::string name);
	const sf::Texture& GetTexture(int index);
	void LoadTexture(std::string name, std::string path);
	~AssetManager() noexcept;
};