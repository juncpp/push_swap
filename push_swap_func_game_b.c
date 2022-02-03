#include "push_swap.h"

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

void	rb(t_stack **stack_b, t_stack *tmp)
{
	int	score;

	score = tmp->score;
	while (score-- != 0)
		write (1, "rb\n", 3);
	*stack_b = tmp;
}

void	rrb(t_stack **stack_b, t_stack *tmp)
{
	int	score;

	score = tmp->score;
	while (score-- != 0)
		write (1, "rrb\n", 4);
	*stack_b = tmp;
}

void	rb_or_rrb(t_stack **stack_b, t_stack *tmp)
{
	if (tmp->prev->score >= tmp->score)
		rrb(stack_b, tmp);
	else
		rb(stack_b, tmp);
}