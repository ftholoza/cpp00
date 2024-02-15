/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:30:35 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/15 19:15:55 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"
#include "cstdio"


contact :: contact()
{
	//std::cout << "constructor contact" << std::endl;
}

contact :: ~contact()
{	
}

void contact :: set_index(int index)
{
	this->index = index;
}

void contact :: set_first(std::string str)
{
	this->first_name = str;
}

void contact :: set_last(std::string str)
{
	this->last_name = str;
}

void contact :: set_nick(std::string str)
{
	this->nickname = str;
}

void contact :: set_number(std::string str)
{
	this->phone_number = str;
}

void contact :: set_secret(std::string str)
{
	this->darkest_secret = str;
}

std::string contact :: get_first()
{
	return(this->first_name);
}

std::string contact :: get_last()
{
	return(this->last_name);
}

std::string contact :: get_nick()
{
	return(this->nickname);
}

std::string contact :: get_number()
{
	return(this->phone_number);
}

std::string contact :: get_secret()
{
	return(this->darkest_secret);
}

int	contact :: get_index()
{
	return (this->index);
}

void contact :: delete_contact()
{
	this->first_name.clear();
	this->last_name.clear();
	this->nickname.clear();
	this->phone_number.clear();
	this->darkest_secret.clear();
}

std::string	format_info(std::string str)
{
	int	i;

	i = 0;
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(1, '.');
		return (str);
	}
	if (str.length() <= 10)
	{
		i = 10 - str.length();
		str.resize(str.length() + i, ' ');
		return (str);
	}
	return (NULL);
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

phone_book :: phone_book()
{
	std::cout << "Hello your book has been created" << std::endl;
	this->index = 0;
}

phone_book :: ~phone_book()
{
	
}

int	is_num(std::string str)
{
	const char *temp;
	int			i;

	i = 0;
	temp = str.c_str();
	while (temp[i])
	{
		if ((temp[i] >= '0' && temp[i] <= '9') || temp[i] == ' ' || temp[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

std::string get_info(const char *str)
{
	std::string res;
	
	res = "";
	while (res.empty())
	{
		std::cout << str, getline(std::cin, res);
		if (res.empty())
			std::cout << "Error: empty" << std::endl;
	}
	return (res);
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
	int			x;
	std::string	y;
	
	x = -1;
	print();
	while (x == -1 || x > 7)
	{
		std::cout << "choose index: ", std::cin >> x;
		if (std::cin.bad())
			return ;
		else if (std::cin.eof())
			return ;
		getline(std::cin, y);
		if (x > 7)
			std::cout << "Error: the index go from 0 to 7" << std::endl;	
	}
	std::cout << "First name    : ", std::cout << this->contacts[x].get_first() << std::endl;
	std::cout << "Last name     : ", std::cout << this->contacts[x].get_last() << std::endl;
	std::cout << "Nickname      : ", std::cout << this->contacts[x].get_nick() << std::endl;
	std::cout << "Phone number  : ", std::cout << this->contacts[x].get_number() << std::endl;
	std::cout << "Darkest secret: ", std::cout << this->contacts[x].get_secret() << std::endl;
	return ;
}

int	command_choice(phone_book *pb, std::string str)
{
	std::cout << "Command: " , getline(std::cin, str);
	if (std::cin.bad())
		return (0);
	else if (std::cin.eof())
		return (0);
	if (str == "ADD")
	{
		pb->add_contact();
		return (1);
	}
	if (str == "SEARCH")
	{
		pb->search_contact();
		return (1);
	}
	if (str == "EXIT")
	{
		std::cout << "phone book closed" << std::endl;
		return (2);
	}
	else
		std::cout << "Error: commands: ADD, SEARCH, EXIT" << std::endl;
	return (0);
}

int	main(void)
{
	phone_book	pb;
	std::string str;
	int			x;

	x = 0;
	while (x != 2)
	{
		x = command_choice(&pb, str);
		if (x == 2)
			return (1);
	}
	return (1);
}


