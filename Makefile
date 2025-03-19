NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C libft clean
	rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: clean fclean

.PHONY: all clean fclean re
