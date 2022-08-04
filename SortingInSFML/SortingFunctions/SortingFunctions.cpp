#include "SortingFunctions.h"

void bubbleSortInSteps(
	int values[],
	int size)
{
	bool sorted{ false };

	for (int step = 0; step < size - 1; step++)
	{
		if (sorted)
		{
			return;
		}

		for (int i = 0; i < size - step - 1; i++)
		{
			if (sorted)
			{
				return;
			}

			if (values[i] > values[i + 1])
			{
				int temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
				sorted = true;
			}
		}
	}
}

void insertionSortInSteps(
	int values[],
	int size)
{
	bool sorted{ false };

	int key;
	int j;
	for (int i = 1; i < size; i++)
	{
		if (sorted)
		{
			return;
		}

		key = values[i];
		j = i - 1;
		while (j >= 0 && values[j] > key)
		{
			values[j + 1] = values[j];
			j--;
			sorted = true;

			if (sorted)
			{
				values[j + 1] = key;
				return;
			}
		}
	}
}

void selectionSortInSteps(int values[], int size)
{
	bool sorted{ false };
	int temp;

	for (int step = 0; step < size - 1; step++)
	{
		if (sorted)
		{
			return;
		}

		int min_idx = step;
		for (int i = step + 1; i < size; i++)
		{
			if (sorted)
			{
				return;
			}

			if (values[i] < values[min_idx])
			{
				min_idx = i;
				// put min at the correct position
				// Not the exact way, but visually makes more sense
				temp = values[min_idx];
				values[min_idx] = values[step];
				values[step] = temp;
				sorted = true;
			}
		}
	}
}

void shellSortInSteps(int values[], int size)
{
	// With Shell's original sequence: { n/2, n/4, n/8 .. 1 } intervals
	bool sorted{ false };

	for (int interval = size / 2; interval > 0; interval /= 2)
	{
		if (sorted) { return; }
		for (int i = interval; i < size; i += 1)
		{
			if (sorted) { return; }
			int temp = values[i];
			int j;
			for (j = i; j >= interval && values[j - interval] > temp; j -= interval)
			{
				values[j] = values[j - interval];
				sorted = true;
			}
			values[j] = temp;
		}
	}
}