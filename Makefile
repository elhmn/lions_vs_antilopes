NAME = game

SRC = main.cpp Game.class.cpp error.cpp Object.class.cpp Lion.class.cpp \
		Team.class.cpp Map.class.cpp load_map.cpp Factory.class.cpp     \
		Antilope.class.cpp RenderManager.class.cpp                      \
		GameManager.class.cpp ObjectManager.class.cpp                   \
		AIManager.class.cpp

SRC_DIR = ./srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.cpp=.o)
OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INCLUDE_PATH = ./incs/

INCLUDES = -I $(INCLUDE_PATH)

FLAGS = -Wall -Werror -Wextra

CC = clang++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -g -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAG) $(INCLUDES) -DUNICODE -c $(SRCS) && mv $(OBJ) $(OBJ_DIR)

ascii: $(SRCS)
	$(CC) $(FLAG) $(INCLUDES) -c $(SRCS) && mv $(OBJ) $(OBJ_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJ)
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
