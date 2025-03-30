#pragma once

#include "AScene.h"
#include <unordered_map>

typedef std::unordered_map<std::string, AScene*> SceneTable;
typedef std::vector<std::string> SceneList;

class SceneManager
{
public:
	static std::string MAIN_MENU_SCENE;
	static std::string RESULTS_SCENE;
	static std::string LEVEL_1_SCENE;
	static std::string LEVEL_2_SCENE;
	static std::string LEVEL_3_SCENE;

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

