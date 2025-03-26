#pragma once

#include <unordered_map>
#include <string>
#include "UIButton.h"
#include "UIText.h"

typedef std::unordered_map<std::string, int> IntTable;
typedef std::unordered_map<std::string, int> FloatTable;

typedef std::unordered_map<std::string, UIText*> TextTable;
typedef std::unordered_map<std::string, UIButton*> ButtonTable;

class UIData
{
public:
	UIData();
	~UIData();
	void putInt(std::string key, int value);
	void putFloat(std::string key, float value);
	int getInt(std::string key, int defaultVal);
	float getFloat(std::string key, float defaultVal);

	void bindUIText(UIText* uiText);
	void refreshTextFromData(std::string objectName, std::string key, std::string prefix = "");

private:
	IntTable intTable;
	FloatTable floatTable;
	TextTable textTable;
};

