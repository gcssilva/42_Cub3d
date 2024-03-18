NAME	=	cub3d
CC		=	cc
LIB		=	/usr/local
CFLAGS	=	-L $(LIB)/inc -lmlx -L $(LIB)/lib -lXext -lX11 -lm
SRC		=	src/main.c
OBJ		=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean
			all

.PHONY:		all clean fclean re
