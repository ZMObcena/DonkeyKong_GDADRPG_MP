#pragma once

class LevelManager
{
public:
	static LevelManager* getInstance();
	void reset();
	void increaseLevel();
	int getLevel();
	void setLevel(int level);

	void setScore(int score);
	int getScore();

	void setLives(int lives);
	int getLives();

	void proceedToNextLevel(bool proceed);
	bool goNextLevel();

private:
	LevelManager() {};
	LevelManager(LevelManager const&) {};
	LevelManager& operator=(LevelManager const&) {};

	static LevelManager* sharedInstance;

	void checkLevel();
	int level = 1;
	int score = 0;
	int lives = 5;
	bool nextLevel = true;
};

