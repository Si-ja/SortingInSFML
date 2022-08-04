#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <random>
#include <string>
#include "DataContainers/BigBrain.h"
#include "DataContainers/ArraysHolder.h"
#include "SortingFunctions/SortingFunctions.h"
#include "DataContainers/VisualData.h"
#include "DataContainers/AudioPlayer.h"

int main()
{
	// Call the main controller
	BigBrain* hBigBrain = new BigBrain();

	// Create main objects that will take care of data presentation
	ArraysHolder* hArraysHolder = new ArraysHolder(
		hBigBrain->BARS_HEIGHT,
		hBigBrain->HEIGHT,
		hBigBrain->BARS_WIDTH,
		hBigBrain->currentlyUsedAmountOfElements);
	VisualData* hVisualData = new VisualData(
		hBigBrain->WIDTH,
		(hBigBrain->HEIGHT - hBigBrain->BARS_HEIGHT),
		hBigBrain->currentlyUsedAmountOfElements,
		hBigBrain->currentlyUsedSorter,
		hBigBrain->currentlyUsedState
	);
	AudioPlayer* hAudioPlayer = new AudioPlayer();
	sf::RenderWindow window(
		sf::VideoMode(hBigBrain->WIDTH, hBigBrain->HEIGHT),
		hBigBrain->TITLE);
	window.setFramerateLimit(hBigBrain->FPS);
	window.setVerticalSyncEnabled(hBigBrain->V_SYNC);

	// Keep track of whether there was a button press and release
	// In order to not cycle through the menus like crazy
	bool allowNewPress{ true };

	// A logical loop for the window to accept in the thinking process
	sf::Event eventInit;
	while (window.isOpen())
	{
		while (window.pollEvent(eventInit));
		{
			switch (eventInit.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
			case sf::Event::TextEntered:
				if (allowNewPress)
				{
					hAudioPlayer->playBeep();
					allowNewPress = false;
					hBigBrain->update(eventInit.key.code, hArraysHolder->SIZE_OF_THE_ARRAY);
					hArraysHolder->updateRectangles(hBigBrain->currentlyUsedAmountOfElements);
					hVisualData->update(
						hBigBrain->currentlyUsedAmountOfElements,
						hBigBrain->currentlyUsedSorter,
						hBigBrain->currentlyUsedState);
				}
				break;

			case sf::Event::KeyReleased:
				allowNewPress = true;
				break;
			default:
				break;
			}

			// Perform sorting if it is seen required by the user
			if (hBigBrain->confirmState())
			{
				switch (hBigBrain->confirmSorter())
				{
				case BigBrain::bubbleSort:
					bubbleSortInSteps(hArraysHolder->setOfNumbers, hArraysHolder->barsVisible);
					break;
				case BigBrain::insertionSort:
					insertionSortInSteps(hArraysHolder->setOfNumbers, hArraysHolder->barsVisible);
					break;
				case BigBrain::selectionSort:
					selectionSortInSteps(hArraysHolder->setOfNumbers, hArraysHolder->barsVisible);
					break;
				case BigBrain::shellSort:
					shellSortInSteps(hArraysHolder->setOfNumbers, hArraysHolder->barsVisible);
					break;
				default:
					break;
				}

				// Check if the values are sorted, if so, switch the sorting state to idle
				if (hArraysHolder->checkIfSorted())
				{
					hBigBrain->updateCurrentlyUsedState();
					hVisualData->update(
						hBigBrain->currentlyUsedAmountOfElements,
						hBigBrain->currentlyUsedSorter,
						hBigBrain->currentlyUsedState);
				}
			}
		}

		window.clear();
		hArraysHolder->drawRectangles(window);
		hVisualData->visualize(window);

		window.display();
	}

	// Get rid of the heap allocated ArraysHolder to free up the memory.
	delete hArraysHolder;
	delete hVisualData;
	delete hAudioPlayer;
	delete hBigBrain;

	return 0;
}