#pragma once

#include "AScene.h"
#include <unordered_map>

typedef std::unordered_map<std::string, AScene*> SceneTable;
typedef std::vector<std::string> SceneList;

class SceneManager
{
public:
	static std::string MAIN_MENU_SCENE_NAME;
	static std::string GAME_SCENE_NAME;

	static SceneManager* getInstance();
	void registerScene(AScene* scene);
	void loadScene(std::string name);
	void unloadScene();
	bool isSceneLoaded(std::string name);
	void checkLoadScene();

private:
	SceneManager() {};
	SceneManager(SceneManager const&) {};
	SceneManager& operator=(SceneManager const&) {};
	static SceneManager* sharedInstance;

	SceneTable storedScenes;
	//SceneTable activeScenes;
	AScene* activeScene;
	std::string toLoadSceneName;
	bool isLoading = false;

};

