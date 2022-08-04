#include "BigBrain.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <map>

BigBrain::BigBrain()
{
	this->currentlyUsedSorter = this->SORTING_FUNCTIONS[currentlyUsedSorterIntRef];
	this->currentlyUsedState = this->OPERATIONAL_STATES[currentlyUsedStateIntRef];
}

BigBrain::~BigBrain()
{

}

bool BigBrain::confirmState()
{
	return this->OPERATIONAL_STATES_DEFINITION.at(this->currentlyUsedStateIntRef);
}

BigBrain::sortingTypes BigBrain::confirmSorter()
{
	return this->SORTING_FUNCTION_DEFINTIONS.at(this->currentlyUsedSorter);
}

void BigBrain::update(sf::Keyboard::Key eventInit, unsigned int arrayLimit)
{
	switch (eventInit)
	{
	case sf::Keyboard::Right:
		this->updateAmountOfElements(increment, arrayLimit);
		break;
	case sf::Keyboard::Left:
		this->updateAmountOfElements(decrement, arrayLimit);
		break;
	case sf::Keyboard::Up:
		this->updateCurrentlyUsedSorter(increment);
		break;
	case sf::Keyboard::Down:
		this->updateCurrentlyUsedSorter(decrement);
		break;
		// Special case for the spaceBar implementation just in this project.
	case sf::Keyboard::Space:
	case 32:
		this->updateCurrentlyUsedState();
		break;
	default:
		break;
	}
}

void BigBrain::updateAmountOfElements(statesUpdate update, unsigned int arrayLimit)
{
	switch (update)
	{
	case increment:
		if (arrayLimit >= this->currentlyUsedAmountOfElements + this->itemsChangeAmount) { this->currentlyUsedAmountOfElements += this->itemsChangeAmount; }
		break;
	case decrement:
		if (0 <= this->currentlyUsedAmountOfElements - this->itemsChangeAmount) { this->currentlyUsedAmountOfElements -= this->itemsChangeAmount; }
		break;
	}
}

void BigBrain::updateCurrentlyUsedSorter(statesUpdate update)
{
	switch (update)
	{
	case increment:
		if (this->currentlyUsedSorterIntRef + 1 < this->currentlyUsedSorterSize)
		{
			this->currentlyUsedSorterIntRef++;
		}
		else
		{
			this->currentlyUsedSorterIntRef = 0;
		}
		this->currentlyUsedSorter = this->SORTING_FUNCTIONS[this->currentlyUsedSorterIntRef];
		break;
	case decrement:
		if (this->currentlyUsedSorterIntRef - 1 < 0)
		{
			this->currentlyUsedSorterIntRef = this->currentlyUsedSorterSize - 1;
		}
		else
		{
			this->currentlyUsedSorterIntRef--;
		}
		this->currentlyUsedSorter = this->SORTING_FUNCTIONS[this->currentlyUsedSorterIntRef];
		break;
	}
}

void BigBrain::updateCurrentlyUsedState()
{
	if (this->currentlyUsedStateIntRef + 1 <= this->currentlyUsedStatesSize - 1)
	{
		this->currentlyUsedStateIntRef++;
	}
	else
	{
		this->currentlyUsedStateIntRef--;
	}
	this->currentlyUsedState = this->OPERATIONAL_STATES[this->currentlyUsedStateIntRef];
}