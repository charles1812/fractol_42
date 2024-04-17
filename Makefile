NAME			=	fractol

SRCS_DIR		=	./src/

INCLUDES		=	./inc/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	fractol.c \
					init.c \
					hooks.c \
					utils.c \



SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror -g -O3

RM				=	rm -f

.c.o:			
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -I ./inc -I ./minilibx-linux


$(NAME):		$(OBJS)
				make -sC ./minilibx-linux all
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) -L ./minilibx-linux -lmlx -lXext -lX11 -lm

all:			$(NAME)

clean:
				make -sC ./minilibx-linux clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all