NAME = push_swap

SRCS = main.c \
		swaps.c \
		pushes.c \
		rotations.c \
		rev_rotations.c \
		special_order.c \
		helpers.c \
		lis_manager.c \
		utils.c \
		mov_counter.c \
		mov_applier.c \
		finisher.c \
		argv_check.c \


OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a \

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : lm pm

lm :
		@make -C libft

pm : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus : all
		@make -C p_checker

clean :
			$(RM) $(OBJS)
			@make clean -C libft
			@make clean -C p_checker

fclean : clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)
			@make fclean -C p_checker

re : fclean all

rebonus: fclean bonus

.PHONY: all lm pm clean fclean re bonus rebonus
