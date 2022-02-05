NAME = push_swap

SRCS = ft_split.c push_swap.c push_swap_utils_beta.c push_swap_set_sort.c push_swap_func_valid.c \
			push_swap_func_game_b.c push_swap_func_game_a.c push_swap_checks.c push_swap_pa_r.c

OBJS = $(SRCS:.c=.o)

HDR = push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

%.o:	%.c $(HDR)
	$(CC) $(CFLAGS) -I.$(HDR) -c $< -o $@

clean:	
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:			all clean fclean re bonus