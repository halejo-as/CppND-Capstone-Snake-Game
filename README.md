# NEW FEATURES FOR SNAKE
## For the capstone project c++ udacity

* Selection the number of players (1 or 2)
* Change the quantity of food into the board with the variable foodMax
* Add names to the players
* Display the winner of the game at the end

## Behavior Program

At the start you should write the number of players 1 or 2 
After enter the name for each player

The player 1 play with (arrow) 
The player 2 play with (w, a ,s d) keys

The number of food is default 3, you should be watch 3 squared
yellow each time into the board

At the end is showed the score and the winner of the game

## RUBRIC

### LOOPS, FUNCTIONS, I/O

* Accept the entry of the number of players
* The name of each player could be enter at the begging

### OOP

* Created class Player to encapsuled the snake and the controller
  and other attributes like name and score

### MEMOMRY MANAGEMENT

* Used of shared ptr to be able to recuperate information after
  the display is closed

### CONCURRENCY

* Used async to execute the handle of each controller



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distrosor(i=0;i<3;i++)
  {
    r
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
