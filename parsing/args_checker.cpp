/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:23:40 by atabiti           #+#    #+#             */
/*   Updated: 2023/03/13 09:13:14 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"
#include <iostream>
#include <stdlib.h> //for atoi
std::string PASSWORD;

/*
		Command: PASS
	Parameters: <password> (RFC 1459)
	ERRORS : ERR_ALREADYREGISTRED  ERR_NEEDMOREPARAMS
*/
int	check_PASS(std::vector<std::string> const &splited_line)
{
	if (splited_line.size() != 2)
	{
		std::cerr << "461 " << splited_line[0] << " :Not enough parameters" << std::endl;
	}
	else
	{
		if (splited_line[1] != PASSWORD)
		{
			std::cerr << "464 " << splited_line[0] << " :Password incorrect" << std::endl;
			return (0);
		}
	}
	return (0);
}

int	checker(int ac, char **av)
{
	size_t	i;
	int		port;

	if (ac != 3)
	{
		std::cerr << "ERROR: Your executable should be run as follows: \t./ircserv <port> <password>" << std::endl;
		return (0);
	}
	else
	{
		std::string port_checking(av[1]);
		std::string password_checking(av[2]);
		i = 0;
		while (i < port_checking.size())
		{
			if (!(std::isdigit(port_checking[i])))
			{
				std::cerr << "ERROR: <port> must be numeric" << std::endl;
				return (0);
			}
			i++;
		}
		port = atoi(av[1]);
		/*Port numbers from 0 to 1023 are reserved for common TCP/IP applications and are called well-known ports.*/
		if (port < 0 || port > 65353)
		{
			std::cerr << "ERROR: <port> must be between 0  and 65353" << std::endl;
			return (0);
		}
		if (port >= 0 && port <= 1023)
		{
			std::cerr << "ERROR: Port numbers from 0 to 1023 are reserved for common TCP/IP applications" << std::endl;
			return (0);
		}
		PASSWORD = password_checking;
		std::cerr << "PASSWORD " << PASSWORD << std::endl;
		if (password_checking.empty()
			|| password_checking.find_first_of(" ") < password_checking.size())
		{
			std::cerr << "ERROR:problem in the password : Please check again " << std::endl;
			return (0);
		}
	}
	return (1);
}