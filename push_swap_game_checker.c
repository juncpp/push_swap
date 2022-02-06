/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_game_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:43:03 by mmeredit          #+#    #+#             */
/*   Updated: 2022/02/06 15:51:44 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	sa_sb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack == NULL)
	{
		print_error();
		return (0);
	}
	tmp = (*stack)->next;
	if ((*stack)->prev->index == 1)
	{
		*stack = tmp;
		return (1);
	}
	tmp2 = (*stack)->prev;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	tmp->prev = tmp2;
	(*stack)->prev = tmp;
	tmp2->next = tmp;
	if (tmp2->prev == tmp)
		tmp2->prev = (*stack);
	*stack = tmp;
	return (1);
}

int	ss(t_stack **stack, t_stack **stack_b)
{
	sa_sb(stack);
	sa_sb(stack_b);
	return (1);
}

int	pa(t_stack **stack, t_stack **stack_b)
{
	t_stack	*tmp_b;

	if (*stack_b == NULL)
	{
		print_error();
		return (0);
	}
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
	return (1);
}

int	pb(t_stack **stack, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack == NULL)
		print_error();
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = tmp;
		ft_circle(stack_b);
	}
	else
	{
		tmp->next = *stack_b;
		tmp->prev = (*stack_b)->prev;
		(*stack_b)->prev->next = tmp;
		(*stack_b)->prev = tmp;
		*stack_b = tmp;
	}
	return (1);
}

int	ra_rb(t_stack **stack)
{
	if (*stack == NULL)
		print_error();
	*stack = (*stack)->next;
	return (1);
}
