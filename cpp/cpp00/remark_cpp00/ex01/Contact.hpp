/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:36:01 by jlim              #+#    #+#             */
/*   Updated: 2022/01/23 21:36:02 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	int	_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nick_name;
	std::string	_phone_number;
	std::string	_darkest_secret;

public:
	void	set_index(int _index); //_index를 설정하는 함수
	void	set_first_name(std::string _first_name); //_first_name을 설정하는 함수
	void	set_last_name(std::string _last_name); //_last_name을 설정하는 함수
	void	set_nick_name(std::string _nick_name); //_nick_name을 설정하는 함수
	void	set_phone_number(std::string _phone_number); //_phone_number을 설정하는 함수
	void	set_darkest_secret(std::string _darkest_secret); //_darkest_secret을 설정하는 함수
	int		get_index(void); //index값을 가져오는 함수
	std::string	get_first_name(void); //_first_name값을 가져오는 함수
	std::string	get_last_name(void); //_last_name값을 가져오는 함수
	std::string get_nick_name(void); //_nick_name값을 가져오는 함수
	std::string	get_phone_number(void); //_phone_number값을 가져오는 함수
	std::string	get_darkest_secret(void); //_darkest_secret값을 가져오는 함수
};

#endif
