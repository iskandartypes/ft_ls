/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:11:06 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/07 12:01:53 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int			count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	*len_next(char const *s, char c)
{
	static int	stendlen[3];

	stendlen[0] = 0;
	stendlen[1] = 0;
	stendlen[2] = 0;
	if (s[stendlen[0]])
	{
		while (s[stendlen[0]] == c)
			stendlen[0]++;
		stendlen[1] = stendlen[0];
		while (s[stendlen[1]] && s[stendlen[1]++] != c)
			stendlen[2]++;
	}
	return (stendlen);
}

char		**ft_strsplit(char const *s, char c)
{
	int			count;
	int			i;
	int			*wl;
	char		**words;

	if (!s || !c)
		return (NULL);
	count = word_count(s, c);
	if (!(words = (char **)malloc((count + 1) * sizeof(*words))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		wl = len_next(s, c);
		if (!(words[i++] = ft_strsub(s, (unsigned int)wl[0], (size_t)wl[2])))
		{
			while (i--)
				ft_strdel(&words[i]);
			free(words);
			return (NULL);
		}
		s += wl[1];
	}
	words[i] = NULL;
	return (words);
}
