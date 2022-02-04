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

void		print_error(void);
void		check_dublies(int num, t_stack *stack);
long int	ft_atoi(const char *str);
int			top_or_botm(int num, int mid);
int			check_max(t_stack **stack, int num);
void		rb_pb(t_stack *tmp, t_stack **stack_b, int num, int med);
int			check_median(int min, int max, int num, int flag);
void		ra_without_score(t_stack **stack);
int			ft_compare(int *arr, int n, t_stack *stack);
int			pb_for_minisort(t_stack *tmp, t_stack **stack_b, t_stack **stack);
void		next_minisort(t_stack **stack, t_stack **stack_b, int min);
t_stack		**set_min_index(t_stack **stack, int min);
void		check_dublies(int num, t_stack *stack);
void		ft_circle(t_stack **stack);
void		sa(t_stack **stack);
int			check_swap(int first, int second, int third);
void		rrb(t_stack **stack_b, t_stack *tmp);
void		rb(t_stack **stack_b, t_stack *tmp);
int			all_in_stack_a(t_stack **stack, t_stack **stack_b);
void		rb_or_rrb(t_stack **stack_b, t_stack *tmp);
t_stack		*find_short_way(t_stack **stack, t_stack **stack_b);
void		pa(t_stack **stack, t_stack **stack_b);
int			all_in_stack_a(t_stack **stack, t_stack **stack_b);
int			ft_sorting_final(t_stack **stack);
void		free_stack(t_stack **stack);
int			ft_count_list(t_stack **stack);
void		ft_print_stack(t_stack **stack);
void		indexing(t_stack **stack);
int			*ft_sort_arr(int *arr, int index);
void		set_score(t_stack **stack);
void		sorting_main(t_stack **stack, t_stack **stack_b);
t_stack		*sorting_b(t_stack **stack);
void		ra(t_stack **stack, t_stack *tmp);
void		rra(t_stack **stack, t_stack *tmp);
void		print_error(void);
char		**ft_split(char const *s, char c);
char		*ft_copy(char *str, const char *s, char c, int i);
char		**ft_free(char **str);
char		*ft_inic(char *str, char c, const char *s, int i);

#endif