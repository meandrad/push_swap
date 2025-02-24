NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SRCS =  ./libft/libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	 rm -rf $(NAME)

re: clean fclean

.PHONY: all clean fclean re
