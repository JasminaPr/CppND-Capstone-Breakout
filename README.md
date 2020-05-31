# CPPND: Capstone Breakout

This is a Cpp Nanodegree Capsone project. This project is a Breakout game based on [Udacity's Snake Game starter repo][https://github.com/udacity/CppND-Capstone-Snake-Game] with modifications inspired by [The Breakout Tutorial][https://rembound.com/articles/the-breakout-tutorial-with-cpp-and-sdl-2]. In short, backbone of the game loop structure is kept from Udacity's Snake Game starter repo, and actors (entities) are replaced to make it a Breakout Game. This project can also be checked out from GitHub [The Capstone Breakout Game][https://github.com/JasminaPr/CppND-Capstone-Breakout], where steps of the code development can be seen via commits.

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
Code is structured into the main known loop: Input, Update and Render.
* Input is handled by getting the keys left and right arrow from the keyboard which moves the paddle.
* Update in each frame updates position of the ball, position of the paddle and checks whether there were any of the following collisions: paddle-ball colision, paddle-playing field edge colision, ball-playing field edge colision and finally ball-brick colision. In case ball hits the lower edge of the playing field and goes beyond the reach of the paddle, ball is set to not alive anymore.
* Render renders each individual entity depending on the update in previous step.

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
Class Game is inherited from the starter repo. IIts function Run() contains main game loop functions - input, update and render.
#### Controller
Also inherited from starter repo, except that in this project it controls the Paddle. Paddle can move only in left or right direction.
#### Renderer
Renderer is also inherited from starter repo, it renders the playing field and main actors.

### Satisfying the necessary rubric
