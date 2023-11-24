

SRC		= get_next_line.c get_next_line_utils.c
SRCB	= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ		= ${SRC:.c=.o}
OBJB		= ${SRC:.c=.o}

CFLAGS	= -Wall -Werror -Wextra
CC		= cc
NAME	= 

all:		${NAME}

${NAME}:	${OBJ}
	ar rcs ${NAME} ${OBJ}

bonus : ${OBJB}

%.o:		%.c
	${CC} ${CFLAGS} -c $< -o $@
	
clean:
	rm -f ${OBJ} ${OBJB}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re