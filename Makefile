NAME	=	libftprintf.a
CFLAGS	=	-Wall -Werror -Wextra -Ilibft/ -Iinc/
SRCDIR	=	src
OBJDIR	=	obj
_SRC	=	ft_skip_nbr.c \
			ft_join_gs.c \
			ft_copy.c \
			ft_process_width.c \
			ft_dioux_prec.c \
			ft_uoxlen.c \
			ft_fwstr.c \
			ft_fwchar.c \
			ft_fstr.c \
			ft_fchar.c \
			ft_fhex.c \
			ft_fint.c \
			ft_fou.c \
			ft_is_width.c \
			ft_is_prec.c \
			ft_is_flag.c \
			ft_is_len.c \
			ft_get_format.c \
			ft_find_fspec.c \
			ft_format.c \
			ft_printf.c
SRC		=	$(addprefix $(SRCDIR)/, $(_SRC))
_OBJ	=	$(_SRC:.c=.o)
OBJ		=	$(addprefix $(OBJDIR)/, $(_OBJ))
LIBFT	=	libft/libft.a
RM		=	rm -f

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@make -s -C ./libft
	@libtool -static -o $(NAME) $(LIBFT) $?

clean:
	@$(RM) $(OBJ)
	@make clean -s -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C ./libft

re: fclean all