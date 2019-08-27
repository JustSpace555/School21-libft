NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCF = Srcs/HighestFunctions/*.c \
		Srcs/HighestFunctions/Parsing/*.c \
		Srcs/Char/*.c \
		Srcs/String/*.c \
		Srcs/Pointer/*.c \
		Srcs/OxX/*.c \
		Srcs/DI/*.c \
		Srcs/Unsigned/*.c \
		Srcs/Float/*.c \

OBJF = $(SRCF: %.c=%.o ($(wildcard *.c))

INCLUDE = -I MainHeader/ft_printf.h -I ../libft.h

all: $(NAME)

$(NAME): $(OBJF)
	@echo Compiling ft_printf ...
	@gcc $(FLAGS) -c $(SRCF) $(INCLUDE)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@mv $(NAME) ../$(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
