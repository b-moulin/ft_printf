SRCS		= ft_printf4.c ft_printf3.c ft_printf2.c ft_nbargs2.c ft_star3.c ft_star2.c ft_flagzerob.c ft_doubledistribbb.c ft_doubledistribb.c ft_flagsx.c ft_flagzero5.c ft_flagzero4.c ft_flagzero3.c ft_flagzero2.c ft_doubleflag2.c ft_doubleflag3.c ft_doubledistrib.c ft_doubledistrib2.c ft_doubleflag.c ft_flaglist.c ft_flags.c ft_flagszero.c ft_itoa.c ft_nbargs.c ft_printf.c ft_star.c prctflag.c ft_strjoin.c libft.c ft_substr.c ft_write.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Werror -Wall -Wextra

RM			= rm -f

all:		$(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		ar rcs $(NAME) $?

$(OBJS) : ft_printf.h

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re