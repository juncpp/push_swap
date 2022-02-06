/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_game_checker2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:45:35 by mmeredit          #+#    #+#             */
/*   Updated: 2022/02/06 15:45:36 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	rr(t_stack **stack, t_stack **stack_b)
{
	ra_rb(stack);
	ra_rb(stack_b);
	return (1);
}

int	rra_rrb(t_stack **stack)
{
	if (*stack == NULL)
		print_error();
	*stack = (*stack)->prev;
	return (1);
}

int	rrr(t_stack **stack, t_stack **stack_b)
{
	rra_rrb(stack);
	rra_rrb(stack_b);
	return (1);
}

int	check_game(char *str, t_stack **stack, t_stack **stack_b)
{
	if (ft_strcmp(str, "sa"))
		return (sa_sb(stack));
	if (ft_strcmp(str, "sb"))
		return (sa_sb(stack_b));
	if (ft_strcmp(str, "ss"))
		return (ss(stack, stack_b));
	if (ft_strcmp(str, "pa"))
		return (pa(stack, stack_b));
	if (ft_strcmp(str, "pb"))
		return (pb(stack, stack_b));
	if (ft_strcmp(str, "ra"))
		return (ra_rb(stack));
	if (ft_strcmp(str, "rb"))
		return (ra_rb(stack_b));
	if (ft_strcmp(str, "rr"))
		return (rr(stack, stack_b));
	if (ft_strcmp(str, "rra"))
		return (rra_rrb(stack));
	if (ft_strcmp(str, "rrb"))
		return (rra_rrb(stack_b));
	if (ft_strcmp(str, "rrr"))
		return (rrr(stack, stack_b));
	print_error();
	return (0);
}

int	check_stdin(char **str)
{
	int	flag;

	flag = 1;
	while (flag > 0)
	{
		flag = get_next_line(str);
		if (flag == -1)
			print_error();
		if (flag == 1)
			break ;
	}
	return (flag);
}
