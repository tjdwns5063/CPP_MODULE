NAME = MyLog
CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra
SRC = Account.cpp
OBJ = $(SRC:.c=.o)
MAIN = test.cpp

all: $(NAME)
$(NAME): $(OBJ) $(MAIN)
	$(CPP) $(CPPFLAGS) $(OBJ) $(MAIN) -o $(NAME)
$(OBJ): $(SRC)
	$(CPP) $(CPPFLAGS) -c $(SRC)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all