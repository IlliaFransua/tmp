#include "constants.h"

int __calculate_visible_left(int *line) {
  int max_seen = 0;
  int visible_count = 0;

  for (int i = 0; i < GRID_SIZE; i++) {
    if (line[i] > max_seen) {
      max_seen = line[i];
      visible_count++;
    }
  }
  return visible_count;
}

int __calculate_visible_right(int *line) {
  int max_seen = 0;
  int visible_count = 0;

  for (int i = GRID_SIZE - 1; i >= 0; i--) {
    if (line[i] > max_seen) {
      max_seen = line[i];
      visible_count++;
    }
  }
  return visible_count;
}

int calculate_visible_towers(int *line, char view_by) {
  if (view_by == 'l')
    return __calculate_visible_left(line);
  if (view_by == 'r')
    return __calculate_visible_right(line);
  return 0;
}

int is_valid_vertical(int grid[GRID_SIZE][GRID_SIZE],
                      int heights[4][GRID_SIZE]) {
  for (int column = 0; column < GRID_SIZE; ++column) {
    int seen[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; ++i)
      seen[i] = 0;

    int column_towers[GRID_SIZE];

    for (int row = 0; row < GRID_SIZE; ++row) {
      int digit = grid[row][column];

      if (seen[digit - 1])
        return 0;
      seen[digit - 1] = 1;

      column_towers[row] = digit;
    }

    int column_up = heights[0][column];
    int column_down = heights[1][column];

    if (calculate_visible_towers(column_towers, 'l') != column_up ||
        calculate_visible_towers(column_towers, 'r') != column_down) {
      return 0;
    }
  }
  return 1;
}
