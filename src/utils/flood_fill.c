#include "../include/so_long.h"

void	fill(
	char **map_clone, t_point map_size, t_point start_point, char to_fill)
{
	if (start_point.y < 0 || start_point.y >= map_size.y
		|| start_point.x < 0 || start_point.x >= map_size.x
		|| map_clone[start_point.y][start_point.x] == to_fill)
		return ;
	map_clone[start_point.y][start_point.x] = '1';
	fill(map_clone, map_size,
		(t_point){start_point.x - 1, start_point.y}, to_fill);
	fill(map_clone, map_size,
		(t_point){start_point.x + 1, start_point.y}, to_fill);
	fill(map_clone, map_size,
		(t_point){start_point.x, start_point.y - 1}, to_fill);
	fill(map_clone, map_size,
		(t_point){start_point.x, start_point.y + 1}, to_fill);
}

void	flood_fill(char **map_clone, t_point map_size, t_point start_point)
{
	fill(map_clone, map_size, start_point, '1');
}
