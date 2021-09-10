/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:44:31 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/10 14:44:33 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*ret;

	i = 0;
	while (s[i] != '\0')
		i++;
	len = i;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = *s;
		s++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	src_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	src_len = i;
	i = 0;
	if (src_len > start)
		while (s[i + start] && i < len)
			i++;
	else
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, i + 1);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*str;

	i = 0;
	while (s1[i] != '\0')
		i++;
	len1 = i;
	i = 0;
	while (s2[i] != '\0')
		i++;
	len2 = i;
	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, (len2 + 1));
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (!dst || !src)
		return (0);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[count] != '\0')
		count++;
	return (count);
}
