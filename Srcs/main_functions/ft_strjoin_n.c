/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 02:21:00 by space             #+#    #+#             */
/*   Updated: 2019/08/30 03:05:37 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

t_strjoin_buffer	make_new_strjoin_buffer(void)
{
	t_strjoin_buffer	buffer;

	buffer.amount_chars = 0;
	buffer.size_for_malloc = 50;
	buffer.overflow_counter = 1;
	return (buffer);
}

char				*check_for_overflow_strjoin(int len, t_strjoin_buffer *buffer, char **str)
{
	char	*new;

	if (buffer->amount_chars + len <= buffer->size_for_malloc)
		return (*str);
	while (buffer->size_for_malloc < buffer->amount_chars + len)
	{
		buffer->overflow_counter++;
		buffer->size_for_malloc *= buffer->overflow_counter;
	}
	new = (char *)malloc(sizeof(char) * buffer->size_for_malloc);
	ft_bzero(new, buffer->size_for_malloc);
	ft_strcpy(new, *str);
	free(*str);
	return (new);
}

void				strjoin_n(char **dest, char *src, t_strjoin_buffer *buffer)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(src);
	while (++i < len)
	{
		(*dest)[buffer->amount_chars] = src[i];
		buffer->amount_chars++;
	}
}

char	*ft_strjoin_n(int num, ...)
{
	va_list				open;
	char				*final;
	char				*temp;
	t_strjoin_buffer	buffer;

	va_start(open, num);
	buffer = make_new_strjoin_buffer();
	final = (char *)malloc(sizeof(char) * buffer.size_for_malloc);
	ft_bzero(final, buffer.size_for_malloc);
	while (num > 0)
	{
		temp = va_arg(open, char *);
		final = check_for_overflow_strjoin(ft_strlen(temp), &buffer, &final);
		strjoin_n(&final, temp, &buffer);
		num--;
	}
	va_end(open);
	return (final);
}
