/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:17:55 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 20:04:02 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<string>

char	ft_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
			c = toupper(c);
	return (c);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (j < argc)
	{
		while (argv[j][i])
		{
			std::cout << ft_uppercase(argv[j][i]);
			i++;
		}
		i = 0;
		j++;
	}
	std::cout << std::endl;
	return (0);
}