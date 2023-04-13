/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:56 by nvillase          #+#    #+#             */
/*   Updated: 2023/03/06 08:53:21 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conte_mot(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			i++;
		else
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static char	**ft_replace(const char *s, char **s2, char c)
{
	int		i;
	int		k;
	int		h;

	i = 0;
	k = 0;
	while (s[i] && (k < ft_conte_mot(s, c)))
	{
		if (s[i] != c && ((i == 0) || s[i - 1] == c))
		{
			h = i;
			while (s[i] && s[i] != c)
				i++;
			s2[k] = ft_substr(s, h, i - h);
			k++;
		}
		i++;
	}
	s2[k] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**s2;

	if (!s)
		return (NULL);
	j = ft_conte_mot(s, c);
	s2 = (char **) malloc ((j + 1) * sizeof(char *));
	if (!s2)
		return (NULL);
	return (ft_replace(s, s2, c));
}
