# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 22:56:07 by qmebble           #+#    #+#              #
#    Updated: 2019/08/27 18:16:00 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Srcs/*.c
OBJ = *.o
LIBS = libftprintf.a
NAME = libft.a
INCLUDE = Header/libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	@ar -x $(LIBS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mv $(NAME) ../$(NAME)

$(OBJ) : $(SRC)
	@echo Compiling libft ...
	@gcc $(FLAGS) -c $(SRC) -I $(INCLUDE)
	@make -C ft_printf/

clean:
	@rm -rf $(OBJ) *SYMDEF*
	@make -C ft_printf/ clean

fclean: clean
	@rm -rf $(NAME) $(LIBS)
	@make -C ft_printf/ fclean

re: fclean all
