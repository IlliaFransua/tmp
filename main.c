#include "constants.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		heights[4][GRID_SIZE];
	int		row_options[GRID_SIZE][MAX_PERMS][GRID_SIZE];
	int		row_options_count[GRID_SIZE];
	int		response[GRID_SIZE][GRID_SIZE];
	int		result;
	char	c;

	if (parse_heights(argc, argv, heights) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	generate_row_options(heights, row_options, row_options_count);
	result = find_answer(0, response, row_options, row_options_count, heights);
	if (!result)
	{
		write(1, "Error\n", 6);
	}
	else
	{
		for (int i = 0; i < GRID_SIZE; i++)
		{
			for (int j = 0; j < GRID_SIZE; j++)
			{
				c = response[i][j] + '0';
				write(1, &c, 1);
				if (j != GRID_SIZE - 1)
				{
					write(1, " ", 1);
				}
			}
			write(1, "\n", 1);
		}
	}
	return (0);
}
