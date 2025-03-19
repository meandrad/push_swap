# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 18:19:46 by meandrad          #+#    #+#              #
#    Updated: 2025/03/19 15:21:39 by meandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c \
      ft_bzero.c \
      ft_calloc.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memcpy.c \
      ft_memset.c \
      ft_memmove.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_tolower.c \
      ft_toupper.c \
      ft_strchr.c \
      ft_strlcat.c \
      ft_strlcpy.c \
      ft_strlen.c \
      ft_strnstr.c \
      ft_strrchr.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_strncmp.c \
      ft_putchar.c \
      ft_putnbr.c \
      ft_putstr.c \
      ft_putendl.c \
      ft_itoa.c \
	  ft_strtrim.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_atol.c \
        ft_isspace.c

OBJS = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
