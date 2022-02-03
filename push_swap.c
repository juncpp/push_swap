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

t_stack	**create_stack_a(int date, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*p;

	check_dublies(date, *stack);
	p = *stack;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
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

	tmp = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	*stack = tmp;
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free(tmp);
		tmp = *stack;
	}
	free(*stack);
}

// void	ft_print_stack(t_stack **stack)
// {
// 	t_stack	*tmp;

// 	tmp = *stack;
// 	while (tmp->next != *stack)
// 	{
// 		printf ("Item a stack: %d  index item = %d  score intem = %d\n", tmp->num, tmp->index, tmp->score);
// 		tmp = tmp->next;
// 	}
// 	printf ("Item a stack: %d  index item = %d  score intem = %d\n", tmp->num, tmp->index, tmp->score);
// }

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
		if (str[j] == 0)
			print_error();
		while (str[j] != NULL)
			stack = create_stack_a(ft_atoi(str[j++]), stack);
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

	stack = NULL;
	if (ag < 2)
		exit (1);
	else
	{
		validation(av, &stack);
		stack_b = sorting_b(&stack);
		sorting_main(&stack, &stack_b);
	}
	return (0);
}
