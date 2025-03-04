#include "../include/so_long.h"

void	render_map(t_game_manager *mngr)
{
	int	coordinate[2];
	int	collectible_count;
	int	row_index;
	int	col_index;

	row_index = -1;
	collectible_count = 0;
	coordinate[1] = 0;
	while (++row_index < mngr->map->map_x)
	{
		col_index = -1;
		coordinate[0] = 0;
		while (mngr->map->map[row_index][++col_index] != '\0')
		{
			render_map_tile(mngr, mngr-> \
				map->map[row_index][col_index],
				coordinate, &collectible_count);
			render_character_image(mngr, row_index, col_index, coordinate);
			coordinate[0] += 50;
		}
		coordinate[1] += 50;
	}
	mngr->chr->is_finished = 0;
	if (collectible_count == 0)
		mngr->chr->is_finished = 1;
}

void	render_map_tile(t_game_manager *mngr, char tile_type,
	int *coordinate, int *collectible_count)
{
	if (tile_type == '1')
		mlx_put_image_to_window(
			mngr->mlx, mngr->window, mngr->texture->wall,
			coordinate[0], coordinate[1]);
	else if (tile_type == '0')
		mlx_put_image_to_window(
			mngr->mlx, mngr->window, mngr->texture->floor,
			coordinate[0], coordinate[1]);
	else if (tile_type == 'C')
	{
		mlx_put_image_to_window(
			mngr->mlx, mngr->window, mngr->texture->collectible,
			coordinate[0], coordinate[1]);
		*collectible_count += 1;
	}
	else if (tile_type == 'E')
		mlx_put_image_to_window(
			mngr->mlx, mngr->window, mngr->texture->exit,
			coordinate[0], coordinate[1]);
}

int	check_exit_and_move(t_game_manager *mngr, int i_w, int i_h)
{
	if (mngr->map->map[mngr->chr->i_w][mngr->chr->i_h] == 'X'
		&& mngr->map->map[mngr->chr->i_w + \
			i_w][mngr->chr->i_h + i_h] != '1')
	{
		mngr->map->map[mngr->chr->i_w][mngr->chr->i_h] = 'E';
		mngr->map->map[mngr->chr->i_w + i_w][mngr->chr->i_h + i_h] = 'P';
		handle_enemy_movement(mngr);
		refresh_displayed_map(mngr, 1);
		return (2);
	}
	if (mngr->map->map[mngr->chr->i_w + i_w][mngr->chr->i_h + i_h] == 'E')
	{
		mngr->map->map[mngr->chr->i_w][mngr->chr->i_h] = '0';
		mngr->map->map[mngr->chr->i_w + i_w][mngr->chr->i_h + i_h] = 'X';
		refresh_displayed_map(mngr, 1);
		handle_enemy_movement(mngr);
		if (mngr->chr->is_finished == 1)
		{
			ft_printf("Game Over! See you soon!");
			exit(0);
		}
		return (2);
	}
	return (0);
}

t_game_manager	*load_images(t_game_manager *mngr)
{
	int	image_width;
	int	image_height;

	mngr->texture = malloc(sizeof(t_textures));
	mngr->texture->floor = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/floor.xpm", &image_width, &image_height);
	mngr->texture->wall = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/wall.xpm", &image_width, &image_height);
	mngr->texture->collectible = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/collectible.xpm", &image_width, &image_height);
	mngr->texture->chr = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/player1.xpm", &image_width, &image_height);
	mngr->texture->chr = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/player2.xpm", &image_width, &image_height);
	mngr->texture->exit = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/exit.xpm", &image_width, &image_height);
	mngr->texture->exit = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/exit2.xpm", &image_width, &image_height);
	mngr->texture->exit = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/exit3.xpm", &image_width, &image_height);
	mngr->texture->enemy = mlx_xpm_file_to_image(mngr->mlx,
			"assets/textures/enemy.xpm", &image_width, &image_height);
	return (mngr);
}
