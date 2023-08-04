/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:28:12 by jlim              #+#    #+#             */
/*   Updated: 2021/06/08 13:58:23 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	// 가변 인자 ap를 선언한다.
	va_list ap;
	int print_len;

	// 가변 인자 ap에 format 값들을 저장한다.
	va_start(ap, format);
	if ((print_len = parse_arg(&ap, format)) < 0)
	{
		// parse_arg에서 에러가 발생한 경우 가변 인자 ap를 정리하고 끝낸다.
		va_end(ap);
		return (-1);
	}
	// 가변 인자 ap를 정리한다.
	va_end(ap);
	return (print_len);
}
