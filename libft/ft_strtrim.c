/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:56:04 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/05 17:32:19 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	res;
	size_t	x;

	i = 0;
	res = 0;
	x = 0;
	while (set[x])
	{
		if (s1[i] == set[x])
		{
			res++;
			x = 0;
			i++;
		}
		else
			x++;
	}
	return (res);
}

static size_t	count_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	x;
	size_t	res;

	x = 0;
	i = ft_strlen(s1) - 1;
	res = ft_strlen(s1);
	while (set[x])
	{
		if (s1[i] == set[x])
		{
			res--;
			x = 0;
			i--;
		}
		else
			x++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*newstr;
	size_t		i;
	size_t		last;
	size_t		first;

	i = 0;
	first = count_start(s1, set);
	last = count_end(s1, set);
	if (s1[first] == '\0')
	{
		first = 0;
		last = 0;
	}
	newstr = (char *) malloc(sizeof(char) * (last - first + 1));
	if (!newstr)
		return (NULL);
	while (first < last)
	{
		newstr[i] = s1[first];
		i++;
		first++;
	}
	newstr[i] = '\0';
	return (newstr);
}
