NAME = ../checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	checker_bonus.c \
		parce_args_bonus.c \
		rules_bonus.c \
		stack_utils_bonus.c \
		moves/moves_bonus.c \
		moves/moves2_bonus.c \
		moves/moves3_bonus.c \
		utils/utils_bonus.c \
		utils/utils2_bonus.c \
		utils/utils3_bonus.c \
		utils/utils4_bonus.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		checker_utils_bonus.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all