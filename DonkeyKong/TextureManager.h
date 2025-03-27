#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <rapidjson/document.h>

class TextureManager
{
public:
	static TextureManager* getInstance();

	void unloadAll();
	void loadAll();
	void loadMainMenu();
	sf::Texture* getTexture(std::string);
	sf::IntRect getSpriteRect(std::string key, int index);
	std::vector<std::string> getAnimationFrames(std::string textureName, std::string animName);

private:
	TextureManager() {};
	TextureManager(TextureManager const&) {};
	TextureManager& operator=(TextureManager const&) {};
	static TextureManager* sharedInstance;

	void loadTexture(std::string, std::string);
	void loadSpriteSheet(std::string path);
	void loadTextureAndSpriteSheet(std::string key, std::string texpath, std::string jsonpath);

	std::unordered_map< std::string, sf::Texture* > textureMap;
	std::unordered_map< std::string, sf::IntRect > spriteMap;
	std::map<std::string, std::vector<sf::IntRect>> textureSpriteMap;
	std::unordered_map<std::string, std::unordered_map<std::string, sf::IntRect>> spriteSheets;
	std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> textureAnimationMap;
};

