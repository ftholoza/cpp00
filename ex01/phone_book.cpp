/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:30:35 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/12 19:02:25 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.h"

contact :: contact(int i, char *fn, char *ln, char *nn, char *nbr, char *ds)
{
	this->index = i;
	this->first_name = fn;
	this->last_name = ln;
	this->nickname = nn;
	this->phone_number = nbr;
	this->darkest_secret = ds;
}

void	contact :: print()
{
	std::cout << "index: " << index  << std::endl;
	std::cout << "Fisrt name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
}

int	main(void)
{
	char	fn[20];
	char	ln[20];
	char	nn[20];
	char	nbr[20];
	char	ds[20];

	std::cin >> fn;
	std::cin >> ln;
	std::cin >> nn;
	std::cin >> nbr;
	std::cin >> ds;
	contact n1(0, fn, ln, nn, nbr, ds);
	n1.print();
}


