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

int	ft_count_list(t_stack **stack)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = *stack;
	while (tmp->next != *stack)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_score_a_b(t_stack **stack)
{
	int		i;
	t_stack	*tmp;
	int		mid;

	i = 0;
	mid = ft_count_list(stack);
	tmp = *stack;
	while (i <= mid)
	{
		if (i < mid / 2 + 1)
			tmp->score = i;
		else if (i - 1 == mid / 2)
		{
			if ((mid / 2) * 2 == mid)
				tmp->score = mid / 2;
			else
				tmp->score = i;
		}
		else
			tmp->score = tmp->prev->score - 1;
		tmp = tmp->next;
		i++;
	}
}

void	pa(t_stack **stack, t_stack **stack_b)
{
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	tmp_b->prev->next = tmp_b->next;
	tmp_b->next->prev = tmp_b->prev;
	(*stack_b) = (*stack_b)->next;
	tmp_b->next = NULL;
	tmp_b->prev = NULL;
	if ((*stack_b)->next == NULL)
		*stack_b = NULL;
	tmp_b->next = *stack;
	tmp_b->prev = (*stack)->prev;
	(*stack)->prev->next = tmp_b;
	(*stack)->prev = tmp_b;
	*stack = tmp_b;
	write(1, "pa\n", 3);
}

int	ft_check_max(t_stack **stack, int num)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	while (tmp->next != *stack)
	{
		if (tmp->num > num && tmp->prev->num < num)
		{
			if (tmp->prev->score >= tmp->score)
				rra(stack, tmp);
			else
				ra(stack, tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	if (tmp->prev->score >= tmp->score)
		rra(stack, tmp);
	else
		ra(stack, tmp);
	return (1);
}

void	ra(t_stack **stack, t_stack *tmp)
{
	int	score;

	score = tmp->score;
	while (score-- != 0)
		write (1, "ra\n", 3);
	*stack = tmp;
}

void	rra(t_stack **stack, t_stack *tmp)
{
	int	score;

	score = tmp->score;
	while (score-- != 0)
		write (1, "rra\n", 4);
	*stack = tmp;
}

int	check_list(t_stack **stack, t_stack **stack_b)
{
	if ((*stack_b)->num < (*stack)->num)
	{
		if ((*stack_b)->num > (*stack)->prev->num)
		{
			pa(stack, stack_b);
			ft_score_a_b(stack);
			return (1);
		}
	}
	ft_check_max(stack, (*stack_b)->num);
	pa(stack, stack_b);
	ft_score_a_b(stack);
	if (*stack_b != NULL)
		ft_score_a_b(stack_b);
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

t_stack		*count_stack_b_a(t_stack **stack, t_stack **stack_b)
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

void	rb(t_stack **stack_b, t_stack *tmp)
{
	int	score;

	score = tmp->score;
	while (score-- != 0)
		write (1, "rb\n", 3);
	*stack_b = tmp;
}

void	rrb(t_stack **stack_b, t_stack *tmp)
{
	int	score;

	score = tmp->score;
	while (score-- != 0)
		write (1, "rrb\n", 4);
	*stack_b = tmp;
}

void	check_r_stack_b(t_stack **stack_b, t_stack *tmp)
{
	if (tmp->prev->score >= tmp->score)
		rrb(stack_b, tmp);
	else
		rb(stack_b, tmp);
}


void	ft_score(t_stack **stack, t_stack **stack_b)
{
	t_stack	*elem_b;

	ft_score_a_b(stack);
	if (*stack_b != NULL)
		ft_score_a_b(stack_b);
	while (*stack_b != NULL)
	{
		elem_b = count_stack_b_a(stack, stack_b);
		check_r_stack_b(stack_b, elem_b);
		check_list(stack, stack_b);
		if (*stack_b != NULL)
			ft_score_a_b(stack_b);
	}
	ft_sorting_final(stack);
	free_stack(stack);;
}
  