#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct stack
{
	int				num;
	int				index;
	int				score;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

void		print_error(void);
void		check_dublies(int num, t_stack *stack);
long int	ft_atoi(const char *str);
void		free_stack(t_stack **stack);
char		**ft_free(char **str);
char		**ft_split(char const *s, char c);
void	    ft_circle(t_stack **stack);
void	    indexing(t_stack **stack);

#endif