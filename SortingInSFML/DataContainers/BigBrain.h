#ifndef BIGBRAIN_H
#define BIGBRAIN_H
#include <SFML/Graphics.hpp>

class BigBrain
{
public:
	// A set of parameters that will never change through out the lifecycle of the program.
	enum sortingTypes { bubbleSort, insertionSort, selectionSort, shellSort };
	enum statesUpdate { increment, decrement };
	unsigned int const WIDTH{ 880 };
	unsigned int const HEIGHT{ 500 };
	int const itemsChangeAmount{ 5 };

	unsigned int const BARS_WIDTH{ WIDTH };
	unsigned int const BARS_HEIGHT{ HEIGHT - 100 };

	unsigned int const FPS{ 30 };
	bool const V_SYNC{ true };
	std::string const TITLE{ "Sorting Vizualized" };
	std::string const SORTING_FUNCTIONS[4] = { "Bubble Sort", "Insertion Sort", "Selection Sort", "Shell Sort" };
	std::string const OPERATIONAL_STATES[2] = { "Sorting", "IDLE" };

	std::map<std::string, sortingTypes> const SORTING_FUNCTION_DEFINTIONS =
	{
		{ "Bubble Sort", bubbleSort },
		{ "Insertion Sort", insertionSort },
		{ "Selection Sort", selectionSort },
		{ "Shell Sort", shellSort }
	};

	std::map<int, bool> OPERATIONAL_STATES_DEFINITION =
	{
		{ 0, true },
		{ 1, false }
	};

	// A set of paramters that change through the programs lifecycle
	int currentlyUsedAmountOfElements{ 30 };

	std::string currentlyUsedSorter;
	int currentlyUsedSorterIntRef{ 0 };
	int currentlyUsedSorterSize{ sizeof(SORTING_FUNCTIONS) / sizeof(SORTING_FUNCTIONS[0]) };

	std::string currentlyUsedState;
	int currentlyUsedStateIntRef{ 1 };
	int currentlyUsedStatesSize{ sizeof(OPERATIONAL_STATES) / sizeof(OPERATIONAL_STATES[0]) };

	/// <summary>
	/// Construct the BigBrain as an object, with a set of pre-determined parameters.
	/// The given parameters can then be utilized in other objects to keep the operationability
	/// of the whole system.
	/// </summary>
	BigBrain();

	~BigBrain();

	/// <summary>
	/// Confirm what the state chosen by the user means - whether it is allowed or not to
	/// continue calculations by sorters further.
	/// </summary>
	/// <returns></returns>
	bool confirmState();

	/// <summary>
	/// Confirm which sorter is chosen at the current step to sort the existing values in an array.
	/// </summary>
	/// <returns>An enum balue defining a sorter reusable for a switch statement.</returns>
	sortingTypes confirmSorter();

	/// <summary>
	/// Update the knowledge of the BigBrain on the environment in which it operats.
	/// Particularly - what kind of an input the user provided.
	/// </summary>
	/// <param name="eventInit">Type of the input a user provided.</param>
	/// <param name="arrayLimit">Maximum amount of elements in an array that might be
	/// affected by any changes, caused by user's actions.</param>
	void update(sf::Keyboard::Key eventInit, unsigned int arrayLimit);

	/// <summary>
	/// Update knowledge on the currently used state of the operations in the operating window. We want to
	/// know if the state changed and whether the sorting should continue or halt.
	/// </summary>
	void updateCurrentlyUsedState();

private:

	/// <summary>
	/// Update knowledge on the amount of elements the user wants to operate with.
	/// </summary>
	/// <param name="update">What actions a user has taken to update the values - incremented or decremented.</param>
	/// <param name="arrayLimit">Knowledge on maximum amount of values present in an array, to know on whether
	/// anything can be modified based on the user's wishes.</param>
	void updateAmountOfElements(statesUpdate update, unsigned int arrayLimit);

	/// <summary>
	/// Update knowledge on the currently used sorter to sort the array of values.
	/// </summary>
	/// <param name="update">What actions a user has taken to update the used sorter - pressed up or down.</param>
	void updateCurrentlyUsedSorter(statesUpdate update);
};

#endif