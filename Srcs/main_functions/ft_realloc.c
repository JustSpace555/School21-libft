/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:21:21 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:54:19 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

void	*ft_realloc(void *s, int size)
{
	int		i;
	int		len;
	char	*c;
	char	*x;
	int		j;

	x = (char *)s;
	i = -1;
	j = -1;
	len = ft_strlen((char *)s) + 1 + size;
	if (!x || !(c = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (x[++i])
		c[i] = x[i];
	while (++j <= size)
	{
		c[i] = '\0';
		i++;
	}
	return ((void *)c);
}
