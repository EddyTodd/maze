# maze

c++ library for maze generation

## Maze Generation Algorithms

In order to build a maze, an algorithm is needed. The following algorithms are implemented in this library, each with their own flaws and strengths.

### Sidewinder

 1. Join all cells in the top row.
 2. Move to the next row.
 3. Randomly connect horizontally adjacent cells.
 4. Connect a random cell from each group to the above row.
 5. Repeat steps 2 - 4 until you processed the bottom row.

### Wilson

 1. Start with one cell as part of the maze.
 2. Choose a cell that is not connected to the maze.
 3. Create a random path from that cell.
 4. If you cross a cell that is already on that path, remove the loop from the path.
 5. If you cross a cell that is already part of the maze, join that path to the maze.
 6. Repeat steps 2 - 5 until there are no unconnected cells.

### Recursive Division

 1. Create a wall dividing the maze with a single passage through the wall.
	 - If the width is bigger than the height, do a vertical division.
	 - If the height is bigger than the width, do a horizontal division.
	 - If the width and the height are the same, do either a horizontal or vertical division.
 2. Repeat step 1 recursively on each side of the wall until the wall's length completely shrinks.

### Recursive Backtracker

1. Select a random starting point.
2. Randomly choose an adjacent cell.
3. If the new cell is not part of the maze, create a connection between them.
4. If all adjacent cells are already part of the maze, move back to the most recent cell that has an adjacent unvisited cell.
5. Repeat steps 2 - 4 until there are no adjacent unvisited cells.

### Random Fusion

 1. Choose any 2 adjacent cells.
 2. If there's not a connection between both cells (either direct or through another path), join the cells.
 3. If there's a connection, do nothing.
 4. Repeat steps 1 - 3 until all cells are connected.
