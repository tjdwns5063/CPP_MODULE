NAME = convert
CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp Convert.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ) : $(SRC)
	$(CPP) $(CPPFLAGS) -c $(SRC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all