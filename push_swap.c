/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:46:57 by mmeredit          #+#    #+#             */
/*   Updated: 2022/01/25 14:47:00 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

t_stack	**create_stack_a(int date, t_stack **stack, char **str)
{
	t_stack	*tmp;
	t_stack	*p;

	check_dublies(date, *stack);
	p = *stack;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
	{
		ft_free(str);
		free_stack(stack);
		print_error();
	}
	tmp->next = NULL;
	tmp->num = date;
	if (p == NULL)
		*stack = tmp;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = tmp;
		tmp->prev = p;
	}
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack != NULL)
	{
		tmp = (*stack)->next;
		while (tmp != *stack)
		{
			tmp = tmp->next;
			free(tmp->prev);
		}
		free(tmp);
	}
}

void	validation(char **av, t_stack **stack)
{
	int			i;
	int			j;
	char		**str;

	j = 0;
	i = 1;
	while (av[i] != NULL)
	{
		str = ft_split(av[i++], ' ');
		if (str[j] == 0 || str == NULL)
		{
			str = ft_free(str);
			print_error();
		}
		while (str[j] != NULL)
			stack = create_stack_a(ft_atoi(str[j++]), stack, str);
		j = 0;
		str = ft_free(str);
	}
	ft_circle(stack);
	indexing(stack);
}

int	main(int ag, char **av)
{
	t_stack		*stack;
	t_stack		*stack_b;

	if (ag < 2)
		return (0);
	else
	{
		stack = NULL;
		validation(av, &stack);
		stack_b = sorting_b(&stack);
		sorting_main(&stack, &stack_b);
	}
	return (0);
}
