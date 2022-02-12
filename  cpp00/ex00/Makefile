CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

NAME = megaphone

all : $(NAME)
$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $< -o $@
%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $<
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all