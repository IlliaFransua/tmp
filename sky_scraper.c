#include "constants.h"

int find_answer(int row, int response[GRID_SIZE][GRID_SIZE],
                int row_options[GRID_SIZE][MAX_PERMS][GRID_SIZE],
                int row_options_count[GRID_SIZE], int heights[4][GRID_SIZE]) {
  if (row == GRID_SIZE) {
    return is_valid_vertical(response, heights);
  }

  for (int i = 0; i < row_options_count[row]; ++i) {
    for (int column = 0; column < GRID_SIZE; ++column) {
      response[row][column] = row_options[row][i][column];
    }

    if (find_answer(row + 1, response, row_options, row_options_count,
                    heights)) {
      return 1;
    }
  }
  return 0;
}
