# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 10:52:19 by tblaase           #+#    #+#              #
#    Updated: 2021/07/22 11:39:13 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES =	ft_flags.c\
			ft_format.c\
			ft_print_char.c\
			ft_print_hexadecimal_help.c\
			ft_print_hexadecimal.c\
			ft_print_int_help.c\
			ft_print_int.c\
			ft_print_pointer.c\
			ft_print_string.c\
			ft_print_unsigned_int_help.c\
			ft_print_unsigned_int.c\
			ft_printf.c\
			ft_special_zero.c\
			ft_width.c\

OBJECTS = $(CFILES:.c=.o)

MAKE = make

LIB_PATH = ./libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

all: subsystem $(NAME)

subsystem:
	$(MAKE) -C $(LIB_PATH)

bonus: all

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS) $(LIB_PATH)/*.o

clean:
	$(MAKE) -C $(LIB_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all
