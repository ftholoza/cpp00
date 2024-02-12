# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 15:21:35 by ftholoza          #+#    #+#              #
#    Updated: 2024/02/12 15:35:22 by ftholoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
NAME = megaphone

all : $(NAME)

re : fclean $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FALGS) $(OBJ) -o $(NAME)
	
$(OBJ) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -rf $(NAME)

