NAME = game

SRC = main.cpp Game.class.cpp Object.class.cpp error.cpp
SRC_DIR = ./srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.cpp=.o)
OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INCLUDE_PATH = ./incs/

INCLUDES = -I $(INCLUDE_PATH)

FLAGS = -Wall -Werror -Wextra

CC = g++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAG) $(INCLUDES) -c $(SRCS) && mv $(OBJ) $(OBJ_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(OBJ)
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
