NAME = ../push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	push_swap.c \
		parce_args.c \
		utils/utils.c \
		utils/utils2.c \
		utils/utils3.c \
		utils/utils4.c \
		rules.c \
		moves/moves.c \
		moves/moves2.c \
		moves/moves3.c \
		stack_utils.c \
		sort.c \
		sort2.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all