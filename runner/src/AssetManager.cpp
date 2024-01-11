#include "AssetManager.h"
#include <string_view>
#include <stdexcept>
#include <format>

using namespace std::literals::string_view_literals;

void AssetManager::LoadFontFile(const std::string& filePath) {
    if (!m_font.loadFromFile(filePath)){
        throw(std::runtime_error(std::format("Unable to load font: {}"sv, filePath)));
    }
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
    else {
        throw(std::runtime_error(std::format("Unable to load texture: {}"sv, path)));
    }
}

AssetManager::~AssetManager() noexcept
{
    m_textures.clear();
}