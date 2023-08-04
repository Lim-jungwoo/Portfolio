/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:59:14 by jlim              #+#    #+#             */
/*   Updated: 2021/06/08 14:09:20 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief t_info 자료형을 모두 0으로 초기화한다.
void init_info(t_info *info)
{
	info->f_hyphen = 0;
	info->f_zero = 0;
	info->w_num = 0;
	info->p_num = 0;
	info->p_is = 0;
	info->p_ast = 0;
}

/// @brief parsing
/// @return 출력한 문자의 개수, 에러 발생시 -1
int parse_arg(va_list *ap, const char *format)
{
	const char *spec;
	int print_len;
	t_info spec_info;

	spec = format;
	print_len = 0;
	//* 문자열 spec를 돌면서 문자들을 출력한다.
	while (*spec)
	{
		// check %가 앞에 있으면 서식 지정자(format specifier)이다.
		if (*spec == '%')
		{
			spec++;
			init_info(&spec_info);
			if (!(spec = (const char *)check_info(ap, spec, &spec_info)))
				return (-1);
			if (!(spec = check_spec(ap, spec, spec_info, &print_len)))
				return (-1);
		}
		//* 서식 지정자가 아닌 기본 문자는 그냥 출력한다.
		else
		{
			ft_putchar_fd(*spec, 1);
			print_len++;
		}
		spec++;
	}
	return (print_len);
}
