#include "constants.h"

void __backtracking(int *current, int *seen, int current_index,
                    int result[MAX_PERMS][GRID_SIZE], int *perm_count) {
  if (current_index == GRID_SIZE) {
    for (int i = 0; i < GRID_SIZE; i++) {
      result[*perm_count][i] = current[i];
    }
    *perm_count += 1;
    return;
  }

  for (int i = 0; i <= GRID_SIZE; i++) {
    if (seen[i])
      continue;

    seen[i] = 1;
    current[current_index] = i + 1;
    __backtracking(current, seen, current_index + 1, result, perm_count);
    seen[i] = 0;
  }
}

void __generate_all_possible_permutations(int result[MAX_PERMS][GRID_SIZE],
                                          int *perm_count) {
  int current[GRID_SIZE];
  int seen[GRID_SIZE];

  for (int i = 0; i < GRID_SIZE; i++)
    seen[i] = 0;

  *perm_count = 0;
  __backtracking(current, seen, 0, result, perm_count);
}

void generate_row_options(int heights[4][GRID_SIZE],
                          int all_row_options[GRID_SIZE][MAX_PERMS][GRID_SIZE],
                          int row_options_counts[GRID_SIZE]) {
  int all_possible_permutations[MAX_PERMS][GRID_SIZE];
  int permutation_count = 0;

  __generate_all_possible_permutations(all_possible_permutations,
                                       &permutation_count);

  for (int row = 0; row < GRID_SIZE; ++row) {
    int row_left = heights[2][row];
    int row_right = heights[3][row];
    row_options_counts[row] = 0;

    for (int perm_i = 0; perm_i < permutation_count; perm_i++) {
      int *permutation = all_possible_permutations[perm_i];
      if (calculate_visible_towers(permutation, 'l') == row_left &&
          calculate_visible_towers(permutation, 'r') == row_right) {

        for (int column = 0; column < GRID_SIZE; ++column) {
          all_row_options[row][row_options_counts[row]][column] =
              permutation[column];
        }
        ++row_options_counts[row];
      }
    }
  }
}
