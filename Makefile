NAME		=	get_next_line.a
HEAD		=	get_next_line.h
INC_DIR		=	.
OBJ_DIR		=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
BUFFER_SIZE	=	-D BUFFER_SIZE
AR			=	ar rcs
RM			=	rm -f

SRC			=	get_next_line.c \
				get_next_line_utils.c

OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o:	%.c $(HEAD) | $(OBJ_DIR)
					$(CC) $(CFLAGS) $(BUFFER_SIZE)=1 -I$(INC_DIR) -c $< -o $@

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


