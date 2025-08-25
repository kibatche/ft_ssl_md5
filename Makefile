CC = gcc
RM = rm -rf

SRC = main.c md5.c error.c
CFLAGS = -Wall -Wextra -Werror
NAME = ft_ssl_md5

SRCDIR = ./src
OBJDIR = ./obj

OBJS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
DEPS = $(SRC:.c=.o)

LIB_EXE = libft/libft.a
INCL = -I ./includes -I ./libft
LIB_COMPIL = -L./libft -lft

all: $(NAME)

${LIB_EXE}:
	@make -C libft

$(NAME): $(LIB_EXE) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Iincludes

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(CFLAGS) -Iincludes

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean re all fclean