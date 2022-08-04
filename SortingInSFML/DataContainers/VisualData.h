#ifndef VISUALDATA_H
#define VISUALDATA_H
#include <SFML/Graphics.hpp>
#include <string>

class VisualData
{
public:
	unsigned int WIDTH;
	unsigned int HEIGHT;
	float TEXT_WIDTH_CENTER;
	float TEXT_HEIGHT_DEDICATED_BOUNDRIES;

	unsigned int const textSize{ 25 };
	sf::Color const textColor{ sf::Color::White };
	std::string const fontLocation{ "Fonts/Pixeltype.ttf" };

	int baseElementsCount;
	std::string baseUsedSotringFunction;
	std::string baseOperationsState;

	sf::Font mainFont;
	sf::Text elementsCount;
	sf::Text usedSotringFunction;
	sf::Text operationsState;

	/// <summary>
	/// Create an object that will be communicated to by ouitside sources, informing it, what the current state of the project is in.
	/// This information will be visible to the user.
	/// </summary>
	/// <param name="WIDTH">Allowed width where text values can be located.</param>
	/// <param name="HEIGHT">Allowed height where text values can be located.</param>
	/// <param name="elementCount">Amount of elements currently in use.</param>
	/// <param name="usedSortingFunction">Currently used sorting function by the user.</param>
	/// <param name="operationalState">Currently used operationa state by the user.</param>
	VisualData(unsigned int WIDTH, unsigned int HEIGHT, int elementCount, std::string usedSortingFunction, std::string operationalState);

	~VisualData();

	/// <summary>
	/// Visualize known information to a window for the user to see.
	/// </summary>
	/// <param name="window">Window used to visualize the run of the program.</param>
	void visualize(sf::RenderWindow& window);

	/// <summary>
	/// Update information, if anything changed after the user pressed any buttons.
	/// </summary>
	/// <param name="elementsCount">Currently used amount of elements that the user chose.</param>
	/// <param name="usedSortingFunction">Currently used sorting function that the user chose.</param>
	/// <param name="usedOperationsState">Currently used operational state that the user chose.</param>
	void update(int elementsCount, std::string usedSortingFunction, std::string usedOperationsState);
};

#endif