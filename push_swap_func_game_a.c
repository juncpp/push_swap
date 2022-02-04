/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_game_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:31:25 by mmeredit          #+#    #+#             */
/*   Updated: 2022/02/04 12:31:27 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_without_score(t_stack **stack)
{
	(*stack) = (*stack)->next;
	write(1, "ra\n", 3);
}

void	sa(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*stack)->next;
	tmp2 = (*stack)->prev;
	tmp->next = (*stack);
	(*stack)->next = tmp2;
	tmp->prev = tmp2;
	(*stack)->prev = tmp;
	tmp2->next = tmp;
	tmp2->prev = (*stack);
	*stack = tmp;
	write (1, "sa\n", 3);
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
