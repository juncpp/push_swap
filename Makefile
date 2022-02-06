NAME = push_swap

NAME_BONUS = checker

SRCS = ft_split.c push_swap.c push_swap_utils_beta.c push_swap_set_sort.c push_swap_func_valid.c \
			push_swap_func_game_b.c push_swap_func_game_a.c push_swap_checks.c push_swap_pa_r.c

SRCS_BONUS = push_swap_checker.c ft_split.c push_swap_func_valid.c push_swap_checker_valid.c  \
				push_swap_game_checker.c push_swap_game_checker2.c

HDR_BONUS = push_swap_checker.h

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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

bonus:
	@make SRCS="$(SRCS_BONUS)" HDR="$(HDR_BONUS)" NAME="$(NAME_BONUS)" SRC="$(SRCS_BONUS)" all

clean:	
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re:	fclean $(NAME)

.PHONY:			all clean fclean re bonus