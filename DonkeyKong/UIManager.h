#pragma once

#include <unordered_map>
#include "UIButton.h"
#include "UIText.h"
#include "UIData.h"

typedef std::unordered_map<std::string, UIData*> DataTable;

class UIManager
{
public:
	static const std::string SCORE_UI_KEY;
	static const std::string LIFE_UI_KEY;
	static const std::string LEVEL_UI_KEY;

	static UIManager* getInstance();

	UIData* getUIData(std::string name);
	UIData* storeData(std::string name);
	void removeData(std::string name);

private:
	UIManager() {};
	UIManager(UIManager const&) {};
	UIManager& operator = (UIManager const&) {};
	static UIManager* sharedInstance;

	DataTable dataTable;
};

