################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                              by CanTale_Games    #
#                                                                              #
#                                                                              #
################################################################################


CC			=		g++
CFLAGS			=		-Wall -Wextra -Werror

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


STATICLIB		=		-static-libgcc -static-libstdc++
LINKER_FLAGS		=		-Llib -lmingw32 -mwindows -lSDL2main -lSDL2 -lSDL2_image

NAME			=		../Ray

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(ICON) $(LINKER_FLAGS) $(STATICLIB) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

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
