/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:49:35 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/31 08:58:11 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define MAX(a, b) (a > b ? a : b)
# define MIN(a, b) (a < b ? a : b)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dynamic_buffer
{
	unsigned int	overflow_counter;
	int				size_for_malloc;
	int				amount_chars;
}					t_dynamic_buffer;

/*
**					Fills the first len bytes of the memory area
**					with a character which code is indicated by argument c
**
**	@param			b	Block of memory
**	@param			c	Value for assignment
**	@param			len	amount of elements for assignment
**
**	@return			Changed block of memory
*/
void				*ft_memset(void *b, int c, size_t len);

/*
**					Nullifies each element of memory block (array)
**
**	@param			s	Block of memory (array)
**	@param			n	Amount of elements to nullify
**
**	@return			N/A
*/
void				ft_bzero(void *s, size_t n);

/*
**					Copies values from one block of memory (array) to another
**
**	@param			s1	Destination array
**	@param			s2	Source array
**	@param			n	amount of elements to copy
**
**	@return			Changed block of memory
*/
void				*ft_memcpy(void *s1, const void *s2, size_t n);

/*
**					Copies the contents of the memory region pointed to source
**					to the memory region pointed to destination.
**					The copy operation ends when count bytes are copied or
**					after copying the first occurrence of the character c.
**
**	@param			s1	Destiantion memory block
**	@param			s2	Source memory block
**	@param			c	Character to stop coping
**	@param			n	Number of bytes to copy
**
**	@return			A pointer to the end of the s1 region
**						if the c character was found
**					NULL if c is not in s2
*/
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);

/*
**					Copies len bytes from the source array (memory region)
**					to the destination array
**
**	@param			dst	Destiantion array
**	@param			src	Source array
**	@param			len	Amount if bytes for copy
**
**	@return			Pointer to array into which data is copied
*/
void				*ft_memmove(void *dst, const void *src, size_t len);

/*
**					Finds the first occurance of a character in array
**					(memory region) for the first len bytes
**
**	@param			s	Source array
**	@param			c	Character to find for
**	@param			len	Amount of first bytes to search in
**
**	@return			Pointer to the character found or NULL if it is not found
*/
void				*ft_memchr(const void *s, int c, size_t n);

/*
**					Concatenates the string s1 and a copy of the string s2.
**					At the end of the modified string s1, the function sets
**					the null character.
**
**	@param			s1	String for concatenate with source string
**	@param			s2	Source string
**
**	@return			Concatenated s1
*/
char				*ft_strcat(char *restrict s1, const char *restrict s2);

/*
**					Copies elements from string src to string dst
**
**	@param			@dst	The string where the copy is made
**	@param			@src	Source string
**
**	@return			Changed destination string
*/
char				*ft_strcpy(char *dst, const char *src);

/*
**					Duplicates the string pointed to s1.
**					Memory for a duplicate row is allocated using
**					the malloc function
**
**	@param			s1	Source string
**
**	@return			Pointer to duplicated string or NULL if malloc error
*/
char				*ft_strdup(const char *s1);

/*
**					Adds to the string pointed to the destination argument,
**					the string pointed to the source argument, until the end
**					of line character is encountered or until n characters are
**					added.
**
**	@param			s1	Destiantion string
**	@param			s2	Source string
**
**	@return			pointer to destination string
*/
char				*ft_strncat(char *restrict s1, const char *restrict s2,
	size_t n);

/*
**					Copies the data from the source string to the destination
**					string, until the zero character is found or the number of
**					copied characters reaches the certain amount of characters.
**					In this case, the line terminator is not copied.
**
**	@param			dst	Destination string
**	@param			src	Source string
**	@param			len	Amount of characters to copy
**
**	@return			A pointer to modified destination string
*/
char				*ft_strncpy(char *dst, const char *src, size_t len);

/*
**					Searches for the first occurrence of a character in a string
**
**	@param			s	String to search in
**	@param			c	Character to search for
**
**	@return			Pointer to the character if it is found, otherwise NULL
*/
char				*ft_strchr(const char *s, int c);

/*
**					Searches for the last occurrence of a character in a string
**
**	@param			s	String to search in
**	@param			c	Character to search for
**
**	@return			Pointer to character if it is found, otherwise NULL
*/
char				*ft_strrchr(const char *s, int c);

char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
	size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_count_amount_digits(int num);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *s);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_n(int num, ...);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char				*ft_strfix(char *s);
char				*ft_mascut(char *s, int start, int end);
void				*ft_realloc(void *s, int size);
double				ft_abs(double s);
double				ft_pow(double n, double s);
t_dynamic_buffer	make_new_strjoin_buffer(void);

#endif
