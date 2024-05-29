# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:50:32 by ftholoza          #+#    #+#              #
#    Updated: 2024/05/29 20:07:02 by ftholoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
NAME = a.out

all : $(NAME)

re : fclean $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFALGS) $(OBJ) -o $(NAME)
	
$(OBJ) : $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) Account.hpp

clean :
	rm -f $(OBJ) Account.hpp.gch
fclean : clean
	rm -rf $(NAME)