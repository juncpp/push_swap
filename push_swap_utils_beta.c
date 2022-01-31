#include "push_swap.h"

void	ft_circle_2(t_stack **stack_b)
{
	t_stack	*first;

	first = *stack_b;
	while (first->next != NULL)
		first = first->next;
	first->next = *stack_b;
	(*stack_b)->prev = first;
	ft_index(stack_b);
}


int	check_med(int num, int mid)
{
	if (num > mid)
		return (1);
	return (0);
}

void	ft_rb_pb(t_stack *tmp, t_stack **stack_b, int num, int med)
{
	t_stack	*p;

	p = *stack_b;
	if (check_med(num, med))
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

int	ft_stack_2_create_add(t_stack *tmp, t_stack **stack_b, int med, t_stack **stack)
{
	*stack = (*stack)->next;
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
		ft_rb_pb(tmp, stack_b, tmp->num, med);
	return (1);
}

int	other_num(int min, int max, int num, int flag)
{
	if (flag || (num > min && num < max))
		return (1);
	return (0);
}

void	ra_second(t_stack **stack)
{
	(*stack) = (*stack)->next;
	write(1, "ra\n", 3);
}

t_stack	*ft_min_max_med(int *arr, t_stack **stack, int ind, t_stack *stack_b)
{
	int			i;
	t_stack		*tmp;
	int			flag;

	flag = 0;
	tmp = *stack;
	i = 0;
	while (i++ <= ind)
	{
		if (flag == 0)
			flag += other_num(arr[0], arr[ind], tmp->num, flag);
		if (tmp->num != arr[0] && tmp->num != arr[ind] && flag++ > 1)
		{
			tmp = tmp->next;
			i += ft_stack_2_create_add(tmp->prev, &stack_b, arr[ind / 2], stack);
		}
		else
		{
			tmp = tmp->next;
			ra_second(stack);
		}
	}
	ft_circle_2(&stack_b);
	return (stack_b);
}

int	ft_compare(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
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
	if (!ft_compare(arr, i))
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

int	check_a(int first, int second, int third)
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

t_stack	**ft_index_min(t_stack **stack, int min)
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
	tmp->next= (*stack);
	(*stack)->next = tmp2;
	tmp->prev = tmp2;
	(*stack)->prev = tmp;
	tmp2->next = tmp;
	tmp2->prev = (*stack);
	*stack = tmp;
	write (1, "sa\n", 3);
}

void    ft_score_a_b(t_stack **stack);

t_stack	*ft_stack_in_arr(t_stack **stack)
{
	int		*arr;
	t_stack	*stack_b;
	int		index;

	stack_b = NULL;
	arr = NULL;
	index = (*stack)->prev->index;
	arr = ft_create_arr(arr, *stack);
	ft_score_a_b(stack);
	if (index > 2)
		stack_b = ft_min_max_med(arr, stack, index, stack_b);
	// printf("Stack_b\n");
	// ft_print_stack(&stack_b);
	// printf("Stack_a\n");
	// ft_print_stack(stack);
	if (check_a((*stack)->num, (*stack)->next->num, (*stack)->prev->num))
	 	sa(stack);
	stack = ft_index_min(stack, arr[0]);
//	printf("SWAP_A\n");
//	ft_print_stack(stack);
//	ft_print_arr(arr, index);
	return (stack_b);
}