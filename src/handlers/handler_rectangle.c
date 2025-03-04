#include "../include/so_long.h"

t_map_data	*validate_rectangle_map(t_map_data *map, char *filename)
{
	int		row_index;
	int		fd;
	char	*line;

	row_index = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_message("I can not open your map!");
	line = get_next_line(fd);
	if (!line)
		error_message("Oops! The map is EMPTY!");
	map->map = malloc(sizeof(char *) * (ft_strlen(line) + 1));
	if (!map->map)
		error_message("Oops! Where is the memory?");
	while (line)
	{
		map->map[row_index++] = line;
		line = get_next_line(fd);
	}
	map->map_x = row_index;
	map->map_y = ft_strlen(map->map[0]);
	return (map);
}
