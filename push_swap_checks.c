#include "push_swap.h"

int	check_swap(int first, int second, int third)
{
	if (first > second)
	{
		if (first > third)
		{
			if (second > third)
				return (1);
		}
		else
			return (1);
	}
	else
	{
		if (second > third)
		{
			if (first < third)
				return (1);
		}
	}
	return (0);
}

int	ft_compare(int *arr, int n, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	free (arr);
	free_stack(&stack);
	exit(0);
}

int	check_max(t_stack **stack, int num)
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

int	check_median(int min, int max, int num, int flag)
{
	if (flag || (num > min && num < max))
		return (1);
	return (0);
}