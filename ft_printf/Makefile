PRINTF = ft_printf.c ft_putchar_count.c ft_putnbr_count.c ft_putnbr_unsigned_count.c ft_putptr.c ft_putstr_count.c hec_to_hex_max.c hec_to_hex_min.c

SRCS = ${PRINTF}

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar -rsc ${NAME} ${OBJS}

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean: clean;
		rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
