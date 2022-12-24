#include "CppUnitTest.h"

#include "../SortingInSFML/SortingFunctions/SortingFunctions.h"
#include "../SortingInSFML/SortingFunctions/SortingFunctions.cpp"

#include <iostream>
#include <map>
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingInSFMLSortingFunctionsUnitTests
{
	TEST_CLASS(SortingFunctionsTests)
	{
	public:

		TEST_METHOD(When_TestingConditionsAreCheckedAndMapsMatch_Then_TheySucceed)
		{
			// Arrange Example
			int const arraySize{ 3 };

			int exampleArray1[arraySize]{ 1, 2, 3 };
			int exampleArray2[arraySize]{ 1, 3, 2 };

			std::map<int, int> exampleArray1Map{ createValuesMap(exampleArray1, arraySize) };
			std::map<int, int> exampleArray2Map{ createValuesMap(exampleArray1, arraySize) };

			// Assert
			Assert::IsTrue(verifyUnchangedArray(exampleArray1Map, exampleArray2Map));
			Assert::IsTrue(verifyArraySequencesDontMatch(exampleArray1, exampleArray1, arraySize));
			Assert::IsTrue(verifyArraySequencesDontMatch(exampleArray2, exampleArray2, arraySize));
			Assert::IsFalse(verifyArraySequencesDontMatch(exampleArray1, exampleArray2, arraySize));
		}

		TEST_METHOD(When_TestingConditionsAreCheckedAndMapsDontMatch_Then_TheyFail)
		{
			// Arrange
			int const array1Size{ 3 };
			int const array2Size{ 6 };

			int exampleArray1[array1Size]{ 1, 2, 3 };
			int exampleArray2[array2Size]{ 1, 2, 3, 4, 5, 6 };

			std::map<int, int> exampleArray1Map{ createValuesMap(exampleArray1, array1Size) };
			std::map<int, int> exampleArray2Map{ createValuesMap(exampleArray1, array2Size) };

			// Assert
			Assert::IsFalse(verifyUnchangedArray(exampleArray1Map, exampleArray2Map));
		}

		TEST_METHOD(When_TestingConditionsAreCheckedAndArraysDontMatchInSize_Then_TheyFail)
		{
			// Arrange
			int const array1Size{ 3 };
			int const array2Size{ 6 };

			int exampleArray1[array1Size]{ 1, 2, 3 };
			int exampleArray2[array2Size]{ 1, 2, 3 };

			std::map<int, int> exampleArray1Map{ createValuesMap(exampleArray1, array1Size) };
			std::map<int, int> exampleArray2Map{ createValuesMap(exampleArray1, array2Size) };

			// Assert
			Assert::IsFalse(verifyUnchangedArray(exampleArray1Map, exampleArray2Map));
		}

		TEST_METHOD(When_BubbleSortSortsOnce_Then_ArrayOfDataIsUnalteredBeyondValuesMovement)
		{
			// Arrange
			int const arraySize{ 40 };
			int arrayContainer[arraySize];
			int arrayContainerBackup[arraySize];
			std::map<int, int> arrayMap;
			std::map<int, int> arrayMapUpdated;

			createRandomArray(arrayContainer, arraySize);
			std::copy(arrayContainer, arrayContainer + arraySize, arrayContainerBackup);
			arrayMap = createValuesMap(arrayContainer, arraySize);

			// Act
			bubbleSortInSteps(arrayContainer, arraySize);
			arrayMapUpdated = createValuesMap(arrayContainer, arraySize);

			// Assert
			Assert::IsFalse(verifyArraySequencesDontMatch(arrayContainer, arrayContainerBackup, arraySize));
			Assert::IsTrue(verifyUnchangedArray(arrayMap, arrayMapUpdated));
		}

		TEST_METHOD(When_InsertionSortSortsOnce_Then_ArrayOfDataIsUnalteredBeyondValuesMovement)
		{
			// Arrange
			int const arraySize{ 40 };
			int arrayContainer[arraySize];
			int arrayContainerBackup[arraySize];
			std::map<int, int> arrayMap;
			std::map<int, int> arrayMapUpdated;

			createRandomArray(arrayContainer, arraySize);
			std::copy(arrayContainer, arrayContainer + arraySize, arrayContainerBackup);
			arrayMap = createValuesMap(arrayContainer, arraySize);

			// Act
			insertionSortInSteps(arrayContainer, arraySize);
			arrayMapUpdated = createValuesMap(arrayContainer, arraySize);

			// Assert
			Assert::IsFalse(verifyArraySequencesDontMatch(arrayContainer, arrayContainerBackup, arraySize));
			Assert::IsTrue(verifyUnchangedArray(arrayMap, arrayMapUpdated));
		}

		TEST_METHOD(When_ShellSortSortsOnce_Then_ArrayOfDataIsUnalteredBeyondValuesMovement)
		{
			// Arrange
			int const arraySize{ 40 };
			int arrayContainer[arraySize];
			int arrayContainerBackup[arraySize];
			std::map<int, int> arrayMap;
			std::map<int, int> arrayMapUpdated;

			createRandomArray(arrayContainer, arraySize);
			std::copy(arrayContainer, arrayContainer + arraySize, arrayContainerBackup);
			arrayMap = createValuesMap(arrayContainer, arraySize);

			// Act
			shellSortInSteps(arrayContainer, arraySize);
			arrayMapUpdated = createValuesMap(arrayContainer, arraySize);

			// Assert
			Assert::IsFalse(verifyArraySequencesDontMatch(arrayContainer, arrayContainerBackup, arraySize));
			Assert::IsTrue(verifyUnchangedArray(arrayMap, arrayMapUpdated));
		}

		TEST_METHOD(When_SelectionSortSortsOnce_Then_ArrayOfDataIsUnalteredBeyondValuesMovement)
		{
			// Arrange
			int const arraySize{ 40 };
			int arrayContainer[arraySize];
			int arrayContainerBackup[arraySize];
			std::map<int, int> arrayMap;
			std::map<int, int> arrayMapUpdated;

			createRandomArray(arrayContainer, arraySize);
			std::copy(arrayContainer, arrayContainer + arraySize, arrayContainerBackup);
			arrayMap = createValuesMap(arrayContainer, arraySize);

			// Act
			selectionSortInSteps(arrayContainer, arraySize);
			arrayMapUpdated = createValuesMap(arrayContainer, arraySize);

			// Assert
			Assert::IsFalse(verifyArraySequencesDontMatch(arrayContainer, arrayContainerBackup, arraySize));
			Assert::IsTrue(verifyUnchangedArray(arrayMap, arrayMapUpdated));
		}

		TEST_METHOD(When_BubbleSortSortsUntilTheEnd_Then_MapsMatchButSequncesDont)
		{
			// Arrange
			int const arraySize{ 40 };
			int arrayContainer[arraySize];
			int arrayContainerBackup[arraySize];
			std::map<int, int> arrayMap;
			std::map<int, int> arrayMapUpdated;

			createRandomArray(arrayContainer, arraySize);
			std::copy(arrayContainer, arrayContainer + arraySize, arrayContainerBackup);
			arrayMap = createValuesMap(arrayContainer, arraySize);

			// Act
			while (!verifySortedArray(arrayContainer, arraySize)) { bubbleSortInSteps(arrayContainer, arraySize); }
			arrayMapUpdated = createValuesMap(arrayContainer, arraySize);

			// Assert
			Assert::IsFalse(verifyArraySequencesDontMatch(arrayContainer, arrayContainerBackup, arraySize));
			Assert::IsTrue(verifySortedArray(arrayContainer, arraySize));
			Assert::IsTrue(verifyUnchangedArray(arrayMap, arrayMapUpdated));
		}

		TEST_METHOD(When_InsertionSortSortsUntilTheEnd_Then_MapsMatchButSequncesDont)
		{
			// Arrange
			int const arraySize{ 40 };
			int arrayContainer[arraySize];
			int arrayContainerBackup[arraySize];
			std::map<int, int> arrayMap;
			std::map<int, int> arrayMapUpdated;

			createRandomArray(arrayContainer, arraySize);
			std::copy(arrayContainer, arrayContainer + arraySize, arrayContainerBackup);
			arrayMap = createValuesMap(arrayContainer, arraySize);

			// Act
			while (!verifySortedArray(arrayContainer, arraySize)) { insertionSortInSteps(arrayContainer, arraySize); }
			arrayMapUpdated = createValuesMap(arrayContainer, arraySize);

			// Assert
			Assert::IsFalse(verifyArraySequencesDontMatch(arrayContainer, arrayContainerBackup, arraySize));
			Assert::IsTrue(verifySortedArray(arrayContainer, arraySize));
			Assert::IsTrue(verifyUnchangedArray(arrayMap, arrayMapUpdated));
		}

		TEST_METHOD(When_SelectionSortSortsUntilTheEnd_Then_MapsMatchButSequncesDont)
		{
			// Arrange
			int const arraySize{ 40 };
			int arrayContainer[arraySize];
			int arrayContainerBackup[arraySize];
			std::map<int, int> arrayMap;
			std::map<int, int> arrayMapUpdated;

			createRandomArray(arrayContainer, arraySize);
			std::copy(arrayContainer, arrayContainer + arraySize, arrayContainerBackup);
			arrayMap = createValuesMap(arrayContainer, arraySize);

			// Act
			while (!verifySortedArray(arrayContainer, arraySize)) { selectionSortInSteps(arrayContainer, arraySize); }
			arrayMapUpdated = createValuesMap(arrayContainer, arraySize);

			// Assert
			Assert::IsFalse(verifyArraySequencesDontMatch(arrayContainer, arrayContainerBackup, arraySize));
			Assert::IsTrue(verifySortedArray(arrayContainer, arraySize));
			Assert::IsTrue(verifyUnchangedArray(arrayMap, arrayMapUpdated));
		}

		TEST_METHOD(When_ShellSortSortsUntilTheEnd_Then_MapsMatchButSequncesDont)
		{
			// Arrange
			int const arraySize{ 40 };
			int arrayContainer[arraySize];
			int arrayContainerBackup[arraySize];
			std::map<int, int> arrayMap;
			std::map<int, int> arrayMapUpdated;

			createRandomArray(arrayContainer, arraySize);
			std::copy(arrayContainer, arrayContainer + arraySize, arrayContainerBackup);
			arrayMap = createValuesMap(arrayContainer, arraySize);

			// Act
			while (!verifySortedArray(arrayContainer, arraySize)) { shellSortInSteps(arrayContainer, arraySize); }
			arrayMapUpdated = createValuesMap(arrayContainer, arraySize);

			// Assert
			Assert::IsFalse(verifyArraySequencesDontMatch(arrayContainer, arrayContainerBackup, arraySize));
			Assert::IsTrue(verifySortedArray(arrayContainer, arraySize));
			Assert::IsTrue(verifyUnchangedArray(arrayMap, arrayMapUpdated));
		}


	private:

		void createRandomArray(int values[], int size)
		{
			srand(time(0));

			for (int i = 0; i < size; i++)
			{
				values[i] = (rand() % 100 + 1);
			}

			// Always add two last values, as with nature of randomness
			// There is a slim chance once all numbers will be in the correct
			// Sequence from the start. We want to avoid that.
			values[size - 2] = 1;
			values[size - 1] = 0;
		}

		std::map<int, int> createValuesMap(int values[], int size)
		{
			std::map<int, int> arrayMap;

			for (int step = 0; step < size; step++)
			{
				bool found = static_cast<bool>(arrayMap.count(values[step]));
				if (found)
				{
					std::map<int, int>::iterator item = arrayMap.find(values[step]);
					if (item != arrayMap.end()) { item->second++; }
				}
				else
				{
					arrayMap.insert(std::pair<int, int>(values[step], 1));
				}
			}

			return arrayMap;
		}

		bool verifySortedArray(int values[], int size)
		{
			bool sorted{ true };

			int firstValue;
			int secondValue;

			for (int step = 1; step < size; step++)
			{
				firstValue = values[step - 1];
				secondValue = values[step];
				if (secondValue < firstValue) { sorted = false; }
			}

			return sorted;
		}

		bool verifyArraySequencesDontMatch(int valuesOne[], int valuesTwo[], int size)
		{
			bool sequentiallyTheSame{ true };

			for (int i = 0; i < size; i++)
			{
				if (valuesOne[i] != valuesTwo[i]) { sequentiallyTheSame = false; }
			}

			return sequentiallyTheSame;
		}

		bool verifyUnchangedArray(std::map<int, int>& firstMap, std::map<int, int>& secondMap)
		{
			return firstMap == secondMap;
		}
	};
}
