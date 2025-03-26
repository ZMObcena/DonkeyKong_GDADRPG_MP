#include "UIData.h"

UIData::UIData()
{

}

UIData::~UIData()
{
	this->textTable.clear();
}

void UIData::putInt(std::string key, int value)
{
	this->intTable[key] = value;
}

void UIData::putFloat(std::string key, float value)
{
	this->floatTable[key] = value;
}

int UIData::getInt(std::string key, int defaultVal)
{
	if (this->intTable.count(key) != 0)
	{
		return this->intTable[key];
	}
	else
	{
		return defaultVal;
	}
}

float UIData::getFloat(std::string key, float defaultVal)
{
	if (this->floatTable.count(key) != 0)
	{
		return this->floatTable[key];
	}
	else
	{
		return defaultVal;
	}
}

void UIData::bindUIText(UIText* uiText)
{
	if (uiText)
	{
		this->textTable[uiText->getName()] = uiText;
	}
}

void UIData::refreshTextFromData(std::string objectName, std::string key, std::string prefix)
{
	if (this->textTable.count(objectName) == 0)
		return; // No associated UIText found

	UIText* uiText = this->textTable[objectName];

	std::string newText = prefix; // Start with prefix

	// Check if key exists in intTable or floatTable
	if (this->intTable.count(key))
	{
		newText += std::to_string(this->intTable[key]);
	}
	else if (this->floatTable.count(key))
	{
		newText += std::to_string(this->floatTable[key]);
	}
	else
	{
		newText += "[MISSING DATA]"; // Handle missing keys
	}

	uiText->setText(newText);
}