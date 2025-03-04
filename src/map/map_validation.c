#include "../include/so_long.h"

char	**create_map_clone(t_map_data *map_data)
{
	char	**map_clone;
	int		row;
	int		col;

	row = 0;
	map_clone = malloc(sizeof(char **) * map_data->map_x);
	while (row < map_data->map_x)
	{
		col = 0;
		map_clone[row] = malloc(sizeof(char *) * map_data->map_y);
		while (col < map_data->map_y)
		{
			map_clone[row][col] = map_data->map[row][col];
			if (map_data->map[row][col] == 'P' || map_data->map[row][col] == 'E'
				|| map_data->map[row][col] == 'M')
				map_clone[row][col] = '0';
			col++;
		}
		row++;
	}
	return (map_clone);
}

void	validate_reachability(t_map_data *map_data, char **map_clone)
{
	int	row;
	int	col;

	row = 0;
	while (row < map_data->map_x)
	{
		col = 0;
		while (col < map_data->map_y)
		{
			if (map_clone[row][col] == 'C')
				error_message("Something wrong with your map! \
				Check all icons on the map!");
			col++;
		}
		free(map_clone[row]);
		row++;
	}
	free(map_clone);
}

void	validate_map(t_map_data *map_data)
{
	char	**map_clone;
	t_point	map_size;
	t_point	start_point;

	map_size.x = map_data->map_y;
	map_size.y = map_data->map_x;
	start_point.x = map_data->player_col;
	start_point.y = map_data->player_row;
	map_clone = create_map_clone(map_data);
	flood_fill(map_clone, map_size, start_point);
	validate_reachability(map_data, map_clone);
}
