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

OBJDIR			=		obj
OBJS			=		$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

LINKER_FLAGS		=		-Llib -lmingw32 -mwindows -lSDL2main -lSDL2 -lSDL2_image

NAME			=		../Ray

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(ICON) $(LINKER_FLAGS) -o $(NAME)

$(OBJS) : $(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rmdir /q /s $(OBJDIR)

fclean:
	del $(NAME).exe

re: clean fclean
	make

play:
	make
	$(NAME)

.PHONY: all clean fclean re play
