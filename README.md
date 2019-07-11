# b3rb's Text Based Roguelike
***A text based roguelike adventure game written in pure C***

## Compiling:
* Building has only been tested on Linux with the gcc compiler and on Windows with mingw32.
* The only dependencies are the ncurses library (Linux), and the PDCurses library (Windows).
* To compile for Windows, run 'make WIN=Y' instead of the standard 'make' command.

## Levels:
* Levels are currently plain text files containing the map.
* the '.' and '#' characters are passable by the player and everything else is solid.
* When designing levels, tabs should not be used as they can be inconsistent depending on the user's terminal settings.

## Contributing:
* Follow the coding style present throughout this program.
* Use tabs, not spaces.
* The code is intended to be viewed with a tabspace of 2.
