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

// typedef struct stack_b
// {
// 	int				num;
// 	int				index;
// 	int				score;
// 	struct stack	*next;
// 	struct stack	*prev;
// }	t_stack_2;

void	ft_print_stack(t_stack **stack);
void	ft_index_2(t_stack **stack_b);
void	ft_index(t_stack **stack);
//void	ft_circle_2(t_stack_2 **stack_b);
//void	start_algorithm(t_stack **stack);
int		*ft_sort_arr(int *arr, int index);
void	ft_stack_in_arr(t_stack **stack);
//
void	print_error(void);
char	**ft_split(char const *s, char c);
char	*ft_copy(char *str, const char *s, char c, int i);
char	**ft_free(char **str);
int		ft_count(char const *s, char c);
char	*ft_inic(char *str, char c, const char *s, int i);
#endif