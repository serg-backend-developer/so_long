#include "../include/so_long.h"

void	move_player_up(t_game_manager *mngr)
{
	update_player_position(mngr, -1, 0, "assets/textures/player1.xpm");
}

void	move_player_down(t_game_manager *mngr)
{
	update_player_position(mngr, 1, 0, "assets/textures/player1.xpm");
}

void	move_player_left(t_game_manager *mngr)
{
	update_player_position(mngr, 0, -1, "assets/textures/player2.xpm");
}

void	move_player_right(t_game_manager *mngr)
{
	update_player_position(mngr, 0, 1, "assets/textures/player1.xpm");
}
