# cub3D

cub3D is my first RayCaster using miniLibX, inspired by the classic game Wolfenstein 3D. This project explores ray-casting techniques to create a dynamic first-person view inside a maze.

## Makefile

Makefile includes the following rules:

- `all`
- `clean`
- `fclean`
- `re`

## Arguments

The program accepts a map file in the format `*.cub`.

## External Functions

The program utilizes the following external functions:

- `open`, `close`, `read`, `write`
- `printf`, `malloc`, `free`
- All functions from the math library (`-lm`)
- All functions from the MiniLibX

## Description

The goal of the project is to create a realistic 3D graphical representation of a maze from a first-person perspective using Ray-Casting principles.

### Constraints

- **MiniLibX**: You must use the MiniLibX for graphical display, either the version available on the operating system or compiled from source.
- **Window Management**: The program must handle window events smoothly, such as minimizing and switching focus.
- **Wall Textures**: Different textures should be displayed on the walls based on their orientation (North, South, East, West).
- **Floor and Ceiling Colors**: The floor and ceiling must have different colors.
- **Controls**:
  - Left/Right arrow keys to look left/right in the maze.
  - W, A, S, D keys to move within the maze.
  - ESC key to close the window and quit the program.
  - Clicking the red cross on the window’s frame must also close the window and quit the program.
- **Scene File (.cub)**:
  - The first argument must be a `.cub` file, containing the scene description.
  - The map must consist of characters: `0` for empty space, `1` for a wall, and `N`, `S`, `E`, or `W` for the player's start position and orientation.
  - The map must be enclosed by walls, or the program should return an error.
  - The map must be parsed directly as it appears in the file.

### Example Scene Description File

```plaintext
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
11000001110101011111011110N0111
11111111 1111111 111111111111
```

### Error Handling

If any misconfiguration is encountered in the scene file, the program must exit and return "Error\n" followed by an explicit error message.

### How to Run

- Compile the program using the provided Makefile.
- Run the program with a valid .cub file as the first argument
- i.e ./cub3D map.cub
