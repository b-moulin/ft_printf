SRCS		= ft_flagsx.c ft_flagzero5.c ft_flagzero4.c ft_flagzero3.c ft_flagzero2.c ft_doubleflag2.c ft_doubleflag3.c ft_doubledistrib.c ft_doubledistrib2.c ft_doubleflag.c ft_flaglist.c ft_flags.c ft_flagszero.c ft_itoa.c ft_nbargs.c ft_printf.c ft_star.c prctflag.c ft_strjoin.c libft.c ft_substr.c ft_write.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= cc

RM			= rm -f

all:		$(NAME)

.c.o:
		$(CC) -c $< -o $@

$(NAME):	$(OBJS)
		ar rcs $(NAME) $?

$(OBJS) : ft_printf.h

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re