#include "../include/so_long.h"

t_map_data	*initialize_map_data(char *filename)
{
	int			row_index;
	t_map_data	*map_data;

	map_data = malloc(sizeof(t_map_data));
	if (!map_data)
		exit(1);
	map_data->e = 0;
	map_data->p = 0;
	map_data->c = 0;
	map_data->m = 0;
	validate_file_extension(filename);
	validate_hidden_file(filename);
	validate_rectangle_map(map_data, filename);
	row_index = 0;
	while (row_index < map_data->map_x)
		if (map_data->map_y != ft_strlen(map_data->map[row_index++]))
			error_message("The map is not a rectangular!");
	if (map_data->map_x > 50 || map_data->map_y > 50)
		error_message("The map is too large!");
	validate_map_walls(map_data);
	return (map_data);
}
