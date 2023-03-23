/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:20:51 by atabiti           #+#    #+#             */
//   Updated: 2023/03/23 21:08:21 by archid           ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "user.hpp"

#define CLIENT_MAX_NICKNAME 9
#define NUM_DIGITS 5
#define PASSWD_SIZE 32

int parse_command(std::string &input , const int fd);
void parse_args(int argc, char *argv[], int &num_port, std::string &passwd);

int	check_PASS(std::vector<std::string> const &splited_line , user *tmp);
// int check_NICK(std::vector<std::string> const & splited_line);
int	check_NICK(std::vector<std::string> const &splited_line, user *tmp);
// int check_USER(std::vector<std::string> const & splited_line);
int	check_USER(std::vector<std::string> const &splited_line, user *tmp);
int check_OPER(std::vector<std::string> const & splited_line);
int check_QUIT(char	*str1, std::string const & back_up_input);
int check_JOIN(std::vector<std::string>  & splited_line);
int check_PART(std::vector<std::string>  & splited_line);
// int check_PRIVMSG(std::vector<std::string>  & splited_line);
int	check_PRIVMSG(std::vector<std::string> &splited_line , std::string &back_up);
int	check_NOTICE(std::vector<std::string> &splited_line, std::string &back_up_input);