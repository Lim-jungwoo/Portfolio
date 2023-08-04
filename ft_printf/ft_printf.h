/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:13:45 by jlim              #+#    #+#             */
/*   Updated: 2021/06/09 16:32:46 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "./libft/libft.h"
#define ONLYDOT 2
#define DOTNUM 1
#define NODOT 0
#define YES 1
#define NO 0

/// @brief store printf format
typedef struct s_info
{
	/// @brief -가 있는지 확인한다. -가 있으면 왼쪽 정렬, 없으면 오른쪽 정렬
	int f_hyphen;
	/// @brief 0가 있는지 확인한다. 0가 있으면 빈 공간은 0으로 채우고, 없으면 공백으로 채운다.
	int f_zero;
	/// @brief width의 값을 확인한다.
	int w_num;
	/// @brief precision의 값을 확인한다.
	int p_num;
	int p_is;
	/// @brief precision이 *인지 확인한다.
	int p_ast;
} t_info;

int ft_printf(const char *format, ...);
int parse_arg(va_list *ap, const char *format);
void init_info(t_info *info);
char *check_info(va_list *ap, const char *spec, t_info *info);
const char *check_spec(va_list *ap, const char *spec,
					   t_info info, int *print_len);
int print_char(const char *spec, char *str,
			   t_info info, size_t len);
int print_num(char *str, t_info info, int sign);
int apply_percent(const char *spec, t_info info, int *print_len);
int apply_char(va_list *ap, const char *spec,
			   t_info info, int *print_len);
int apply_str(va_list *ap, const char *spec,
			  t_info info, int *print_len);
int apply_pointer(va_list *ap, const char *spec,
				  t_info info, int *print_len);
int apply_int(va_list *ap, t_info info, int *print_len);
int apply_unint(va_list *ap, t_info info, int *print_len);
int apply_hex(va_list *ap, const char *spec,
			  t_info info, int *print_len);
char *change_hex(size_t num, const char *spec);

#endif
