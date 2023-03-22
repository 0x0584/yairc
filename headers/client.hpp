/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:21:35 by archid            #+#    #+#             */
/*   Updated: 2023/03/21 00:51:26 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <string>

namespace yairc {
	class client {

		int client_fd_;
		std::string nickname_, username_;
		//std::vector<channel_ptr> channels_;

	public:
		typedef client *client_ptr;

		client(int client_fd);
		const std::string &nickname() const { return nickname_; }
		void nickname(std::string nickname) {
			nickname_ = nickname;
		}

		const std::string &username() const { return username_; }
		void username(std::string username) {
			username_ = username;
		}

	};

	typedef client::client_ptr client_ptr;
} // namespace yairc
#endif