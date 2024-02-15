/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:30:55 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/15 18:09:06 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>
# include <string>


class contact
{
	private:
		int		index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		contact();
		~contact();
		std::string	get_first();
		std::string	get_last();
		std::string	get_nick();
		std::string	get_number();
		std::string	get_secret();
		int			get_index();
		void		set_index(int index);
		void		delete_contact();
		void		set_first(std::string str);
		void		set_last(std::string str);
		void		set_nick(std::string str);
		void		set_number(std::string str);
		void		set_secret(std::string str);
};

class phone_book
{
	private:
		int		index;
		contact	contacts[8];
	public:
		phone_book();
		~phone_book();
		void	print();
		void	add_contact();
		void	search_contact();
		contact get_contact(int index);	
};

#endif
