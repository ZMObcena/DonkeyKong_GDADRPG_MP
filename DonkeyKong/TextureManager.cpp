#include "TextureManager.h"
#include <stddef.h>
#include <iostream>

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new TextureManager();
	}

	return sharedInstance;
}

void TextureManager::loadAll()
{
	loadTexture("desert_bg", "Media/Textures/Desert.png");
	sf::Texture* bgTex;
	bgTex = getTexture("desert_bg");
	bgTex->setRepeated(true);

	loadTexture("Eagle", "Media/Textures/Eagle.png");

	loadTexture("Raptor", "Media/Textures/Raptor.png");

}

void TextureManager::loadTexture(std::string key, std::string path)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
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
