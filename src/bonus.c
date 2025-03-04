#include "../include/so_long.h"

void	update_step_count(t_game_manager *mngr, int increment)
{
	static int	step_count = 0;
	char		*step_str;

	if (increment == 1)
		++step_count;
	step_str = ft_itoa(step_count);
	mlx_string_put(mngr->mlx, mngr->window, 20, 45, 0xFFFFFF, "STEP =>");
	mlx_string_put(mngr->mlx, mngr->window, 75, 45, 0xFFFFFF, step_str);
	free(step_str);
}

int	handle_enemy_movement(t_game_manager *mngr)
{
	int	random_direction;

	random_direction = rand() % 4;
	if (random_direction == 0)
		move_enemy(mngr, 0, -1);
	else if (random_direction == 1)
		move_enemy(mngr, 0, 1);
	else if (random_direction == 2)
		move_enemy(mngr, -1, 0);
	else
		move_enemy(mngr, 1, 0);
	return (0);
}
