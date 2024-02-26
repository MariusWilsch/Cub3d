# cub3D

## Project Overview

`cub3D` is a graphical project inspired by the classic game Wolfenstein 3D, the first First-Person Shooter (FPS). This project aims to explore the fundamentals of ray-casting and graphical design using the miniLibX library. The primary goal is to create a realistic 3D representation of a maze from a first-person perspective, allowing navigation through the maze with basic controls.

## Features

- **Ray-Casting**: Implements ray-casting to render a 3D maze from a first-person view.
- **Texture Management**: Supports different wall textures that vary depending on the wall's orientation (North, South, East, West).
- **Dynamic Colors**: Allows setting of floor and ceiling colors to enhance the 3D effect.
- **Control System**: Utilizes keyboard controls for navigation (WASD for movement and arrow keys) and Q for program exit.
- **Error Handling**: Robust error handling for file and input management, ensuring stability and user feedback.
- **MiniLibX Library**: Uses miniLibX for window management and graphic rendering, providing a smooth graphical experience.

## Installation

Clone the repository and compile the project using `Make`. Ensure you have the MLX42 library installed or available in your project directory.

```bash
make
```

## Running the Project

To run `cub3D`, execute the compiled program with a map file as its argument. The map file must follow the `.cub` format specified in the project guidelines.

```bash
./cub3D path_to_map.cub
```

## Controls

- **WASD**: Move through the maze.
- **Arrow Left/Right**: To rotate the player's view
- **Q**: Exit the program.

## Map Configuration

The map is defined in a `.cub` file with specific symbols representing walls, spaces, and the player's start position. Textures and colors are also defined in this file, following the project's specifications.
