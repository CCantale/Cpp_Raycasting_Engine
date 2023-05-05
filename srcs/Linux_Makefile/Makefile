################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                              by CanTale_Games    #
#                                                                              #
#                                                                              #
################################################################################

CC		=		g++
FLAGS		=		-Wall -Wextra -Werror
LINKER_FLAGS	=		-L/usr/include/SDL2 -lSDL2 -lSDL2main -lSDL2_image

NAME		=		../../Ray

SRC		=		../main.cpp \
				../Game/Game.cpp \
				../Time/Time.cpp \
				../Renderer/Renderer.cpp \
				../Map/Map.cpp \
				../Player/Player.cpp \
				../Raycaster/Raycaster.cpp \
				../Keys/Keys.cpp \
				../Editor/Editor.cpp \
				../Texture/Texture.cpp \
				../Button/Button.cpp \
				../Button/GridButton/GridButton.cpp

OBJ		=		$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
OBJDIR		=		../obj




all: $(NAME)
	@echo Ray succesfully compiled!

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LINKER_FLAGS)

$(OBJ) : $(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) -c $(FLAGS) $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	rm -rf $(OBJDIR)

fclean:
	rm $(NAME)

kill: clean fclean


re: kill
	make

play:
	make
	./$(NAME)

.PHONY: all clean fclean kill re demo
