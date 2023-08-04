/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:56:56 by jlim              #+#    #+#             */
/*   Updated: 2022/01/23 18:56:57 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //표준 입출력 라이브러리, std::cout, std::cin, std::endl 등 포함
#include <cctype> //toupper
#include <string> //std::string

int	main(int argc, char **argv)
{
	std::string	str;
	std::string	ret;
	int			i;
	int			j;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < argc; i++)
		{
			str = argv[i];
			for (j = 0; str[j]; j++)
			{
				ret = static_cast<char>(std::toupper(str[j]));
				//toupper는 int형을 반환하므로 static_cast<char>을 통해 형 변환 시켜준다.
				std::cout << ret;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
