NAME = Zombie

CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp Zombie.cpp ZombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CPP) $(CPPFLAGS) -c $(SRC)

clean: $(OBJ)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all