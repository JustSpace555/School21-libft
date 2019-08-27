/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mascut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:55:21 by qmebble           #+#    #+#             */
/*   Updated: 2019/07/05 20:18:17 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mascut(char *s, int start, int end)
{
	int		i;
	char	*f;

	i = 0;
	f = ft_strnew(end - start + 1);
	start--;
	if (!f || !s || end < start)
		return (NULL);
	while (++start < end && s[start] && s[i])
	{
		f[i] = s[start];
		i++;
	}
	f[i] = '\0';
	return (f);
}
