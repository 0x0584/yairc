/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:22:56 by atabiti           #+#    #+#             */
/*   Updated: 2023/03/08 09:25:50 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <vector>

int	parse_coommand(void)
{
	size_t i;
	/*

  1235 642 TEXT 0-=+ aKU
*/
	while (1)
	{
		std::vector<std::string> splited_line;
		std::string input;
		std::string back_up_input;
		std::getline(std::cin, input); // read a line
		back_up_input = input;
		// std::cout << "before input = " << input << std::endl << std::endl;
		if (!input.empty())
		{
			/*const_cast <new_type> (expression) why? strtok uses char
				* and input.c_str() return const char* */
			char *str = const_cast<char *>(input.c_str());
			/* 
            strtok() stores the pointer in static variable where did you last time left off ,
	
            so on its 2nd call , when we pass the null ,
	strtok() gets the pointer from the static variable .
            If you provide the same string name ,
	it again starts from beginning.
    */
			str = strtok(str, " ");
			// std::cout << "after input = " << input << std::endl << std::endl;
			if (str != NULL)
			{
				while (str != NULL)
				{
					// std::cout << "str|" << str << std::endl;
					splited_line.push_back(str);
					str = strtok(NULL, " ");
				}

				i = 0;
				while (i < splited_line.size())
				{
					std::cout << "splited_line [] = " << splited_line[i] << std::endl;
					i++;
				}
				/*
 		Command: PASS 
	Parameters: <password> (RFC 1459)
    ERRORS : ERR_ALREADYREGISTRED  ERR_NEEDMOREPARAMS
*/
				if (splited_line[0] == "PASS")
				{
					std::cout << "PASS Command" << std::endl;
					if (splited_line.size() != 2)
					{
						std::cerr << "461 " << splited_line[0] << " :Not enough parameters" << std::endl;
					}
				}
				/*
					Command: NICK
	NICK <nickname> [<hopcount>] (RFC 1459)
	NICK <nickname> (RFC 2812)
    ERRORS : ERR_NONICKNAMEGIVEN   ERR_ERRONEUSNICKNAME   ERR_NICKNAMEINUSE        ERR_NICKCOLLISION
*/

				if (splited_line[0] == "NICK")
				{
					std::cout << "NICK Command" << std::endl;
					if (splited_line.size() != 2)
					{
						std::cerr << "431 " << splited_line[0] << " :No nickname given" << std::endl;
					}
				}

				/*
				 	Command: USER 
	USER <username> <hostname> <servername> <realname> (RFC 1459)
	USER <user> <mode> <unused> <realname> (RFC 2812)
*/
				if (splited_line[0] == "USER")
				{
					std::cout << "PASS USER" << std::endl;
					if (splited_line.size() > 5 || splited_line.size() < 5)
					{
						std::cerr << "461 " << splited_line[0] << " :Not enough parameters" << std::endl;
					}
					std::cout << "USER is found" << std::endl;
				}

				/*			Command: SERVER
   Parameters: <servername> <hopcount> <info> 
*/

				// if (splited_line[0] == "SERVER")
				// {
				// 	std::cout << "SERVER command" << std::endl;
				// 	if (splited_line.size() != 1)
				// 		std::cerr << "SERVER  parameters error " << std::endl;
				// }

				/*
					Command: OPER   Parameters: <user> <password>
	OPER message is used by a normal user to obtain operator privileges.
The combination of <user> and <password> are required to gain
Operator privileges.
*/
				if (splited_line[0] == "OPER")
				{
					if (splited_line.size() != 2)
					{
						std::cerr << "461 " << splited_line[0] << " :Not enough parameters" << std::endl;
					}
				}
				/*
			Command: QUIT
  				Parameters: [<Quit message>]
	*/
				if (splited_line[0] == "QUIT")
				{
					char *str1 = const_cast<char *>(back_up_input.c_str());
					str1 = strtok(str1, ":");
					str1 = strtok(NULL, ":");
					if(str1 != NULL)
					{
							/*  If a "Quit Message" is given, this will be sent instead of the default message, the nickname. */
						std::cerr << "ERROR :Closing link: ["<<str1 <<"]" << std::endl; // str1 is the full message  without : ERROR :Closing link: (asd@localhost) [Gone to have lunch]
					}
					if(str1  == NULL)
					{
						std::cerr << "ERROR :Closing link: [Client exited]" << std::endl; // ERROR :Closing link: (atabiti@localhost) [Client exited]
							
					}
					
				}
			}
		}
	}
}