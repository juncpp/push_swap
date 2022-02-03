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

void	check_dublies(int num, t_stack *stack)
{
	while (stack != NULL)
	{
		if (num == stack->num)
			print_error();
		stack = stack->next;
	}
}

t_stack	**ft_stack_create_add(int date, t_stack **stack)
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

void	ft_next_back(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
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

t_stack	**ft_circle(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	while (first->next != NULL)
		first = first->next;
	first->next = *stack;
	(*stack)->prev = first;
	return (stack);
}

void	ft_valid(char **av, t_stack **stack)
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
			stack = ft_stack_create_add(ft_atoi(str[j++]), stack);
		j = 0;
		str = ft_free(str);
	}
	stack = ft_circle(stack);
	ft_index(stack);
}

void	ft_index(t_stack **stack)
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

int	main(int ag, char **av)
{
	t_stack		*stack;
	t_stack		*stack_b;

	stack = NULL;
	if (ag < 2)
		exit (1);
	else
	{
		ft_valid(av, &stack);
		stack_b = ft_stack_in_arr(&stack);
		ft_score(&stack, &stack_b);
	}
	return (0);
}
