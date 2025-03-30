#pragma once

class LevelManager
{
public:
	static LevelManager* getInstance();
	void setLevel(int level);
	int getLevel();

	void proceedToNextLevel(bool proceed);
	bool goNextLevel();

private:
	LevelManager() {};
	LevelManager(LevelManager const&) {};
	LevelManager& operator=(LevelManager const&) {};

	static LevelManager* sharedInstance;

	int level = 1;
	bool nextLevel = true;
};

