NAME = checker

SRCS = check_main.c \
		swaps.c \
		pushes.c \
		rotations.c \
		rev_rotations.c \
		special_order.c \
		helpers.c \
		lis_manager.c \
		utils.c \
		mov_applier.c \
		finisher.c \
		argv_check.c \
		get_next_line.c \
		get_next_line_utils.c \
		checker_utils.c \



OBJS = $(SRCS:.c=.o)


CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o checker

clean :
			$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
