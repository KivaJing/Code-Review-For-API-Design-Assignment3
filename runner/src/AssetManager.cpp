#include "AssetManager.h"

std::unordered_map<std::string, sf::Texture> m_textures;
std::vector<std::string> m_order;
std::unordered_map<std::string, sf::Text> m_text;

bool AssetManager::LoadFontFile(const std::string& filePath) {
    return m_font.loadFromFile(filePath);
}

sf::Text AssetManager::SetText(std::string textSentence, int size, sf::Color color, float positionX, float positionY)
{
    sf::Text text;
    text.setFont(m_font);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(positionX, positionY);
    text.setString(textSentence);
    return text;
}

const sf::Texture& AssetManager::GetTexture(std::string name) {
    return m_textures[name];
}

const sf::Texture& AssetManager::GetTexture(int index) {
    return GetTexture(m_order.at(index));
}

void AssetManager::LoadTexture(std::string name, std::string path) {
    sf::Texture texture = {};

    if (texture.loadFromFile(path)) {
        m_textures[name] = texture;

        m_order.push_back(name);
    }
}

AssetManager::~AssetManager()
{
    m_textures.clear();
}