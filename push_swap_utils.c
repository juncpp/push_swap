#include "push_swap.h"

t_stack_2	**ft_stack_2_create_add(int num, t_stack_2 **stack_b)
{
	t_stack_2	*tmp;
	t_stack_2	*p;

	p = *stack_b;
	tmp = malloc(sizeof(t_stack_2));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->num = num;
	if (p == NULL)
		*stack_b = tmp;

	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = tmp;
		tmp->prev = p;
	}
	return (stack_b);
}

t_stack	**ft_remove_list(t_stack **stack, t_stack *tmp)
{
	t_stack	*remove;
	t_stack	*back;

	remove = *stack;
	while (remove != tmp)
		remove = remove->next;
	(*stack) = (*stack)->next;
	back = remove->prev;
	(*stack)->prev = back;
	free(remove);
	return (stack);
}

void	ft_min(t_stack **stack, t_stack_2 **stack_b)
{
	int			min;
	t_stack		*tmp;

	tmp = (*stack)->next;
	min = (*stack)->num;
	while (tmp != *stack)
	{
		if (min > tmp->num)
			min = tmp->num;
		tmp = tmp->next;
	}
	while (tmp->num != min)
		tmp = tmp->next;
	stack_b = ft_stack_2_create_add(min, stack_b);
//	stack = ft_remove_list(stack, tmp);
}

void	ft_max(t_stack **stack, t_stack_2 **stack_b)
{
	int			max;
	t_stack		*tmp;

	tmp = (*stack)->next;
	max = (*stack)->num;
	while (tmp != *stack)
	{
		if (max < tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	while (tmp->num != max)
		tmp = tmp->next;
	stack_b = ft_stack_2_create_add(max, stack_b);
	ft_remove_list(stack, tmp);
}

void	ft_circle_2(t_stack_2 **stack_b)
{
	t_stack_2	*first;

	first = *stack_b;
	while (first->next != NULL)
		first = first->next;
	first->next = *stack_b;
	(*stack_b)->prev = first;
	ft_index_2(stack_b);
	//return (stack_b);
}

void	ft_print_stack_2(t_stack_2 **stack_b)
{
	t_stack_2	*tmp;

	tmp = *stack_b;
	while (tmp->next != *stack_b)
	{
		printf ("Item a stack: %d  index item = %d\n", tmp->num, tmp->index);
		tmp = tmp->next;
	}
	printf ("Item a stack: %d  index item = %d\n", tmp->num, tmp->index);
	//free_stack(stack_b);
}

void	ft_index_2(t_stack_2 **stack_b)
{
	t_stack_2	*tmp;
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

void	start_algorithm(t_stack **stack)
{
	t_stack_2	*stack_b;

	stack_b = NULL;
	ft_min(stack, &stack_b);
	ft_max(stack, &stack_b);
	ft_circle_2(&stack_b);
	ft_print_stack_2(&stack_b);
}