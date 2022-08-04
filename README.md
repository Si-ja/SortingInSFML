# Sorting Algorithms with SFML

## The idea

The idea of the project is to prepare a small setup, that uses SFML 2 for visualizing how sorting algorithms operate. SFML allows for a quite easy manipulation
of objects through C++ to be displayed in a GUI style environment (though it's more of a videogame type window).

## Points of interest

### Controls

The project is setup to use the most basic aspects of SFML, such as ability to visualize data, use text values, produce sounds and accept user inputs
in order for the user to be able to interact with the sorting algorithms. Controls are the following and hopefully can be deducted from the opened
game window as is too:

* `Left` and `Right` controls should allow the user to change the amount of values they wish to see be sorted.
* `Up` and `Down` can allow the user to chose the sorting function that can be applied to sorting.
* `Spacebar` allows the user to stop or start the sorting process.

All of the said functions can be selected in real time, meaning the sorting function used can be changed in real time. However, if the amount of elements
that are sorted is changed - the values will be randomized and sorting will start from scratch.

### How the sorting functions are setup

The sorting functions are setup in a style that they perform a return call, everytime even a single value in an array of random values (represented via
a histogram like table) changes places with another. A loop is performed, that checks whether such action was sufficient to sort an array. Consequently,
the user sees the array update with 1 steps of sorting taking place (it's not ideal, but close enough to what is being conveyed). If the array hasn't been
fully sorted, the sorting continues.

If you will add your own sorting functions, do consier this caveat.

## Limitations

This repository has only the basic code on how to run the aforementioned project. However, it does not show the files for the final build, or the
various dll files that have been used when setting up the SFML. This unfortunatelly will have to be taken care by the next user who will take this
project for own use or experementation.

`Note:` HOWVER! You can find a simple executable in the exe folder. This setup should be sufficient with the Font folder to get you up and
running to just try the applciation out.

## Visualizations

Couple of examples on how the project works currently:

![alt text](https://github.com/Si-ja/Sorting-Algorithms-with-SFML/blob/main/Visuals/IDLEstate.png "IDLE State")

![alt text](https://github.com/Si-ja/Sorting-Algorithms-with-SFML/blob/main/Visuals/SortingHappening.png "Sorting Happening")

![alt text](https://github.com/Si-ja/Sorting-Algorithms-with-SFML/blob/main/Visuals/SortingChangedMidWay.png "Sorting Changed Mid Way")