#include "push_swap.h"

void	ft_index_2(t_stack **stack_b)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = *stack_b;
	while (tmp->next != *stack_b)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
	tmp->index = i;
}

// t_stack	**ft_remove_list(t_stack **stack, int max, int min)
// {

// 	return (stack);
// }

void	ft_circle_2(t_stack **stack_b)
{
	t_stack	*first;

	first = *stack_b;
	while (first->next != NULL)
		first = first->next;
	first->next = *stack_b;
	(*stack_b)->prev = first;
	ft_index_2(stack_b);
	//return (stack_b);
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

void	ft_stack_2_create_add(t_stack *tmp, t_stack **stack_b, int med)
{
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
}

int	other_num(int min, int max, int num, int flag)
{
	if (flag || (num > min && num < max))
		return (1);
	return (0);
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
		if (flag >= 0 && flag < 2)
			flag += other_num(arr[0], arr[ind], tmp->num, flag);
		if (tmp->num != arr[0] && tmp->num != arr[ind] && flag > 1)
		{
			tmp = tmp->next;
			ft_stack_2_create_add(tmp->prev, &stack_b, arr[ind / 2]);
		}
		else
			tmp = tmp->next;
	}
	ft_circle_2(&stack_b);
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

void	mini_sort_b(t_stack	**stack_b)
{
	t_stack *tmp;

	tmp = *stack_b;
}

void	ft_stack_in_arr(t_stack **stack)
{
	int			*arr;
	t_stack		*stack_b;
	int			index;

	stack_b = NULL;
	arr = NULL;
	index = (*stack)->prev->index;
	arr = ft_create_arr(arr, *stack);
	stack_b = ft_min_max_med(arr, stack, index, stack_b);

	ft_print_stack(&stack_b);
	printf ("a________________a\n");
	//ft_remove_list(stack, arr[index], arr[0]);
	ft_print_stack(stack);
	printf ("________________\n");
//	ft_print_arr(arr, index);
}