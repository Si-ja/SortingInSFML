#include "VisualData.h"
#include <SFML/Graphics.hpp>
#include <string>

VisualData::VisualData(unsigned int WIDTH, unsigned int HEIGHT, int elementCount, std::string usedSortingFunction, std::string operationalState)
{
	// Assigned an are that can be operated in
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->TEXT_WIDTH_CENTER = static_cast<float>(this->WIDTH) / 2; // Middle of the screen;
	this->TEXT_HEIGHT_DEDICATED_BOUNDRIES = static_cast<float>(this->HEIGHT) / 3; // We have 3 unique text entries to work with;

	// Load a font
	mainFont.loadFromFile(this->fontLocation);

	// Set default values for display for now
	this->baseElementsCount = elementCount;
	this->baseUsedSotringFunction = usedSortingFunction;
	this->baseOperationsState = operationalState;

	// Set font for all the used elements
	this->elementsCount.setFont(this->mainFont);
	this->usedSotringFunction.setFont(this->mainFont);
	this->operationsState.setFont(this->mainFont);

	// Set character size for all text elements
	this->elementsCount.setCharacterSize(this->textSize);
	this->usedSotringFunction.setCharacterSize(this->textSize);
	this->operationsState.setCharacterSize(this->textSize);

	// Set the color for all text elements
	this->elementsCount.setFillColor(this->textColor);
	this->usedSotringFunction.setFillColor(this->textColor);
	this->operationsState.setFillColor(this->textColor);

	// Set text positions
	// With adjustments because oh well...
	this->elementsCount.setPosition(this->TEXT_WIDTH_CENTER - 120, (this->TEXT_HEIGHT_DEDICATED_BOUNDRIES) * 0);
	this->usedSotringFunction.setPosition(this->TEXT_WIDTH_CENTER - 170, (this->TEXT_HEIGHT_DEDICATED_BOUNDRIES) * 1);
	this->operationsState.setPosition(this->TEXT_WIDTH_CENTER - 120, (this->TEXT_HEIGHT_DEDICATED_BOUNDRIES) * 2);

	// Set starting text to give the user something to work with
	this->elementsCount.setString("< Elements Count: " + std::to_string(this->baseElementsCount) + " >");
	this->usedSotringFunction.setString("^ Selected Function: " + this->baseUsedSotringFunction + " v");
	this->operationsState.setString("Current State: " + this->baseOperationsState);
}

VisualData::~VisualData()
{

}

void VisualData::visualize(sf::RenderWindow& window)
{
	window.draw(this->elementsCount);
	window.draw(this->usedSotringFunction);
	window.draw(this->operationsState);
}

void VisualData::update(int elementsCount, std::string usedSortingFunction, std::string usedOperationsState)
{
	this->elementsCount.setString("< Elements Count: " + std::to_string(elementsCount) + " >");
	this->usedSotringFunction.setString("^ Selected Function: " + usedSortingFunction + " v");
	this->operationsState.setString("Current State: " + usedOperationsState);
}
