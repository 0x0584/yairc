/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:13:39 by archid            #+#    #+#             */
/*   Updated: 2023/03/24 04:57:44 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <climits>
#include <iostream>
#include "../headers/server.hpp"

void handler(int) {
	ircserv.terminate();
	exit(0);
}

int main(int argc, char *argv[]) {
	int port = 1;
	std::string passwd = "1";

	signal(SIGINT, handler);
	// parse_args(argc, argv);

	try {
		ircserv = server(port, passwd.c_str());
		ircserv.run();
		return EXIT_SUCCESS;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
}

server ircserv;
