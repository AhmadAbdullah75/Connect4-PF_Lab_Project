# Connect 4 - C++ Implementation

![Connect 4](https://img.shields.io/badge/Game-Connect%204-blue.svg)
![Language](https://img.shields.io/badge/Language-C++-orange.svg)

## Introduction
Connect Four (also known as Four Up, Plot Four, Find Four, Four in a Row, Four in a Line, Drop Four, and Gravitrips) is a classic two-player connection board game. Players choose a color and take turns dropping colored discs into a 7-column, 6-row vertically suspended grid. The pieces fall straight down, occupying the lowest available space within the column. 

The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs. 

## Features
This project implements the complete set of standard rules for Connect 4 in a console-based C++ environment:

- **Play Game:** 
  - Supports 2 players with custom names.
  - Initial coin toss to decide who goes first.
  - Interactive 6x7 grid printed to the console.
  - Validates moves (checks for full columns and valid inputs).
  - Automatically checks for win conditions (horizontal, vertical, forward diagonal, backward diagonal).
  - Automatically checks for draw conditions.
- **Credits:** View the developers who created the game.
- **Instructions:** Displays how to play the game and the rules.
- **Records:** Saves match outcomes and turns taken into a file (`file.txt`) for persistent tracking of the winner.
- **Exit:** Gracefully terminates the application.

## Prerequisites
- A C++ Compiler (e.g., GCC, Clang, or MSVC)
- Windows/Linux/MacOS terminal

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/AhmadAbdullah75/Connect4-PF_Lab_Project.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Connect4-PF_Lab_Project
   ```
3. Compile the code:
   ```bash
   g++ finalproject.cpp -o connect4
   ```
4. Run the executable:
   - On Windows: `connect4.exe`
   - On Linux/Mac: `./connect4`

## How to Play
1. Launch the game.
2. Select `Play` from the main menu by typing it.
3. Enter the names for Player 1 (Red) and Player 2 (Blue).
4. Perform the toss by selecting `head` or `tail`.
5. The board will be displayed. Players will take turns choosing a column (1-7) to drop their disc.
6. The game ends when a player gets 4 discs in a row or the board is full (Draw).

## Project Structure
- `finalproject.cpp`: Contains the main source code for the game, including game logic, board state management, and file I/O for records.
- `file.txt`: Generated dynamically. Stores the game history and records of who won.
- `23F-3027 23F-3001 23F-3035.pdf`: Project description and requirements document.

## Credits
Programmed by:
- Ahmad Abdullah
- Ayesha Noor
- Hashim Shaid

