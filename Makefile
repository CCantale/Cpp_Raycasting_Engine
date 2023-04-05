################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                              by CanTale_Games    #
#                                                                              #
#                                                                              #
################################################################################

CC		=		g++
FLAGS		=		-Wall -Wextra -Werror
LINKER_FLAGS	=		-Llib -lSDL -lSDLmain -lSDL_image

NAME		=		demo

SCR		=		main.cpp

OBJ		=		$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
OBJDIR		=		obj




all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LINKER_FLAGS)

$(OBJ) : $(OBJDIR)/%o: %cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	rm -rf $(OBJDIR)

fclean:
	rm $(NAME)

kill: clean fclean


re: kill
	make

demo:
	make
	./demo

.PHONY: all clean fclean kill re demo
