#ifndef ARRAYSHOLDER_H
#define ARRAYSHOLDER_H
#include <SFML/Graphics.hpp>

class ArraysHolder
{
public:
	static unsigned int const SIZE_OF_THE_ARRAY{ 180 };
	int setOfNumbers[SIZE_OF_THE_ARRAY];
	sf::RectangleShape setOfRectangles[SIZE_OF_THE_ARRAY];
	bool arraySorted{ false };

	int windowHeight;

	int barsHeight;
	int barsWidth;
	int barsVisible;

	/// <summary>
	/// Constructor. Builds the initial version that holds data about bars that
	/// will be sorted.
	/// </summary>
	/// <param name="barsHeight">Expected height of bars in the window.</param>
	/// <param name="windowHeight">The total size of the window.</param>
	/// <param name="barsWidth">Expected width of bars in the window.</param>
	/// <param name="barsVisible">How many bars do we expect to see on a screen.</param>
	ArraysHolder(int barsHeight, int windowHeight, int barsWidth, int barsVisible);

	~ArraysHolder();

	/// <summary>
	/// Check if the array is sorted.
	/// </summary>
	/// <param name="values">An array of values.</param>
	/// <param name="size">The size of the array.</param>
	/// <returns>Returns information on whether the array of values is sorted or not.</returns>
	bool checkIfSorted();

	/// <summary>
	/// Update information about the rectangles that are saved with this object, if the number
	/// of visualized rectangles should change.
	/// </summary>
	/// <param name="amount">Amount of visible rectangles to the user.</param>
	void updateRectangles(int amount);

	/// <summary>
	/// Draw the rectangles on the screen.
	/// </summary>
	/// <param name="window">Window that is used to show data to the user.</param>
	void drawRectangles(sf::RenderWindow& window);

private:
	/// <summary>
	/// Check whether the desired amount of bars to visualize is not smaller than 0 and
	/// not larger than the array initially allowed there to be.
	/// </summary>
	void checkDataPrePopulating();

	/// <summary>
	/// Populate an array of data with random numbers, that later will be used
	/// to generate the height of visualized bars.
	/// </summary>
	void populateArrayWithRandomNumbers();

	/// <summary>
	/// Populate an array of bars to be visualized with data. They can be visualized
	/// right away further.
	/// </summary>
	void assignRectanglesToAnArray();
};

#endif