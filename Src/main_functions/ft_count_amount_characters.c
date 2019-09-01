/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_amount_characters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:41:37 by qmebble           #+#    #+#             */
/*   Updated: 2019/09/01 18:05:39 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

long long int	return_type(void *num, char *type)
{
	if (ft_strcmp(type, "char") == 0)
		return (*(char *)num);
	else if (ft_strcmp(type, "short") == 0)
		return (*(short *)num);
	else if (ft_strcmp(type, "int") == 0)
		return (*(int *)num);
	else if (ft_strcmp(type, "long int") == 0)
		return (*(long int *)num);
	return (*(long long int *)num);
}

unsigned int	ft_count_amount_characters(void *num, char *type)
{
	long long int	value;
	unsigned int	d;

	d = 0;
	value = return_type(num, type);
	if (value <= 0)
	{
		d = 1;
		value *= -1;
	}
	while (value > 0)
	{
		value /= 10;
		d++;
	}
	return (d);
}

