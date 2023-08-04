/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:36:17 by jlim              #+#    #+#             */
/*   Updated: 2022/01/23 21:36:18 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

std::string	ft_truncate(std::string str);
//문자가 10개 이상일 때 9개만 표시하고 뒤에 .표시하는 함수

class PhoneBook
{
private:
	int	_index; //_index값을 저장
	Contact	_contact[8]; //Contact 8개 배열

public:
	int		flag; //입력된 값이 8개 미만이면 0, 8개 이상이면 1
	void	search_screen(void); //SEARCH 명령어를 사용했을 때 뜨는 화면
	void	add_contact(int index); //ADD 명령어를 사용했을 때 입력받는 화면
	void	reset_index(void); //index값을 다시 0으로 초기화
	void	show_contact(int index); //SEARCH 명령어를 사용하고 index값을 입력했을 때 정보 표시
};

#endif
