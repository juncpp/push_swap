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


int	top_or_botm(int num, int mid)
{
	if (num > mid)
		return (1);
	return (0);
}

void	rb_pb(t_stack *tmp, t_stack **stack_b, int num, int med)
{
	t_stack	*p;

	p = *stack_b;
	if (top_or_botm(num, med))
	{
		while (p->next != NULL)
				p = p->next;
		p->next = tmp;
		tmp->prev = p;
		write(1, "pb\n", 3);
		write(1, "rb\n", 3);
	}
	else
	{
		tmp->next = p;
		p->prev = tmp;
		*stack_b = tmp;
		write(1, "pb\n", 3);
	}
}

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

int	check_median(int min, int max, int num, int flag)
{
	if (flag || (num > min && num < max))
		return (1);
	return (0);
}

void	ra_without_score(t_stack **stack)
{
	(*stack) = (*stack)->next;
	write(1, "ra\n", 3);
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

void	ft_print_arr(int *arr, int n)
{
	int	i;

	i = 0;
	while (i <= n)
		printf("arr_sort = %d\n", arr[i++]);
}

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

void	sa (t_stack **stack)
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

void    set_score(t_stack **stack);

int	pb_for_minisort(t_stack *tmp, t_stack **stack_b, t_stack **stack)
{
	*stack = tmp->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*stack_b == NULL)
		*stack_b = tmp;
	else
	{
		tmp->next = *stack_b;
		tmp->prev = *stack_b;
		(*stack_b)->prev = tmp;
		(*stack_b)->next = tmp;
		*stack_b = tmp;
	}
	write(1, "pb\n", 3);
	return (1);
}

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