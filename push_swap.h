/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:47:04 by mmeredit          #+#    #+#             */
/*   Updated: 2022/01/25 14:47:05 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct stack
{
	int				num;
	struct stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
char	*ft_copy(char *str, const char *s, char c, int i);
char	**ft_free(char **str);
int		ft_count(char const *s, char c);
char	*ft_inic(char *str, char c, const char *s, int i);
#endif