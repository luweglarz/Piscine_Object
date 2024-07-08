NAME = divideAndRule

CC = g++

STD = -std=c++98

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp Bank.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(STD) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) $(STD) -c $< -o $@

fclean:
	$(RM) -f $(NAME) $(OBJS)

re: fclean all