
SRCP = ./
SRCS_PRINTF = ft_printf.c
SRCS = $(addprefix $(SRCP),$(SRCS_PRINTF))

OBJS = $(SRCS:.c=.o)

HEAD = ./
LIBFT_DIR = ./libft/
LIBFT = libft.a
LIBFT_AR = $(addprefix $(LIBFT_DIR), $(LIBFT))

NAME		= libftprintf.a
AR			= ar rcs
RM			= rm -f
GCC			= gcc
CFLAGS 		= -Wall -Wextra -Werror

all: $(NAME) $(LIBFT_AR)

$(OBJS): %.o: %.c

$(LIBFT_AR):
	@make print -C $(LIBFT_DIR)
	@make string -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_AR)

clean:
	@make fclean -C $(LIBFT_DIR)
	
fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
