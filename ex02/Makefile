# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:50:32 by ftholoza          #+#    #+#              #
#    Updated: 2024/02/19 12:55:23 by ftholoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
NAME = a.out

all : $(NAME)

re : fclean $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FALGS) $(OBJ) -o $(NAME)
	
$(OBJ) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC) Account.hpp

clean :
	rm -f $(OBJ) Account.hpp.gch
fclean : clean
	rm -rf $(NAME)