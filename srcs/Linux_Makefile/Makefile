################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                              by CanTale_Games    #
#                                                                              #
#                                                                              #
################################################################################


CC		=		g++
FLAGS		=		-Wall -Wextra -Werror

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

SDLDIR		=		sdl2
OBJDIR		=		../obj
OBJS		=		$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

INCL		=		-I/nfs/homes/ccantale/Ray/srcs/$(SDLDIR)/include/SDL2
LINK		=		-L/nfs/homes/ccantale/Ray/srcs/$(SDLDIR)/lib -lSDL2 -lSDL2_image

NAME		=		../Ray_linux

all : $(NAME)
	@echo "Ray_linux successfully compiled!"

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LINK)

$(OBJS): $(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(INCL) $(FLAGS) -c $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	rm -rf $(OBJDIR)

fclean:
	rm $(NAME)

re: clean fclean
	make

.PHONY: all clean fclean re play
