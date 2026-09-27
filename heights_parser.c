#include "constants.h"

int parse_heights(int argc, char **argv, int heights[4][GRID_SIZE]) {
  if (argc != 2)
    return 0;

  char *str = argv[1];
  int arg_type_count = 0;
  int arg_type_index_count = 0;
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] == ' ') {
      i++;
      continue;
    }
    if (!('0' <= str[i] && str[i] <= '9'))
      return 0;

    int number = str[i] - '0';

    if (number < 1 || number > GRID_SIZE)
      return 0;

    if (arg_type_index_count == GRID_SIZE) {
      ++arg_type_count;
      arg_type_index_count = 0;
    }
    if (arg_type_count == 4) {
      return 0;
    }
    heights[arg_type_count][arg_type_index_count] = number;
    ++arg_type_index_count;
    ++i;
  }

  if (arg_type_count != 3 || arg_type_index_count != GRID_SIZE)
    return 0;

  return 1;
}
