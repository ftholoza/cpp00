/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:30:55 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/12 18:59:59 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>

class phone_book
{
	private:
		char	**contact;
	public:
		phone_book(char *contact);
		char	*get_contact();
		
};

class contact
{
	private:
		int		index;
		char	*first_name;
		char	*last_name;
		char	*nickname;
		char	*phone_number;
		char	*darkest_secret;
	public:
		contact(int i, char *fn, char *ln, char *nn, char *nbr, char *ds);
		void	print();
};

#endif
