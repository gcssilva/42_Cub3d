NAME	=	cub3d
CC		=	cc
LIB		=	/usr/local
CFLAGS	=	-L libft -lft -L $(LIB)/inc -lmlx -L $(LIB)/lib -lXext -lX11 -lm
SRC		=	src/main.c src/parse/parse_map.c src/parse/parse_el.c src/parse/parse_path.c
OBJ		=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			@cd libft && make
			@cd ..
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			@cd libft && make clean
			@cd ..
			@rm -f $(OBJ)

fclean:		clean
			@cd libft && make fclean
			@cd ..
			@rm -f $(NAME)

re:			fclean
			all

.PHONY:		all clean fclean re
