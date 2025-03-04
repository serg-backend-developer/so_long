#include "../include/so_long.h"

int	handle_key_input(int keycode, t_game_manager *mngr)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 0)
		move_player_left(mngr);
	else if (keycode == 1)
		move_player_down(mngr);
	else if (keycode == 2)
		move_player_right(mngr);
	else if (keycode == 13)
		move_player_up(mngr);
	return (0);
}

int	exit_game(char *message)
{
	if (message)
		ft_printf("%s\n", message);
	exit(0);
}
