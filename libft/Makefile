# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/04 09:05:22 by mtaquet      #+#   ##    ##    #+#        #
#    Updated: 2018/12/03 11:23:22 by mtaquet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
MEMDIR = mem/
STRDIR = str/
PUTDIR = put/
LSTDIR = lst/
OTHERDIR = other/
SRCDIR = srcs/
INCDIR = includes/
MEMFILES = ft_memalloc.c\
		ft_memdel.c\
		ft_memset.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\

STRFILES = ft_strdel.c\
		ft_strnew.c\
		ft_strdup.c\
		ft_strnstr.c\
		ft_strequ.c\
		ft_strrchr.c\
		ft_striter.c\
		ft_strsplit.c\
		ft_striteri.c\
		ft_strstr.c\
		ft_strjoin.c\
		ft_strsub.c\
		ft_strlcat.c\
		ft_strtrim.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strcat.c\
		ft_strmapi.c\
		ft_strchr.c\
		ft_strncat.c\
		ft_strclr.c\
		ft_strncmp.c\
		ft_strcmp.c\
		ft_strncpy.c\
		ft_strcpy.c\
		ft_strnequ.c\

PUTFILES = ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\

LSTFILES = ft_lstnew.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\

OTHERFILES = ft_atoi.c\
		ft_itoa.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_split_whitespaces.c\
		ft_tolower.c\
		ft_isprint.c\
		ft_sqrt.c\
		ft_toupper.c\
		ft_power.c\
		ft_print_tables.c\
		ft_print_tables_fd.c\
		ft_abs.c\
		get_next_line.c\

SRCFILES = $(addprefix $(MEMDIR),$(MEMFILES))\
	 	$(addprefix $(STRDIR),$(STRFILES))\
	 	$(addprefix $(PUTDIR),$(PUTFILES))\
	 	$(addprefix $(LSTDIR),$(LSTFILES))\
		$(addprefix $(OTHERDIR),$(OTHERFILES))\

INCFILES = libft.h
SRC = $(addprefix $(SRCDIR),$(SRCFILES))
INC = $(addprefix $(INCDIR),$(INCFILES))
OBJ = $(SRC:.c=.o)
FLAG = -Wall #-Werror -Wextra

all: $(NAME)

%.o: %.c $(INC)
	gcc -c -o $@ $< -I includes $(FLAG)

$(NAME): $(OBJ) $(INC)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

re: fclean all
