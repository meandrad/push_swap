NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SRCS = \
	srcs/handle_errors.c \
	srcs/create_stack_a.c \
	srcs/create_stack_b.c \
	srcs/stack_utils.c \
	srcs/push_swap.c \
	srcs/build_stack.c \
	srcs/instructions/sort_three_nodes.c \
	srcs/instructions/push_stack.c \
	srcs/instructions/swap_stack.c \
	srcs/instructions/sort_stack.c \
	srcs/instructions/reverse_rotate_stack.c \
	srcs/instructions/rotate_stack.c
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

re: fclean all

.PHONY: all clean fclean re
