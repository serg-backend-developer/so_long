#include "../include/so_long.h"

void	render_character_image(
		t_game_manager *mngr,
		int row_offset,
		int col_offset,
		int *coordinates)
{
	if (mngr->map->map[row_offset][col_offset] == 'P' || \
			mngr->map->map[row_offset][col_offset] == 'X')
	{
		mlx_put_image_to_window(mngr->mlx, mngr->window,
			mngr->texture->chr, coordinates[0], coordinates[1]);
		mngr->chr->i_w = row_offset;
		mngr->chr->i_h = col_offset;
		mngr->chr->x = coordinates[0];
		mngr->chr->y = coordinates[1];
	}
	if (mngr->map->map[row_offset][col_offset] == 'M')
	{
		mlx_put_image_to_window(mngr->mlx, mngr->window,
			mngr->texture->enemy, coordinates[0], coordinates[1]);
		mngr->enemy->row_offset = row_offset;
		mngr->enemy->col_offset = col_offset;
	}
}

int	move_enemy(
		t_game_manager *mngr,
		int row_offset,
		int col_offset)
{
	if (mngr->map->map[mngr->enemy->row_offset + \
			row_offset][mngr->enemy->col_offset + col_offset] != '1'
		&& mngr->map->map[mngr->enemy->row_offset + \
			row_offset][mngr->enemy->col_offset + col_offset] != 'P'
		&& mngr->map->map[mngr->enemy->row_offset + \
			row_offset][mngr->enemy->col_offset + col_offset] != 'E'
		&& mngr->map->map[mngr->enemy->row_offset + \
			row_offset][mngr->enemy->col_offset + col_offset] != 'C'
		&& mngr->map->map[mngr->enemy->row_offset + \
			row_offset][mngr->enemy->col_offset + col_offset] != 'X')
	{
		mngr->map->map[mngr->enemy->row_offset + \
			row_offset][mngr->enemy->col_offset + col_offset] = 'M';
		mngr->map-> \
		map[mngr->enemy->row_offset][mngr->enemy->col_offset] = '0';
		refresh_displayed_map(mngr, 0);
	}
	return (0);
}
