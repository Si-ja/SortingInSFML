#include "ArraysHolder.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <random>

ArraysHolder::ArraysHolder(int barsHeight, int windowHeight, int barsWidth, int barsVisible)
{
	this->barsHeight = barsHeight;
	this->windowHeight = windowHeight;
	this->barsWidth = barsWidth;
	this->barsVisible = barsVisible;

	this->checkDataPrePopulating();
	this->populateArrayWithRandomNumbers();
	this->assignRectanglesToAnArray();
}

ArraysHolder::~ArraysHolder()
{

}

bool ArraysHolder::checkIfSorted()
{
	bool sorted{ true };

	// We only care if the array is sorted at the base, where bars are seen by the user
	for (int step = 1; step < this->barsVisible; step++)
	{
		int firstValue = this->setOfNumbers[step - 1];
		int secondValue = this->setOfNumbers[step];
		bool comparisonLogical = firstValue <= secondValue;

		if (!comparisonLogical) { sorted = false; }
	}

	this->arraySorted = sorted;
	return this->arraySorted;
}

void ArraysHolder::updateRectangles(int amount)
{
	if (this->barsVisible == amount || amount < 0 || amount > SIZE_OF_THE_ARRAY)
	{
		return;
	}
	else
	{
		this->barsVisible = amount;
		this->checkDataPrePopulating();
		this->populateArrayWithRandomNumbers();
		this->assignRectanglesToAnArray();
	}
}

void ArraysHolder::drawRectangles(sf::RenderWindow& window)
{
	// Make sure rectangles are in the correct sequence before being drawn
	this->assignRectanglesToAnArray();
	for (int i = 0; i < this->barsVisible; i++)
	{
		window.draw(this->setOfRectangles[i]);
	}
}

void ArraysHolder::checkDataPrePopulating()
{
	if (this->barsVisible > this->SIZE_OF_THE_ARRAY)
	{
		this->barsVisible = this->SIZE_OF_THE_ARRAY;
	}
	else if (this->barsVisible < 0)
	{
		// We can't operate with a zero
		this->barsVisible = 1;
	}
	else
	{
		return;
	}
}

void ArraysHolder::populateArrayWithRandomNumbers()
{
	// Set a seed to work with
	srand(time(0));

	for (int i = 0; i < this->barsVisible; i++)
	{
		this->setOfNumbers[i] = (rand() % 100 + 1);
	}
}

void ArraysHolder::assignRectanglesToAnArray()
{
	// Set states for the rectangles
	double barWidth = static_cast<double>(this->barsWidth) / this->barsVisible;
	double barWidthWithBlackLines = barWidth - 2;

	for (int i = 0; i < SIZE_OF_THE_ARRAY; i++)
	{
		// Set states for the rectangles
		double barHeight = static_cast<double>(this->barsHeight) * (0.01 * setOfNumbers[i]);
		double barXPosition = barWidth * i;

		// Create rectangles with known information about them
		sf::RectangleShape rectangle;
		rectangle = sf::RectangleShape(sf::Vector2f(barWidthWithBlackLines, barHeight));
		rectangle.setPosition(barXPosition, this->windowHeight - barHeight);
		rectangle.setFillColor(sf::Color::White);

		// Save the information about the created and saved rectangle in an array
		this->setOfRectangles[i] = rectangle;
	}
}