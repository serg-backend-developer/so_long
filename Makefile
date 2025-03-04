NAME            =   so_long

SRC             =   src/
HANDLERS		=	src/handlers/
MAP				=	src/map/
UTILS			=	src/utils/
OBJ             =   obj/
INCLUDE         =   include/
GCC             =   gcc
CFLAGS          =   -Wall -Werror -Wextra -I$(INCLUDE)
RM              =   rm -f

LIB             =   ./minilibx/libmlx.a
MLX_FLAGS       =   -L ./minilibx -lmlx -framework OpenGL -framework AppKit

FILES           =   $(SRC)main.c \
                    $(SRC)bonus.c \
                    $(HANDLERS)handler_errors.c \
                    $(HANDLERS)handler_image.c \
                    $(HANDLERS)handler_logic.c \
					$(HANDLERS)handler_movement.c \
					$(HANDLERS)handler_rectangle.c \
					$(HANDLERS)handler_wall.c \
					$(MAP)map_refresh.c \
					$(MAP)map_validation.c \
					$(MAP)map_checking.c \
					$(UTILS)utils_input_and_exit.c \
					$(UTILS)utils_bonus.c \
                    $(UTILS)exit_animation.c \
                    $(UTILS)flood_fill.c \
					$(UTILS)utils_image.c \
					libs/get_next_line/get_next_line_utils.c \
					libs/get_next_line/get_next_line.c \
					libs/ft_printf.c

OBJS            =   $(patsubst $(SRC)%.c,$(OBJ)%.o,$(FILES))

all: $(NAME)

$(LIB):
				@echo "Compiling MinilibX library"
				@make -C ./minilibx

$(NAME): $(OBJS) $(LIB)
				@$(GCC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIB) -o $(NAME)

$(OBJ)%.o: $(SRC)%.c
				@mkdir -p $(@D)
				@$(GCC) $(CFLAGS) -c $< -o $@

clean:
				@echo "Cleaning o-files ..."
				@$(RM) -r $(OBJ)
				@make clean -C ./minilibx

fclean: clean
				@echo "Cleaning so_long file ..."
				@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
