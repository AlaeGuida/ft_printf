# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguida <aguida@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 10:04:22 by aguida            #+#    #+#              #
#    Updated: 2022/11/09 12:47:13 by aguida           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c\
		  ft_putchar.c\
		  ft_puthexa.c\
		  ft_putnbr.c\
		  ft_putstr.c\
		  ft_putunbr.c\

CC		= cc
CFLAG	= -Wall -Wextra -Werror
OBJS	= $(SRCS:.c=.o)
INCLUDES= ./ft_printf.h

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all