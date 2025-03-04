#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "../minilibx/mlx.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct s_map_data
{
	int		map_x;
	int		map_y;
	int		c;
	int		e;
	int		p;
	int		m;
	int		player_row;
	int		player_col;
	char	**map;
}			t_map_data;

typedef struct s_textures
{
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*chr;
	void	*exit;
	void	*enemy;
}			t_textures;

typedef struct s_character
{
	int	i_w;
	int	i_h;
	int	x;
	int	y;
	int	is_finished;
}		t_character;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_enemy
{
	int	row_offset;
	int	col_offset;
}		t_enemy;

typedef struct s_game_manager
{
	void		*mlx;
	void		*window;
	t_character	*chr;
	t_textures	*texture;
	t_map_data	*map;
	t_enemy		*enemy;
}				t_game_manager;

char			**create_map_clone(t_map_data *map);
void			error_message(char *message);
void			fill(char **tab, t_point size, t_point cur, char to_fill);
void			flood_fill(
					char **map_clone, t_point map_size, t_point start_point);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
void			ft_printf(const char *str, ...);
char			*ft_itoa(int n);
void			move_player_left(t_game_manager *mngr);
void			move_player_right(t_game_manager *mngr);
void			move_player_up(t_game_manager *mngr);
void			move_player_down(t_game_manager *mngr);
void			refresh_displayed_map(t_game_manager *mngr, int i);
void			render_map(t_game_manager *mngr);
void			render_character_image(
					t_game_manager *mngr,
					int row_offset,
					int col_offset,
					int *coordinates);
void			render_map_tile(t_game_manager *mngr, char tile_type,
					int *coordinate, int *collectible_count);
void			parse_args(va_list lst, char c);
void			validate_hidden_file(char *filename);
void			validate_file_extension(char *filename);
void			validate_map_walls(t_map_data *map_data);
void			validate_map_element(t_map_data *map_data, int row, int col);
void			validate_reachability(t_map_data *map_data, char **map_clone);
void			validate_map(t_map_data *map_data);
void			update_step_count(t_game_manager *mngr, int increment);
int				check_exit_and_move(
					t_game_manager *mngr, int row_offset, int col_offset);
int				exit_animation(t_game_manager *mngr);
int				exit_game(char *message);
int				handle_enemy_movement(t_game_manager *mngr);
int				handle_key_input(int keycode, t_game_manager *stc);
int				move_enemy(
					t_game_manager *mngr, int row_offset, int col_offset);
int				update_player_position(t_game_manager *mngr, int row_offset,
					int col_offset, char *player_image_path);
t_map_data		*initialize_map_data(char *filename);
t_map_data		*validate_rectangle_map(t_map_data *map, char *filename);
t_game_manager	*load_images(t_game_manager *mngr);

#endif
