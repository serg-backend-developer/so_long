#include "../include/so_long.h"

int	update_player_position(
	t_game_manager *mngr, int row, int col, char *i_path)
{
	int	i_w;
	int	i_h;

	if (check_exit_and_move(mngr, row, col) == 2)
		return (0);
	if (mngr->map->map[mngr->chr->i_w + \
			row][mngr->chr->i_h + col] == 'M')
		exit_game("The enemy killed you!");
	if (mngr->map->map[mngr->chr->i_w + \
			row][mngr->chr->i_h + col] == '0'
		|| mngr->map->map[mngr->chr->i_w + \
			row][mngr->chr->i_h + col] == 'C')
	{
		mngr->map->map[mngr->chr->i_w + \
			row][mngr->chr->i_h + col] = 'P';
		mngr->map-> \
			map[mngr->chr->i_w][mngr->chr->i_h] = '0';
		if (row == 0)
			mngr->texture->chr = \
				mlx_xpm_file_to_image(mngr->mlx, i_path, &i_w, &i_h);
		handle_enemy_movement(mngr);
		refresh_displayed_map(mngr, 1);
	}
	return (0);
}
