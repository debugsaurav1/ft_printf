SRCS =	ft_printchar.c\
		ft_printf.c \
		ft_printhex.c \
		ft_printnumber.c \
		ft_printptr.c \
		ft_printstr.c \
		ft_printunsigned.c \
		
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fcclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
