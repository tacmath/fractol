# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/05 12:24:50 by mtaquet      #+#   ##    ##    #+#        #
#    Updated: 2018/12/10 02:19:29 by mtaquet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol
LIBDIR = libft/
MLXDIR = minilibx/
SRCDIR = srcs/
INCDIR = includes/
LIBFILES = libft.a
MLXFILES = libmlx.a
SRCFILES = main.c\
		fractal.c\
		event.c\
		draw.c\
		color.c\
		util.c\

INCFILES = fractol.h
LIB = $(addprefix $(LIBDIR),$(LIBFILES))
MLX = $(addprefix $(MLXDIR),$(MLXFILES))
SRC = $(addprefix $(SRCDIR),$(SRCFILES))
INC = $(addprefix $(INCDIR),$(INCFILES)) minilibx/mlx.h libft/includes/libft.h
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra -I includes -I libft/includes -I minilibx

all: $(NAME)

%.o: %.c $(INC)
	gcc -c -o $@ $< $(FLAG)

$(LIB): $(LIBDIR)
	make -C $(LIBDIR)

$(MLX): $(MLXDIR)
	make -C $(MLXDIR)

$(NAME): $(LIB) $(MLX) $(OBJ) $(INC)
	gcc -o $@ $(LIB) $(MLX) $(OBJ) $(FLAG) -framework OpenGL -framework AppKit


clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)
	make clean -C $(MLXDIR)


fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all
