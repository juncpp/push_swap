/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pa_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:01:39 by mmeredit          #+#    #+#             */
/*   Updated: 2022/02/02 14:01:41 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_in_stack_a(t_stack **stack, t_stack **stack_b)
{
	if ((*stack_b)->num < (*stack)->num)
	{
		if ((*stack_b)->num > (*stack)->prev->num)
		{
			pa(stack, stack_b);
			set_score(stack);
			return (1);
		}
	}
	check_max(stack, (*stack_b)->num);
	pa(stack, stack_b);
	set_score(stack);
	if (*stack_b != NULL)
		set_score(stack_b);
	return (0);
}

int	ft_sorting_final(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != *stack)
	{
		if (tmp->index == -1)
		{
			if (tmp->score == 0)
				return (0);
			else
			{
				if (tmp->prev->score >= tmp->score)
					rra(stack, tmp);
				else
					ra(stack, tmp);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	rra(stack, tmp);
	return (0);
}

int		count_move_stack_a(t_stack **stack, t_stack **stack_b, int num)
{
	t_stack	*tmp_a;

	tmp_a = *stack;
	if ((*stack_b)->num < (*stack)->num)
	{
		if ((*stack_b)->num > (*stack)->prev->num)
			return (1);
	}
	while (tmp_a->next != *stack)
	{
		if (tmp_a->num > num && tmp_a->prev->num < num)
			return (tmp_a->score);
		tmp_a = tmp_a->next;
	}
	return (tmp_a->score);
}

t_stack		*find_short_way(t_stack **stack, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*elem_in_stack_b;

	tmp = (*stack_b)->next;
	i = count_move_stack_a(stack, &tmp->prev, tmp->prev->num) + tmp->prev->score;
	elem_in_stack_b = tmp->prev;
	while (tmp != *stack_b)
	{
		if (i > count_move_stack_a(stack, &tmp, tmp->num) + tmp->score)
		{
			i = count_move_stack_a(stack, &tmp, tmp->num) + tmp->score;
			elem_in_stack_b = tmp;
		}
		tmp = tmp->next;
	}
	return (elem_in_stack_b);
}


void	sorting_main(t_stack **stack, t_stack **stack_b)
{
	set_score(stack);
	if (*stack_b != NULL)
		set_score(stack_b);
	while (*stack_b != NULL)
	{
		rb_or_rrb(stack_b, find_short_way(stack, stack_b));
		all_in_stack_a(stack, stack_b);
		if (*stack_b != NULL)
			set_score(stack_b);
	}
	ft_sorting_final(stack);
	free_stack(stack);;
}
  