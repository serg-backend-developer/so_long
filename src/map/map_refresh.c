#include "../include/so_long.h"

void	refresh_displayed_map(t_game_manager *mngr, int i)
{
	mlx_do_sync(mngr->mlx);
	mlx_clear_window(mngr->mlx, mngr->window);
	render_map(mngr);
	if (i == 1)
		update_step_count(mngr, 1);
	else
		update_step_count(mngr, 0);
}
