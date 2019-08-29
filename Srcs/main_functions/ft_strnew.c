/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:08:32 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:55:32 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*a;

	i = -1;
	if (!(a = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(a, size);
	return (a);
}
