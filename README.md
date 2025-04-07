# so_long - 42 Project
![so_long]((./img/so_long.gif))
## Introduction

**so_long** is a project at 42 that involves creating a simple 2D game where the player navigates through a grid-based map, collecting items and reaching an exit. The goal is to develop a game using basic graphical and game programming techniques, including handling user input, rendering graphics, and managing game state.

## Project Overview

The game includes:

- **Player Movement**: Navigate a player character through a map using keyboard inputs.
- **Map Loading**: Load and render a map from a file, where different tiles represent walls, floor, items, and the exit.
- **Game Objectives**: Collect items and reach the exit to complete the level.
- **Graphics**: Use a graphics library (like MinilibX) for rendering the game.

## Features

- **Map Design**: Define the game map with walls, floors, items, and exit points.
- **Player Control**: Move the player using the arrow keys or WASD.
- **Item Collection**: Collect items and update the game state.
- **Exit**: Reach the exit to win the game.

## Requirements

- **Graphics Library**: Use MinilibX or a similar library for rendering.
- **Map Format**: The map is defined in a text file with specific characters representing walls, floors, items, and the exit.

## Usage

1. Clone the repository and navigate to the project directory:

   ```bash
   git clone https://github.com/fclaus-g/so_long.git
   cd so_long
   ```

2. Compile the project using:

   ```bash
   make
   ```

3. Run the game with a map file:

   ```bash
   ./so_long path/to/map.ber
   ```

   Replace `path/to/map.ber` with the path to your map file.

## Example

1. Create a map file `map.ber` with content like:

   ```
   1111
   1P01
   1C01
   1E11
   ```

   - `1` represents walls.
   - `0` represents floors.
   - `P` represents the player.
   - `C` represents collectibles.
   - `E` represents the exit.

2. Run the game with:

   ```bash
   ./so_long map.ber
   ```

   Use the arrow keys or WASD to move the player.

## License

This project is part of the 42 curriculum and is intended for educational purposes. Feel free to use it for learning, but be mindful of 42’s collaboration policies.
