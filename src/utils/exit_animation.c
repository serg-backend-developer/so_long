#include "../include/so_long.h"

int	exit_animation(t_game_manager *mngr)
{
	int			image_size;
	static int	frame_counter = 0;

	frame_counter += 1;
	if (frame_counter < 10)
		mngr->texture->exit = mlx_xpm_file_to_image(mngr->mlx, \
				"assets/textures/exit.xpm", &image_size, &image_size);
	else if (frame_counter < 20)
		mngr->texture->exit = mlx_xpm_file_to_image(mngr->mlx, \
				"assets/textures/exit2.xpm", &image_size, &image_size);
	else if (frame_counter < 30)
		mngr->texture->exit = mlx_xpm_file_to_image(mngr->mlx, \
				"assets/textures/exit3.xpm", &image_size, &image_size);
	if (frame_counter >= 30)
		frame_counter = 0;
	mlx_clear_window(mngr->mlx, mngr->window);
	render_map(mngr);
	update_step_count(mngr, 0);
	return (0);
}
