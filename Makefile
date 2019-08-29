# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: space <space@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 22:56:07 by qmebble           #+#    #+#              #
#    Updated: 2019/08/30 02:10:50 by space            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIB =		Srcs/main_functions/*.c

GET_NEXT_LINE_FOLDER = Srcs/get_next_line/
SRC_GET_NEXT_LINE = $(GET_NEXT_LINE_FOLDER)*.c

FT_PRINTF_FOLDER = Srcs/ft_printf_functions/
SRC_FT_PRINTF = $(FT_PRINTF_FOLDER)HighestFunctions/*.c \
				$(FT_PRINTF_FOLDER)HighestFunctions/Parsing/*.c \
				$(FT_PRINTF_FOLDER)Char/*.c \
				$(FT_PRINTF_FOLDER)String/*.c \
				$(FT_PRINTF_FOLDER)Pointer/*.c \
				$(FT_PRINTF_FOLDER)OxX/*.c \
				$(FT_PRINTF_FOLDER)DI/*.c \
				$(FT_PRINTF_FOLDER)Unsigned/*.c \
				$(FT_PRINTF_FOLDER)Float/*.c
OBJ = *.o
OBJ_DIT = obj
HEADERS_FOLDER = Headers/
NAME = libft.a
INCLUDE =	$(HEADERS_FOLDER)libft.h \
			$(HEADERS_FOLDER)ft_printf.h \
			$(HEADERS_FOLDER)get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: compile_libft compile_get_next_line compile_ft_printf ran_lib

compile_libft:
	@echo Compiling libft ...
	@gcc $(FLAGS) -c $(SRC_LIB) -I $(INCLUDE)

compile_get_next_line:
	@echo Compilint get_next_line ...
	@gcc $(FLAGS) -c $(SRC_GET_NEXT_LINE) $(INCLUDE)

compile_ft_printf:
	@echo Compiling ft_printf ...
	@gcc $(FLAGS) -c $(SRC_FT_PRINTF) $(INCLUDE)

ran_lib:
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mv $(NAME) ../$(NAME)
	@mkdir obj
	@mv *.o obj/

clean:
	@rm -rf $(OBJ_DIT) *SYMDEF* Headers/*.gch

fclean: clean
	@rm -rf ../$(NAME)

re: fclean all
