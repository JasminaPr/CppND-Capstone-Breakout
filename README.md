# CPPND: Capstone Breakout

This is a Cpp Nanodegree Capsone project. This project is a Breakout game based on [Udacity's Snake Game starter repo][https://github.com/udacity/CppND-Capstone-Snake-Game] with modifications inspired by [The Breakout Tutorial][https://rembound.com/articles/the-breakout-tutorial-with-cpp-and-sdl-2]. In short, backbone of the game loop structure is kept from Udacity's Snake Game starter repo, and actors (entities) are replaced to make it a Breakout Game. This project can also be checked out from GitHub [The Capstone Breakout Game][https://github.com/JasminaPr/CppND-Capstone-Breakout], where steps of the code development can be seen via commits.

Goal of the game is to destroy all the bricks by controlling the paddle via left and right arrow keys. The Bricks are destroyed once the ball hits them. The Ball is not allowed to pass the lower bottom of the screen point where it is not reachable by the paddle anymore. In this case the ball becomes unresponsive - game over.

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
4. Run it: `./Breakout`.

## Overview of the code structure

### Game loop
Code is structured into the main known "game loop": Input, Update and Render.
#### Input
Input is handled by getting the keys left and right arrow from the keyboard which moves the paddle.
#### Update
In each frame position of the ball and position of the paddle are updated. There are also checks whether there were any of the following collisions: paddle-ball colision, paddle-playing field edge colision, ball-playing field edge colision and finally ball-brick colision. In case the ball hits the lower edge of the playing field and goes beyond the reach of the paddle, ball is not alive anymore.
#### Render
Render renders each individual entity depending on the update in previous step.

### Entities in the game
Code is structured in Object-Oriented manner, therefore each entity is a class, with some of the additional classes.
#### Entity
Class entity is a parent class to all other actors in the playing filed. These include: ball, paddle, board with bricks.
#### Ball
Class Ball is a child class of class Entity. Position and dimensions memebers are gained from the parent class. There are also additional members and functions related to the ball, such as checking whether the ball has colided with the edges of the playing field.
#### Paddle
Paddle is also a child class of the class Entity. It is responsive to the user input via keyboard. Also contains other methods, such as checking whether the paddle has collided with the edges of the playing field.
#### Board
Exactly as Ball and Paddle, Board is also a child of the class Entity. Board contains predefined number of bricks. Goal of the game is to destroy all the bricks using Ball and Paddle.
#### Game
Class Game is inherited from the starter repo. Its function Run() contains main game loop functions - input, update and render.
#### Controller
Also inherited from starter repo, except that in this project it controls the Paddle. Paddle can move only in left or right direction.
#### Renderer
Renderer is also inherited from starter repo, it renders the playing field and main actors.

## Satisfying the necessary rubric

### Object Oriented Programming
#### Criteria: The project uses Object Oriented Programming tecniques.
Project is structred into classes. Besides the inherited "generic classes" such as game, renderer or controller, additional actors(entities) in the game are organized in a way that there is a parent class Entity from which following child classes are derived: Ball, Paddle, Board.
#### Criteria: Classes use appropriate access specifiers for class members. 
All members are specifically declared as public or private. There are also getters defined, such as getter to check whether the ball is alive. One example is defined in: ball.h, line 26. Called in: game.cpp, line 65.
#### Criteria: Class constructors utilize member initialization lists.
For class members which are not derived from parent class, member initialization lists are used. Example 1: game.cpp lines 8-10. Example 2: ball.cpp lines 3-5. Example 3: paddle.cpp line 4.
#### Criteria: Derived class functions overrride virtual base class functions.
Classes Ball, Paddle and Board override virtual function Update() declared in class Entity. Example 1: ball.h, line 21.

### Memory Management
#### The project makes use of references in function declarations.
In the constructor of the classes Game, Ball and Paddle there is a struct called displayParameters passed by reference. Struct DisplayParameters contains the inital display parameters so the ratio of the Ball and Paddle sizes compared to the screen size stays consistent with screen size changes. Additionally, paddle is passed by reference to the friend class Controller, where the position of the paddle is set. For reference check controller.cpp. 
#### The project uses destructors appropriately.
In the game.cpp, member board is defined as a pointer to class board. In the constructor of the class Game, memory is allocated using "new". Appropriately, memory is deallocated in the destructor of the class Game with "delete". For reference check game.cpp, lines 8-17.
