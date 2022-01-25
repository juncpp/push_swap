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

void	ft_stack_create_add(int date, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->next = NULL;
	tmp->num = date;
	if (p == NULL)
		*stack = tmp;
	else
	{
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	ft_next_back(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
}

void	print_error()
{
	write(1, "ERROR", 5);
	exit(0);
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
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	if (str[i] == '\0')
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

void	ft_print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf ("Item a stack: %d\n", tmp->num);
		tmp = tmp->next;
	}
}

int	main(int ag, char **av)
{
	t_stack	*stack;
	int		i;
	int		j;
	char	**str;

	j = 0;
	stack = NULL;
	i = 1;
	if (ag < 2)
		write (1, "ERROR", 5);
	else
	{
		i = 1;
		while (av[i] != '\0')
		{
			str = ft_split(av[i], ' ');
			if (str[j] == 0)
				print_error();
			while (str[j] != 0)
			{
				ft_stack_create_add(ft_atoi(str[j]), &stack);
				j++;
			}
			j = 0;
			i++;
		}
		ft_free(str);
	//	ft_next_back(&stack);
		ft_print_stack(&stack);
	}
	return (0);
}
