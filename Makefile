NAME		=	get_next_line.a
HEAD		=	get_next_line.h
INC			=	.
OBJ_DIR		=	obj/
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
BUFFER_SIZE	=	-D BUFFER_SIZE=
AR			=	ar rcs
RM			=	rm -f

SRC			=	get_next_line.c \
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o:	%.c $(HEAD) | $(OBJ_DIR)
					$(CC) $(CFLAGS) $(BUFFER_SIZE)42 -I$(INC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ)
					$(AR) $@ $^

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					rm -rf $(OBJ_DIR)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re


