/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:30:35 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/16 15:38:45 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"
#include "cstdio"

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

int	is_printable(std::string str)
{
	const char *temp;
	int			i;

	i = 0;
	temp = str.c_str();
	while (temp[i])
	{
		if (std::isprint(temp[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_white(std::string str)
{
	const char *temp;
	int			i;

	i = 0;
	temp = str.c_str();
	while (temp[i])
	{
		if (std::iswspace(temp[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

std::string get_info(const char *str)
{
	std::string res;
	int			x;
	
	x = 0;
	res = "";
	while (x == 0)
	{
		std::cout << str, getline(std::cin, res);
		if (std::cin.bad())
		{
			std::cout << "Error: " << std::endl;
			x = 0;
		}
		else if (std::cin.eof())
			exit(1);
		else if (res.empty())
		{
			std::cout << "Error: empty" << std::endl;
			x = 0;
		}
		else if (is_printable(res) == 0)
		{
			std::cout << "Error: non printable" << std::endl;
			x = 0;
		}
		else if (is_white(res) == 1)
		{
			std::cout << "Error: empty" << std::endl;
			x = 0;
		}
		else
			x = 1;
	}
	return (res);
}

int	command_choice(phone_book *pb, std::string str)
{
	std::cout << "Command: " , getline(std::cin, str);
	if (std::cin.bad())
		return (0);
	else if (std::cin.eof())
		return (2);
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


