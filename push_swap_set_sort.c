#include "push_swap.h"

int	top_or_botm(int num, int mid)
{
	if (num > mid)
		return (1);
	return (0);
}

int	*ft_sort_arr(int *arr, int index)
{
	int	i;
	int	tmp;
	int	j;

	j = 0;
	i = 0;
	while (i++ <= index)
	{
		while (j <= index - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		j = 0;
	}
	return (arr);
}

t_stack	**set_min_index(t_stack **stack, int min)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != *stack)
	{
		if (tmp->num == min)
		{
			tmp->index = -1;
			return (stack);
		}
		tmp = tmp->next;
	}
	tmp->index = -1;
	return (stack);
}

void	next_minisort(t_stack **stack, t_stack **stack_b, int min)
{
	while (*stack_b != NULL)
	{
		rb_or_rrb(stack_b, find_short_way(stack, stack_b));
		all_in_stack_a(stack, stack_b);
		if (*stack_b != NULL)
			set_score(stack_b);
	}
	stack = set_min_index(stack, min);
	ft_sorting_final(stack);
}

void	set_score(t_stack **stack)
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