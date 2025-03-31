#include "UIManager.h"

UIManager* UIManager::sharedInstance = NULL;

const std::string UIManager::SCORE_UI_KEY = "SCORE_UI_KEY";
const std::string UIManager::LIFE_UI_KEY = "LIFE_UI_KEY";
const std::string UIManager::LEVEL_UI_KEY = "LEVEL_UI_KEY";

UIManager* UIManager::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new UIManager();
	}
	return sharedInstance;
}

UIData* UIManager::getUIData(std::string name)
{
	return this->dataTable[name];
}

UIData* UIManager::storeData(std::string name)
{
	if (this->dataTable[name] != nullptr)
	{
		return this->dataTable[name];
	}

	UIData* data = new UIData();
	this->dataTable[name] = data;
	return data;
}

void UIManager::removeData(std::string name)
{
	delete this->dataTable[name];
	this->dataTable.erase(name);
}