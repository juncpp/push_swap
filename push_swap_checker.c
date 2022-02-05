#include "push_swap_checker.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

t_stack	**create_stack_a(int date, t_stack **stack, char **str)
{
	t_stack	*tmp;
	t_stack	*p;

	check_dublies(date, *stack);
	p = *stack;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
	{
		ft_free(str);
		free_stack(stack);
		print_error();
	}
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

void	ft_print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != *stack)
	{
		printf ("Item a stack: %d  index item = %d\n", tmp->num, tmp->index);
		tmp = tmp->next;
	}
	printf ("Item a stack: %d  index item = %d\n", tmp->num, tmp->index);
	//free_stack(stack_b);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack != NULL)
	{
		tmp = (*stack)->next;
		while (tmp != *stack)
		{
			tmp = tmp->next;
			free(tmp->prev);
		}
		free(tmp);
	}
}

void	validation(char **av, t_stack **stack)
{
	int			i;
	int			j;
	char		**str;

	j = 0;
	i = 1;
	while (av[i] != NULL)
	{
		str = ft_split(av[i++], ' ');
		if (str[j] == 0 || str == NULL)
		{
			str = ft_free(str);
			print_error();
		}
		while (str[j] != NULL)
			stack = create_stack_a(ft_atoi(str[j++]), stack, str);
		j = 0;
		str = ft_free(str);
	}
	ft_circle(stack);
	indexing(stack);
}

char    *ft_strjoin(char *str, char c)
{
    int     i;
    char    *s;

    i = 0;
    while (str[i] != '\0')
        i++;
    s = (char *)malloc(i + 2);
    if (!s)
        print_error();
    i = 0;
    while (str[i])
    {
        s[i] = str[i];
        i++;
    }
    s[i++] = c;
    s[i] = '\0';
    free(str);
    return (s);
}

int get_next_line(char **str)
{
    int     flag;
    char    c;

    *str = (char *)malloc(1);
    if (!*str)
        print_error();
    *str[0] = '\0';
    flag = 1;
    while (flag > 0)
    {
        flag = read(0, &c, 1);
        if (c == '\n')
            break;
        *str = ft_strjoin(*str, c);
    }
    return (flag);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    return (1);
}

int	sa_sb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

    if (*stack == NULL)
    {
        print_error();
        return (0);
    }
    tmp = (*stack)->next;
    if ((*stack)->prev->index == 1 )
    {
        *stack = tmp;
        return (1);
    }
	tmp2 = (*stack)->prev;
    (*stack)->next = tmp->next;
	tmp->next = (*stack);
	tmp->prev = tmp2;
	(*stack)->prev = tmp;
	tmp2->next = tmp;
    if (tmp2->prev == tmp)
		tmp2->prev = (*stack);
	*stack = tmp;
    return (1);
}

int ss(t_stack **stack, t_stack **stack_b)
{
    sa_sb(stack);
    sa_sb(stack_b);
    return (1);
}

int	pa(t_stack **stack, t_stack **stack_b)
{
	t_stack	*tmp_b;

    if (*stack_b == NULL)
    {
        print_error();
        return (0);
    }
	tmp_b = *stack_b;
	tmp_b->prev->next = tmp_b->next;
	tmp_b->next->prev = tmp_b->prev;
	(*stack_b) = (*stack_b)->next;
	tmp_b->next = NULL;
	tmp_b->prev = NULL;
	if ((*stack_b)->next == NULL)
		*stack_b = NULL;
	tmp_b->next = *stack;
	tmp_b->prev = (*stack)->prev;
	(*stack)->prev->next = tmp_b;
	(*stack)->prev = tmp_b;
	*stack = tmp_b;
	return (1);
}

int pb(t_stack **stack, t_stack **stack_b)
{
    t_stack *tmp;

    if (*stack == NULL)
        print_error();
    tmp = *stack;
    *stack = (*stack)->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*stack_b == NULL)
    {
		*stack_b = tmp;
        ft_circle(stack_b);
    }
	else
	{
		tmp->next = *stack_b;
        tmp->prev = (*stack_b)->prev;
        (*stack_b)->prev->next = tmp;
		(*stack_b)->prev = tmp;
		*stack_b = tmp;
	}
	return (1);
}

int ra_rb(t_stack **stack)
{
    if (*stack == NULL)
        print_error();
    *stack = (*stack)->next;
    return (1);
}

int rr(t_stack **stack, t_stack **stack_b)
{
    ra_rb(stack);
    ra_rb(stack_b);
    return (1);
}

int rra_rrb(t_stack **stack)
{
    if (*stack == NULL)
        print_error();
    *stack = (*stack)->prev;
    return(1);
}

int rrr(t_stack **stack, t_stack **stack_b)
{
    rra_rrb(stack);
    rra_rrb(stack_b);
    return (1);
}

int check_game(char *str, t_stack **stack, t_stack **stack_b)
{
    if (ft_strcmp(str, "sa"))
        return (sa_sb(stack));
    if (ft_strcmp(str, "sb"))
        return (sa_sb(stack_b));
    if (ft_strcmp(str, "ss"))
        return (ss(stack, stack_b));
    if (ft_strcmp(str, "pa"))
        return (pa(stack, stack_b));
    if (ft_strcmp(str, "pb"))
        return (pb(stack, stack_b));
    if (ft_strcmp(str, "ra"))
        return (ra_rb(stack));
    if (ft_strcmp(str, "rb"))
        return (ra_rb(stack_b));
    if (ft_strcmp(str, "rr"))
        return (rr(stack, stack_b));
    if (ft_strcmp(str, "rra"))
        return (rra_rrb(stack));
    if (ft_strcmp(str, "rrb"))
        return (rra_rrb(stack_b));
    if (ft_strcmp(str, "rrr"))
        return (rrr(stack, stack_b));
    print_error();
    return (0);
}

int    check_stdin(char **str)
{
    int     flag;
    
    flag = 1;
    while (flag > 0)
    {
        flag = get_next_line(str);
        if (flag == -1)
            print_error();
        if (flag == 1)
            break;
    }
    return (flag);
}

int check_ok(int index, int i)
{
    if (index <= 5 && index >= 4)
    {
        if (i <= 12)
            return (1);
    }
    if (index <= 3)
    {
        if (i <= 3)
            return (1);
    }
    if (index >= 6 && index < 500)
    {
        if (i <= 1500)
            return (1);
    }
    if (index >= 500)
    {
        if (i <= 11500)
            return(1);
    }
    return (0);
}

void    check_result(t_stack **stack, t_stack **stack_b, int i)
{
    t_stack *tmp;

    tmp = *stack;
    if (*stack_b == NULL)
    {
        while (tmp->next != *stack)
        {
            if (tmp->num > tmp->next->num)
            {
                write (1, "KO\n", 3);
                exit(0);
            }
            tmp = tmp->next;
        }
        if (check_ok(tmp->index, i))
            write (1, "OK\n", 3);
        else
            write (1, "KO\n", 3);
        exit(0);
    }
    write (1, "KO\n", 3);
}

int main(int ag, char **av)
{
    t_stack *stack;
    t_stack *stack_b;
    char    *str;
    int     i;

    i = 0;
    if (ag > 1)
    {
        stack = NULL;
        stack_b = NULL;
		validation(av, &stack);
    }
    str = NULL;
    while (check_stdin(&str) > 0)
    {
        i += check_game(str, &stack, &stack_b);
        indexing(&stack);
    }
    indexing(&stack);
    check_result(&stack, &stack_b, i);
    return (0);
}