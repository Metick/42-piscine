# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 12:24:28 by sgrootve          #+#    #+#              #
#    Updated: 2023/08/02 17:34:09 by sgrootve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
PATH_SRC = ./source/
HEADER = ./includes/
FLAG = -Wall -Wextra -Werror
OPTION = -I $(HEADER)
SRC := $(PATH_SRC)buffer.c $(PATH_SRC)file.c $(PATH_SRC)main.c $(PATH_SRC)map.c $(PATH_SRC)parser.c $(PATH_SRC)print.c $(PATH_SRC)solver.c $(PATH_SRC)utils.c
OBJECTS := $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	cc $(FLAG) $(OBJECTS) -o $(NAME)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all