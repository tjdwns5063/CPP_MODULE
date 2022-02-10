CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = PhoneBook.cpp Contact.cpp
MAIN = main.cpp
OBJ = $(SRC:.cpp=.o)

NAME = PhoneBook

all : $(NAME)
$(NAME): $(OBJ) $(MAIN)
	$(CPP) $(CPPFLAGS) $(OBJ) $(MAIN) -o $@
$(OBJ) : $(SRC)
	$(CPP) $(CPPFLAGS) -c $(SRC)
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all