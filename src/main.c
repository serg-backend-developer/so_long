#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_game_manager	*mngr;

	if (argc != 2)
		error_message("Oops! Incorrect number of arguments.");
	mngr = malloc(sizeof(t_game_manager));
	mngr->chr = malloc(sizeof(t_character));
	mngr->enemy = malloc(sizeof(t_enemy));
	mngr->mlx = mlx_init();
	mngr->map = initialize_map_data(argv[1]);
	validate_map(mngr->map);
	mngr->window = mlx_new_window(mngr->mlx, mngr->map->map_y * 50,
			mngr->map->map_x * 50, "*** so_long project ***");
	mngr = load_images(mngr);
	render_map(mngr);
	mlx_hook(mngr->window, 2, 1L << 0, handle_key_input, mngr);
	mlx_hook(mngr->window, 17, 0L, exit_game, NULL);
	mlx_loop_hook(mngr->mlx, exit_animation, mngr);
	mlx_loop(mngr->mlx);
	return (0);
}
