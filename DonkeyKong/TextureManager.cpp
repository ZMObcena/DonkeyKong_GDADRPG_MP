#include "TextureManager.h"
#include <stddef.h>
#include <iostream>
#include <fstream>
#include <sstream>

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new TextureManager();
	}

	return sharedInstance;
}

void TextureManager::unloadAll() {}

void TextureManager::loadAll()
{
    loadTextureAndSpriteSheet("Mario", "Media/Atlas/Mario_Atlas.png", "Media/Atlas/Mario_Atlas.json");
    loadTextureAndSpriteSheet("DonkeyKong", "Media/Atlas/DK_Atlas.png", "Media/Atlas/DK_Atlas.json");
    loadTextureAndSpriteSheet("Barrel", "Media/Atlas/Barrel_Atlas.png", "Media/Atlas/Barrel_Atlas.json");
    loadTextureAndSpriteSheet("Fire", "Media/Atlas/Fire_Atlas.png", "Media/Atlas/Fire_Atlas.json");

    loadTexture("Floor", "Media/Sprites/Floor.png");
    loadTexture("Lives", "Media/Sprites/Walk2.png");
}

void TextureManager::loadMainMenu()
{
    loadTexture("Start_normal", "Media/Sprites/Start1.png");
    loadTexture("Start_pressed", "Media/Sprites/Start2.png");
    loadTexture("Exit_normal", "Media/Sprites/Exit1.png");
    loadTexture("Exit_pressed", "Media/Sprites/Exit2.png");
    loadTexture("Title", "Media/Sprites/dk.png");
}

void TextureManager::loadTexture(std::string key, std::string path)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

void TextureManager::loadSpriteSheet(std::string jsonPath)
{
    /*
    std::ifstream file(jsonPath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open sprite sheet JSON: " << jsonPath << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    rapidjson::Document doc;
    doc.Parse(buffer.str().c_str());

    if (!doc.HasMember("frames") || !doc["frames"].IsObject() || !doc.HasMember("meta"))
    {
        std::cerr << "Invalid JSON format: " << jsonPath << std::endl;
        return;
    }

    std::string textureName = doc["meta"]["image"].GetString();  // "Mario_Atlas.png"

    for (auto it = doc["frames"].MemberBegin(); it != doc["frames"].MemberEnd(); ++it)
    {
        std::string spriteName = it->name.GetString();
        const rapidjson::Value& frameData = it->value["frame"];

        if (frameData.IsObject())
        {
            int x = frameData["x"].GetInt();
            int y = frameData["y"].GetInt();
            int width = frameData["w"].GetInt();
            int height = frameData["h"].GetInt();

            textureSpriteMap[textureName][spriteName] = sf::IntRect(x, y, width, height);

            // Detect animation sequences
            std::string animPrefix = spriteName.substr(0, spriteName.find_first_of("0123456789")); // Extract "Walk", "Climbing"
            textureAnimationMap[textureName][animPrefix].push_back(spriteName);
        }
    }
    */
}

void TextureManager::loadTextureAndSpriteSheet(std::string key, std::string texturePath, std::string jsonPath)
{
    // Load texture
    sf::Texture* texture = new sf::Texture();
    if (!texture->loadFromFile(texturePath))
    {
        delete texture;
        std::cerr << "Failed to load texture: " << texturePath << std::endl;
        return;
    }

    // Store texture
    textureMap[key] = texture;
    std::cout << "Loaded texture: " << key << std::endl;

    // Load JSON
    std::ifstream file(jsonPath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open sprite sheet JSON: " << jsonPath << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    rapidjson::Document doc;
    doc.Parse(buffer.str().c_str());

    if (!doc.HasMember("frames") || !doc["frames"].IsObject())
    {
        std::cerr << "Invalid JSON format: " << jsonPath << std::endl;
        return;
    }

    // Store sprites in order inside a vector
    std::vector<sf::IntRect> spriteFrames;
    for (auto it = doc["frames"].MemberBegin(); it != doc["frames"].MemberEnd(); ++it)
    {
        const rapidjson::Value& frameData = it->value["frame"];

        if (frameData.IsObject())
        {
            int x = frameData["x"].GetInt();
            int y = frameData["y"].GetInt();
            int width = frameData["w"].GetInt();
            int height = frameData["h"].GetInt();

            spriteFrames.emplace_back(x, y, width, height);
            std::cout << "Stored sprite frame index " << spriteFrames.size() - 1
                << " -> (" << x << "," << y << "," << width << "," << height << ")" << std::endl;
        }
    }

    textureSpriteMap[key] = spriteFrames;
}


sf::Texture* TextureManager::getTexture(std::string key)
{
	if (textureMap[key] != nullptr)
	{
		return textureMap[key];
	}
	else
	{
		std::cout << "No texture found for" << key << std::endl;
		return nullptr;
	}
}

sf::IntRect TextureManager::getSpriteRect(std::string textureKey, int index)
{
    auto it = textureSpriteMap.find(textureKey);
    if (it != textureSpriteMap.end() && index >= 0 && index < it->second.size())
    {
        return it->second[index];
    }
    else
    {
        std::cerr << "Invalid sprite index " << index << " for texture " << textureKey << std::endl;
        return sf::IntRect(); // Return an empty rect
    }
}

std::vector<std::string> TextureManager::getAnimationFrames(std::string textureName, std::string animName)
{
    if (textureAnimationMap.count(textureName) && textureAnimationMap[textureName].count(animName))
    {
        return textureAnimationMap[textureName][animName];
    }
    else
    {
        std::cerr << "No animation found for " << animName << " in texture " << textureName << std::endl;
        return {};
    }
}