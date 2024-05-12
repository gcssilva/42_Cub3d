##########################################################
#					Instructions						 #
##########################################################

NAME =  cub3D
CFLAGS =  -Werror -Wall -Wextra #-g -fsanitize=address 
CC = cc 
UNAME := $(shell uname)

##########################################################
#					SOURCES AND OBJS					 #
##########################################################

SRCS =	src/main.c src/parse/parse_map.c src/parse/parse_el.c src/parse/parse_path.c src/parse/map_utils.c src/parse/parse_utils.c \
		src/image/image.c src/game/ray_cast.c src/game/init_vars.c src/game/utils.c src/game/hooks.c \
		src/game/utils2.c src/game/close_game.c

OBJS :=$(SRCS:.c=.o)

##########################################################
#					CODIGOS ANSI						 #
##########################################################


CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CLEARBLUE	= \033[1;94m
CYAN 		= \033[1;36m
PURPLE		= \033[1;35m
WHITE 		= \033[1;37m
BLACK 		= \033[1;30m
GREY 		= \033[0;37m

##########################################################

ifeq ($(UNAME), Darwin)
	MLX_LIB_DIR = minilibx_opengl/
	MLX_INCLUDE = -Iminilibx_opengl
	MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit -O3
else
	MLX_LIB_DIR = mlx/
	MLX_INCLUDE = -Iminilibx_linux
	MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm #-lz# -O3
endif


all: $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft/ --silent --no-print-directory
	@make -C $(MLX_LIB_DIR) --silent --no-print-directory
	$(CC) $(CFLAGS) $(^) libft/libft.a $(MLX_FLAGS) -o $(@)
	@clear
	@echo "$(GREEN)Compilation of ${CLR_RMV}${CYAN}$(NAME): ${CLR_RMV}$(GREEN)⭐️"
	@echo "$(CYAN)$(NAME) ${CLR_RMV}$(GREEN)created with sucess ${CLR_RMV} ✔️"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus: 

clean:
	rm -f $(OBJS)
	make clean -C ./libft/
	clear
	@echo "$(RED)Deleting🗑 $(PURPLE)-> $(YELLOW)$(NAME) $(CLR_RMV)$(RED)[objs]$(GREEN) ✔️${CLR_RMV}"

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
	clear
	@echo "$(RED)Deleting🗑 $(PURPLE)-> $(YELLOW)$(NAME) $(CLR_RMV)$(RED)[objs] $(GREEN)✔️${CLR_RMV}"

re: fclean all

.PHONY: all clean fclean re