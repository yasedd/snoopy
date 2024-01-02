# Snoopy's Bird Hunt Game

## Overview
Snoopy's Bird Hunt Game is a console-based game implemented in C. The objective of the game is to control Snoopy and catch all the birds within a time limit, while avoiding collisions with a bouncing ball.

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Gameplay](#gameplay)
- [Rules](#rules)
- [Screenshots](#screenshots)
- [Acknowledgments](#acknowledgments)

## Description
This game provides a basic console environment with a map, Snoopy, birds, and a bouncing ball. The player can move Snoopy using the 'w', 'a', 's', and 'd' keys to catch birds while avoiding collisions with the ball. The game includes a time limit, and the player must complete the objective within that time.

## Instructions
1. **Clone the Repository:**
    ```bash
    git clone https://github.com/your-username/snoopy-bird-hunt.git
    ```

2. **Compile the Code:**
    ```bash
    gcc snoopy.c -o snoopy.exe
    ```

3. **Run the Executable:**
    ```bash
    ./snoopy.exe
    ```

4. **Controls:**
   - `w`: Move Snoopy up
   - `a`: Move Snoopy left
   - `s`: Move Snoopy down
   - `d`: Move Snoopy right
   - `c`: Stop the game

## Gameplay
- Snoopy is represented by 'S' and can be moved around the map.
- The goal is to catch all the birds represented by 'B' before time runs out.
- The bouncing ball, represented by 'O', adds an element of challenge. If Snoopy collides with the ball, the game ends.
- Press 'c' at any time to stop the game.

## Rules
- The game has a time limit, and the player must catch all the birds within that time.
- Snoopy and the ball move within the boundaries of the map.
- The game stops if Snoopy collides with the ball or time runs out.

## Screenshots
![Gameplay](screenshots/gameplay.png)

## Acknowledgments
This game is a simple project created for fun and learning purposes. It utilizes basic C programming concepts and is inspired by classic console games.

Feel free to contribute, report issues, or provide suggestions to enhance the game!
