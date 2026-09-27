#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <stdlib.h>
# include <unistd.h>

# define GRID_SIZE 4
# define MAX_PERMS 24

void	generate_row_options(int heights[4][GRID_SIZE],
			int all_row_options[GRID_SIZE][MAX_PERMS][GRID_SIZE],
			int row_options_counts[GRID_SIZE]);

int		parse_heights(int argc, char **argv, int heights[4][GRID_SIZE]);

int		calculate_visible_towers(int *line, char view_by);

int		is_valid_vertical(int grid[GRID_SIZE][GRID_SIZE],
			int heights[4][GRID_SIZE]);

int		find_answer(int row_index, int grid[GRID_SIZE][GRID_SIZE],
			int row_options[GRID_SIZE][MAX_PERMS][GRID_SIZE],
			int row_options_count[GRID_SIZE], int heights[4][GRID_SIZE]);

void	ft_putstr(char *str);

#endif
