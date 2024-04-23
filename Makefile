NAME			=	fractol

CC				=	gcc

CC_FLAGS		= 	-Wall -Wextra -Werror -g -O3

RM				=	rm -f

SRC				=	src/fractol.c \
					src/init.c \
					src/hooks.c \
					src/utils.c \

SRC_BONUS		=	src_bonus/fractol.c \
					src_bonus/init.c \
					src_bonus/hooks.c \
					src_bonus/utils.c \

OBJS			=	$(SRC:.c=.o)

OBJS_BONUS		=	$(SRC_BONUS:.c=.o)

.c.o:			
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -I ./inc -I ./minilibx-linux


$(NAME):		$(OBJS)
				make -sC ./minilibx-linux all
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) -L ./minilibx-linux -lmlx -lXext -lX11 -lm

bonus :			$(OBJS_BONUS)
				make -sC ./minilibx-linux all
				$(CC) $(CC_FLAGS) $(OBJS_BONUS) -o $(NAME) -L ./minilibx-linux -lmlx -lXext -lX11 -lm


all:			$(NAME)

clean:
				make -sC ./minilibx-linux clean
				$(RM) $(OBJS)

clean_bonus:
				make -sC ./minilibx-linux clean
				$(RM) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)

fclean_bonus:	clean_bonus
				$(RM) $(NAME)

re:				fclean all

re_bonus:		fclean_bonus all