/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book_utils.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:08:18 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/16 15:47:05 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"
#include "cstdio"

phone_book :: phone_book()
{
	std::cout << "Hello your book has been created" << std::endl;
	this->index = 0;
}

phone_book :: ~phone_book()
{
}

void	phone_book :: print()
{
	std::string	str;
	int			i;
	
	i = 0;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "|  index  |first name| last name| nickname |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	while (i < 8)
	{
		std::cout << "|    ", std::cout << i, std::cout << "    |";
		str = this->contacts[i].get_first(), str = format_info(str), std::cout << str, std::cout << "|";
		str = this->contacts[i].get_last(), str = format_info(str), std::cout << str, std::cout << "|";
		str = this->contacts[i].get_nick(), str = format_info(str), std::cout << str, std::cout << "|" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		i++;
	}
}

void phone_book ::  add_contact()
{
	std::string str;
	
	str = "";
	if (this->index == 8)
	{
		std::cout << "Warning: max contact: your last contact will be replaced by new !" << std::endl;
		while (str != "Y")
		{
			std::cout << "Are u sure: Y N: ", getline(std::cin, str);
			if (std::cin.eof())
				exit(1);
			if (str == "N")
				return ;
			if (str == "Y")
			{
				this->index--;
			}
		}
	}
	this->contacts[this->index].set_index(this->index);
	str = get_info("First name: ");
	this->contacts[this->index].set_first(str);
	str = get_info("Last name: ");
	this->contacts[this->index].set_last(str);
	str = get_info("Nickname: ");
	this->contacts[this->index].set_nick(str);
	str = get_info("Phone number: ");
	while (!is_num(str))
	{
		std::cout << "invalid phone number" << std::endl;
		str = get_info("Phone number: ");
	}
	this->contacts[this->index].set_number(str);
	str = get_info("Darkest secret: ");
	this->contacts[this->index].set_secret(str);
	this->index++;
}

void phone_book :: search_contact()
{
	std::string	y;
	const char	*str;
	int			x;
	
	print();
	x = -1;
	while (x == -1)
	{
		std::cout << "choose index: ", getline(std::cin, y);
		str = y.c_str();
		if (std::cin.eof())
			exit(1);
		else if (y.length() > 1)
		{
			std::cout << "Error: index from 0 to 7" << std::endl;
			x = -1;
		}
		else if (str[0] < '0' || str[0] > '7')
		{
			x = -1;
			std::cout << "Error: index from 0 to 7" << std::endl;
		}
		else
			x = atoi(y.c_str());
	}
	std::cout << "First name    : ", std::cout << this->contacts[x].get_first() << std::endl;
	std::cout << "Last name     : ", std::cout << this->contacts[x].get_last() << std::endl;
	std::cout << "Nickname      : ", std::cout << this->contacts[x].get_nick() << std::endl;
	std::cout << "Phone number  : ", std::cout << this->contacts[x].get_number() << std::endl;
	std::cout << "Darkest secret: ", std::cout << this->contacts[x].get_secret() << std::endl;
	return ;
}