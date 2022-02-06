/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:13:07 by mmeredit          #+#    #+#             */
/*   Updated: 2022/02/06 15:51:57 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

char	*ft_strjoin(char *str, char c)
{
	int		i;
	char	*s;

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

int	get_next_line(char **str)
{
	int		flag;
	char	c;

	*str = (char *)malloc(1);
	if (!*str)
		print_error();
	*str[0] = '\0';
	flag = 1;
	while (flag > 0)
	{
		flag = read(0, &c, 1);
		if (c == '\n')
			break ;
		*str = ft_strjoin(*str, c);
	}
	return (flag);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ag, char **av)
{
	t_stack	*stack;
	t_stack	*stack_b;
	char	*str;

	if (ag > 1)
	{
		stack = NULL;
		stack_b = NULL;
		validation(av, &stack);
	}
	else
		exit(0);
	str = NULL;
	while (check_stdin(&str) > 0)
	{
		if (*str == '\0')
			print_error();
		check_game(str, &stack, &stack_b);
		free(str);
		indexing(&stack);
	}
	check_result(&stack, &stack_b);
	free_stack(&stack);
	return (0);
}
