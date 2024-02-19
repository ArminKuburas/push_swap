CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = sources
OBJDIR = objects
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
PROGRAM = push_swap

SRCS = $(SRCDIR)/ft_free_substrings.c \
	$(SRCDIR)/ft_join2DArrays.c \
	$(SRCDIR)/ft_push_swap.c \
	$(SRCDIR)/initialize_stacks.c \
	$(SRCDIR)/push_functions.c \
	$(SRCDIR)/reverse_rotate_functions.c \
	$(SRCDIR)/rotate_functions.c \
	$(SRCDIR)/sort_algorithm.c \
	$(SRCDIR)/swap_functions.c \
	$(SRCDIR)/exit_handler.c \

LIBFT_SRC = $(LIBFTDIR)/ft_atoi.c \
		$(LIBFTDIR)/ft_bzero.c \
		$(LIBFTDIR)/ft_calloc.c \
		$(LIBFTDIR)/ft_isalnum.c \
		$(LIBFTDIR)/ft_isalpha.c \
		$(LIBFTDIR)/ft_isascii.c \
		$(LIBFTDIR)/ft_isdigit.c \
		$(LIBFTDIR)/ft_isprint.c \
		$(LIBFTDIR)/ft_memchr.c \
		$(LIBFTDIR)/ft_memcmp.c \
		$(LIBFTDIR)/ft_memcpy.c \
		$(LIBFTDIR)/ft_memset.c \
		$(LIBFTDIR)/ft_strchr.c \
		$(LIBFTDIR)/ft_strdup.c \
		$(LIBFTDIR)/ft_strlcat.c \
		$(LIBFTDIR)/ft_strlcpy.c \
		$(LIBFTDIR)/ft_strlen.c \
		$(LIBFTDIR)/ft_strncmp.c \
		$(LIBFTDIR)/ft_strnstr.c \
		$(LIBFTDIR)/ft_strrchr.c \
		$(LIBFTDIR)/ft_tolower.c \
		$(LIBFTDIR)/ft_toupper.c \
		$(LIBFTDIR)/ft_memmove.c \
		$(LIBFTDIR)/ft_substr.c \
		$(LIBFTDIR)/ft_strjoin.c \
		$(LIBFTDIR)/ft_strtrim.c \
		$(LIBFTDIR)/ft_split.c \
		$(LIBFTDIR)/ft_itoa.c \
		$(LIBFTDIR)/ft_strmapi.c \
		$(LIBFTDIR)/ft_striteri.c \
		$(LIBFTDIR)/ft_putchar_fd.c \
		$(LIBFTDIR)/ft_putstr_fd.c \
		$(LIBFTDIR)/ft_putendl_fd.c \
		$(LIBFTDIR)/ft_putnbr_fd.c \
		$(LIBFTDIR)/ft_strcmp.c \
		$(LIBFTDIR)/ft_strndup.c \
		$(LIBFTDIR)/ft_printf.c \
		$(LIBFTDIR)/ft_ptrhex.c \
		$(LIBFTDIR)/ft_put_unsigned_nbr.c \
		$(LIBFTDIR)/ft_putchar.c \
		$(LIBFTDIR)/ft_puthex.c \
		$(LIBFTDIR)/ft_putnbr.c \
		$(LIBFTDIR)/ft_putstr.c \
		$(LIBFTDIR)/ft_printf.c


OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

all: $(PROGRAM)

$(PROGRAM): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT): $(LIBFT_SRC)
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	rm -rf $(MLXDIR)/build

fclean: clean
	rm -rf $(PROGRAM)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re