#include "../include/so_long.h"

void	validate_map_walls(t_map_data *map_data)
{
	int	row;
	int	col;

	row = -1;
	while (++row < map_data->map_x)
	{
		col = -1;
		while (map_data->map[row][++col])
			validate_map_element(map_data, row, col);
	}
	if (map_data->p != 1 || map_data->e != 1 || \
			map_data->c < 1 || map_data->m != 1)
		error_message("SMTH WRONG WITH MAP!");
}

void	validate_map_element(t_map_data *map_data, int row, int col)
{
	if ((map_data->map[0][col] != '1' || map_data->map[row][0] != '1'
		|| map_data->map[row][map_data->map_y - 1] != '1'
		|| map_data->map[map_data->map_x - 1][col] != '1')
		|| (map_data->map[row][col] != '0' && map_data->map[row][col] != '1'
		&& map_data->map[row][col] != 'C' && map_data->map[row][col] != 'P'
		&& map_data->map[row][col] != 'E' && map_data->map[row][col] != 'M'))
		error_message("The map uses strange symbols! Check them!");
	if (map_data->map[row][col] == 'E')
		map_data->e += 1;
	else if (map_data->map[row][col] == 'C')
		map_data->c += 1;
	else if (map_data->map[row][col] == 'M')
		map_data->m += 1;
	else if (map_data->map[row][col] == 'P')
	{
		map_data->p += 1;
		map_data->player_row = row;
		map_data->player_col = col;
	}
}
