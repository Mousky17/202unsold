

FLAGS	=	-Wall -Werror -Wextra -pedantic -lm

CC	=	g++

RM	=	rm -f

SRC =	$(wildcard src/*.cpp)

OBJ =	$(SRC:.cpp=.o)

NAME =	202unsold

all:	$(NAME)

$(NAME):	$(OBJ);
		$(CC) -o $(NAME) $(OBJ) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean;
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
