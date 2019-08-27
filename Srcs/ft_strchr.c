/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:36:16 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/27 18:08:19 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char*)&s[i]);
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
