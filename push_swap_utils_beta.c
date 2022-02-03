#include "push_swap.h"

// void	ft_circle_2(t_stack **stack_b)
// {
// 	t_stack	*first;

// 	first = *stack_b;
// 	while (first->next != NULL)
// 		first = first->next;
// 	first->next = *stack_b;
// 	(*stack_b)->prev = first;
// 	indexing(stack_b);
// }

int	all_with_stack_b(t_stack *tmp, t_stack **stack_b, int med, t_stack **stack)
{
	*stack = tmp->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = tmp;
		write(1, "pb\n", 3);
	}
	else
		rb_pb(tmp, stack_b, tmp->num, med);
	return (1);
}

t_stack	*create_stack_b(int *arr, t_stack **stack, int ind, t_stack *stack_b)
{
	int			i;
	t_stack		*tmp;
	int			flag;

	flag = 0;
	tmp = *stack;
	i = 0;
	while (ind - i != 2)
	{
		if (flag == 0)
			flag += check_median(arr[0], arr[ind], tmp->num, flag);
		if (tmp->num != arr[0] && tmp->num != arr[ind] && flag++ > 1)
		{
			tmp = tmp->next;
			i += all_with_stack_b(tmp->prev, &stack_b, arr[ind / 2], stack);
		}
		else
		{
			tmp = tmp->next;
			ra_without_score(stack);
		}
	}
	ft_circle(&stack_b);
	return (stack_b);
}

int	*ft_create_arr(int *arr, t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack->prev;
	arr = (int *)malloc(sizeof(int) * (tmp->index + 1));
	while (tmp != stack)
	{
		arr[i++] = tmp->num;
		tmp = tmp->prev;
	}
	arr[i] = tmp->num;
	tmp = tmp->prev;
	if (!ft_compare(arr, i, stack))
		arr = ft_sort_arr(arr, tmp->index);
	return (arr);
}

// void    set_score(t_stack **stack);

t_stack	*minisort(int *arr, t_stack **stack, int index, t_stack **stack_b)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = *stack;
	while (i != 2)
	{
		if (tmp->num != arr[index] && tmp->num != arr[0])
		{
			tmp = tmp->next;
			i += pb_for_minisort(tmp->prev, stack_b, stack);
		}
		else
		{
			tmp = tmp->next;
			ra_without_score(stack);
		}
	}
	if (check_swap((*stack)->num, (*stack)->next->num, (*stack)->prev->num))
		sa(stack);
	set_score(stack);
	set_score(stack_b);
	return (*stack_b);
}

t_stack	*sorting_b(t_stack **stack)
{
	int		*arr;
	t_stack	*stack_b;
	int		index;

	stack_b = NULL;
	arr = NULL;
	index = (*stack)->prev->index;
	arr = ft_create_arr(arr, *stack);
	set_score(stack);
	if (index > 2 && index != 4)
		stack_b = create_stack_b(arr, stack, index, stack_b);
	else if (index == 4)
	{
		stack_b = minisort(arr, stack, index, &stack_b);
		next_minisort(stack, &stack_b, arr[0]);
		free (arr);
		free_stack(stack);
		exit(0);
	}
	if (check_swap((*stack)->num, (*stack)->next->num, (*stack)->prev->num))
		sa(stack);
	stack = set_min_index(stack, arr[0]);
	free (arr);
	return (stack_b);
}