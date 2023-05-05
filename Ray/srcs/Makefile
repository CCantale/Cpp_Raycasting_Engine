################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                              by CanTale_Games    #
#                                                                              #
#                                                                              #
################################################################################


CC			=		g++
FLAGS			=		-Wall -Wextra -Werror

SRC			=		main.cpp \
					Game/Game.cpp \
					Time/Time.cpp \
					Renderer/Renderer.cpp \
					Map/Map.cpp \
					Player/Player.cpp \
					Raycaster/Raycaster.cpp \
					Keys/Keys.cpp \
					Texture/Texture.cpp \
					Button/Button.cpp \
					Editor/Editor.cpp \
					Button/GridButton/GridButton.cpp

ICON			=		icon.rs

OBJS			=		$(SRC:.cpp=.o)

#INCLUDE_PATHS		=		-IC:\SDL2\include\SDL2 -IC:\SDL2_image\i686-w64-mingw32\include\SDL2
#LIBRARY_PATHS		=		-LC:\SDL2\lib -LC:\SDL2_image\i686-w64-mingw32\lib
LINKER_FLAGS		=		-Llib -lmingw32 -mwindows -lSDL2main -lSDL2 -lSDL2_image

NAME			=		../Ray

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(ICON) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) $(IMAGE_PATH) $(IMAGE_FLAG) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	del /q /s *.o

fclean:
	del $(NAME).exe

re: clean fclean
	make

play:
	make
	$(NAME)

.PHONY: all clean fclean re play
