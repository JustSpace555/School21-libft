/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_amount_digits.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:41:37 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/31 18:50:44 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

unsigned int	ft_count_amount_characters(void *num)
{
	long long int	value;
	int				d;

	d = 0;
	value = (long long int)num;
	if (value == -MAX_LL_INT - 1)
		return (20);
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
