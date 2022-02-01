/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:47:04 by mmeredit          #+#    #+#             */
/*   Updated: 2022/01/25 14:47:05 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int check_list(t_stack **stack, t_stack **stack_b);
int ft_sorting_final(t_stack **stack);
void	free_stack(t_stack **stack);
int 	ft_count_list(t_stack **stack);
void	ft_print_stack(t_stack **stack);
void	ft_index(t_stack **stack);
int		*ft_sort_arr(int *arr, int index);
void    ft_score_a_b(t_stack **stack);
void    ft_score(t_stack **stack, t_stack **stack_b);
t_stack	*ft_stack_in_arr(t_stack **stack);
void    ra(t_stack **stack, t_stack *tmp);
void    rra(t_stack **stack, t_stack *tmp);
void	print_error(void);
char	**ft_split(char const *s, char c);
char	*ft_copy(char *str, const char *s, char c, int i);
char	**ft_free(char **str);
//int		ft_count(char const *s, char c);
char	*ft_inic(char *str, char c, const char *s, int i);

#endif