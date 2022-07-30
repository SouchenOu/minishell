/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:35:52 by souchen           #+#    #+#             */
/*   Updated: 2022/07/28 15:11:06 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenwrd(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len++;
			while (*s != '\0' && *s != c)
			{
				s++;
			}
			if (*s == '\0')
				return (len);
		}
		s++;
	}
	return (len);
}

static void	*ft_free(char **dest, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(dest[j]);
		i++;
	}
	free (dest);
	return (NULL);
}

static char	**ft_checkalocc(char **dest, const char *s, char c)
{
	size_t	i;
	int		j;
	size_t	index;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		index = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (index != i)
		{
			dest[j] = ft_substr(s, index, i - index);
			if (!dest[j])
				return (ft_free(dest, j));
			j++;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc((ft_lenwrd(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest = ft_checkalocc(dest, s, c);
	return (dest);
}
