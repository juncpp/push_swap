/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:30:49 by mmeredit          #+#    #+#             */
/*   Updated: 2022/02/04 12:30:52 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dublies(int num, t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (num == tmp->num)
		{
			ft_circle(&stack);
			free_stack(&stack);
			print_error();
		}
		tmp = tmp->next;
	}
}

int	ft_checknum(unsigned long long int num, int negative)
{
	if (num > 2147483647 && negative > 0)
		print_error();
	if (num > 2147483648 && negative < 0)
		print_error();
	return ((int) num * negative);
}

long int	ft_atoi(const char *str)
{
	int						i;
	int						negative;
	unsigned long long int	num;

	num = 0;
	i = 0;
	negative = 1;
	if (str[i] == '-')
	{
		negative = -negative;
		i++;
	}
	if (str[i] == '\0' || str[i] == '-' || str[i] == '+')
		print_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		print_error();
	return (ft_checknum(num, negative));
}

void	ft_circle(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	while (first->next != NULL)
		first = first->next;
	first->next = *stack;
	(*stack)->prev = first;
}

void	indexing(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp->next != *stack)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
	tmp->index = i;
}
