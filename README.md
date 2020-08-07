# (Marwan Abdellattif) CPPND: Capstone Snake Game

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Code Structure and Editions:

The work done in this project covers most of the Nanodegree contents. The added functionalities are mainly in three calsses which are:
### Player class in player_data.h :
    - Creates a profile for the new player which contains the following data:
        1. Name
        2. Score
        3. Level of Difficulty
    - The class has or utilizes the following:
        * Setters/Getters
        * list intializers.
        * rule of five.
        * operator overloading.
        * Encapsulation & Abstraction. 
### History class in game_history.h:
    - Saves the Hall of Fame, the top 10 players of all time in a (Hall_of_Fame.txt) file. 
    - Gives the option to sort the players based on their scores.
    - Gives the option to display the history with different choices such as:
        * Display the list based on date of playing. 
        * Display  the list sorted by high score.
        * Display the highest score.
        * Display the lowest score.
    - The History class has or utilizes the following:
        * Composition
        * shared_pointers
        * memory allocation on the heap. 
        * move semantics. 
        * lambda function
### ProfileManager class in game_settings.h: 
    - Visualizes the main menu to the user. 
    - manages the input/output.
    - Gives the option to play in different game modes.

## Game Settings: 
The player can change the settings of the game he can play in two modes:
- Different Theme: 
* Changes the head to orange , the body to green and the food to fuschia. 
- Higher difficulty:
* can play in level one with no obstacles and regular speed. 
* can play in level 2 with randomly placed obstacles and higher speed.

## Rubric Points Addressed

### Loops, Functions, I/O
|Criteria| Addressed(Yes/No)|
|--------|------------|
The project demonstrates an understanding of C++ functions and control structures. == Yes, All the src files contains or consists of this rubric. |YES
The project reads data from a file and process the data, or the program writes data to a file. == Yes, The class History in game_history.h read/write txt files. |YES
The project accepts user input and processes the input. == Yes, this is demonstrated in the main.cpp where the user has up to 9 options to choose from the main menu. |YES

### Object Oriented Programming
|Criteria| Addressed(Yes/No)|
|--------|------------|
The project uses Object Oriented Programming techniques. == Yes, all the functionalities/files are written using OOP techniques.|YES
Classes use appropriate access specifiers for class members. == Yes, all classes have their getters/setters when needed. for instance the Player class has GetName, SetName methods.|YES
Class constructors utilize member initialization lists. == Yes, it is shown in Player class and several other classes.|YES
Classes abstract implementation details from their interfaces.== Yes.|YES
Classes encapsulate behavior. == Yes, and this is represented by having all the functions belongong for a certain class to be defined in that class's `.h` file.|YES


### Memory Management
|Criteria| Addressed(Yes/No)|
|--------|------------|
Classes abstract implementation details from their interfaces. == Yes. |YES
The project uses destructors appropriately. == Yes, and it is shown in the Player class.|YES
The project follows the Rule of 5. == Yes, and this is represented in the Player Class. |YES
The project uses smart pointers instead of raw pointers. == Yes, this is described in the game_history.h file where shared pointers are used.|YES
The project uses move semantics to move data, instead of copying it, where possible. == Yes, the Player data moves from the source and pushed in the players vector.|YES
The project makes use of references in function declarations. == Yes. |YES
