/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:11:23 by archid            #+#    #+#             */
//   Updated: 2023/03/27 21:22:01 by archid           ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "command.hpp"
#include "server.hpp"
#include "user.hpp"

void authenticate(const std::string &msg, const int fd) {
	user *usr = ircserv.user(fd);
	if (msg.find("NICK ") != std::string::npos && usr->nickname().empty())
    {
			if (msg.length() > 6){
				usr->nickname(msg.substr(5));
				std::cout << "nick name set\n";
				return ;
			}
    }

	if (msg.find("USER ") != std::string::npos && usr->username().empty()) {
		if (msg.length() > 6)
			{
				usr->username(msg.substr(5));
				std::cout << "user set\n";
				return ;
			}
	}

	if (msg.find("PASS ") != std::string::npos)
    {
			if (msg.length() > 6){
				std::string tmp1 = msg.substr(5);
				if (tmp1 == "123")
					{
						return ;
					}
				std::cerr << "464 " << "PASS" << " :Password incorrect" << tmp1 <<"|"<< std::endl;
			}
			send(fd, "wrong arg\n", 10, 0);
		}
}

command *parse_command(const std::string &msg, int fd) {
}

int exec_command(const std::string &msg) {
}
