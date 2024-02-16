/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:05:38 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/16 14:06:16 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

contact :: contact()
{
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