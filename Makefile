NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SRCS =
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(FLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	 rm -f $(NAME)

re: clean fclean

.PHONY: all clean fclean re
