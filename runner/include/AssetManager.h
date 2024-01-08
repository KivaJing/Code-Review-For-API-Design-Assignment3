#pragma once
#include <unordered_map>
#include "batch.hpp"

class AssetManager
{
public:
	AssetManager() noexcept = default;
	~AssetManager();

	const sf::Texture& GetTexture(std::string name);
	const sf::Texture& GetTexture(int index);
	void LoadTexture(std::string name, std::string path);
	bool LoadFontFile(const std::string& filePath);
	sf::Text SetText(std::string textSentence, int size, sf::Uint32 textStyle, float positionX, float positionY);

private:
	sf::Font m_font;
	int GetLength() noexcept;
};