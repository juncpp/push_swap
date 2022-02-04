/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:20:31 by mmeredit          #+#    #+#             */
/*   Updated: 2022/02/04 13:20:34 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_inic(char *str, char c, const char *s, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	str = (char *)malloc(sizeof(char) * (j + 1));
	return (str);
}

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

char	*ft_copy(char *str, const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	j = 0;
	i = 0;
	if (s == NULL)
		return (0);
	str = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (str == NULL)
		return (0);
	while (j < ft_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		str[j] = ft_inic(str[j], c, s, i);
		if (!(str[j]))
			return (ft_free(str));
		str[j] = ft_copy(str[j], s, c, i);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	str[j] = 0;
	return (str);
}
