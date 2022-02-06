/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:13:18 by mmeredit          #+#    #+#             */
/*   Updated: 2022/02/06 14:13:20 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H
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

int			ft_strcmp(char *s1, char *s2);
int			get_next_line(char **str);
void		check_result(t_stack **stack, t_stack **stack_b);
void		validation(char **av, t_stack **stack);
t_stack		**create_stack_a(int date, t_stack **stack, char **str);
int			check_stdin(char **str);
int			check_game(char *str, t_stack **stack, t_stack **stack_b);
int			rrr(t_stack **stack, t_stack **stack_b);
int			rra_rrb(t_stack **stack);
int			rr(t_stack **stack, t_stack **stack_b);
int			ra_rb(t_stack **stack);
int			pb(t_stack **stack, t_stack **stack_b);
int			pa(t_stack **stack, t_stack **stack_b);
int			ss(t_stack **stack, t_stack **stack_b);
int			sa_sb(t_stack **stack);
int			ft_checknum(unsigned long long int num, int negative);
void		print_error(void);
void		check_dublies(int num, t_stack *stack);
long int	ft_atoi(const char *str);
void		free_stack(t_stack **stack);
char		**ft_free(char **str);
char		**ft_split(char const *s, char c);
void		ft_circle(t_stack **stack);
void		indexing(t_stack **stack);

#endif
