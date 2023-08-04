/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:33:59 by jlim              #+#    #+#             */
/*   Updated: 2021/02/19 16:01:40 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	rm_low(void *s);

int		main(void)
{
	/*
	//memset 확인
	char str[30] = "hello, my world";
	printf("======memset======\n");
	printf("%s\n", str);
	memset(str, '-', 5);
	printf("memset : %s\n", str);
	ft_memset(str, '*', 2);
	printf("ft_memset : %s\n\n", str);

	//bzero 확인
	int n;
	char str_bzero[30] = "hello, my world";
	printf("======bzero======\n");
	puts(str_bzero);
	n = 5;
	//bzero(str_bzero, n);
	ft_bzero(str_bzero, n);
	while (n < 10)
		printf("%c", str_bzero[n++]);
	

	//memcpy 확인
	char str_memcpy1[30] = "123456";
	char str_memcpy2[5];
	char str_memcpy3[5];
	int	c_memcpy = 6;
	printf("======memcpy======\n");
	memcpy(str_memcpy2, str_memcpy1, c_memcpy);
	printf("memcpy : %s\n", str_memcpy2);
	ft_memcpy(str_memcpy3, str_memcpy1, c_memcpy);
	printf("ft_memcpy : %s\n", str_memcpy3);
	//memcpy((void *)0, (void *)0, 3);
	//ft_memcpy((void *)0, (void *)0, 3);

	*/	
/*	
	//memccpy 확인
	char str_memccpy1[30] = "zyxwvutsrqponmlkjihgfedcba";
	char str_memccpy2[30];
	char str_memccpy3[30];
	int	c_memccpy = 'a';
	int	len_memccpy = 26;
	printf("======memccpy======\n");
	printf("%s\n", str_memccpy1);
	memccpy(str_memccpy2, str_memccpy1, c_memccpy, len_memccpy);
	printf("%s\n", str_memccpy2);
	ft_memccpy(str_memccpy3, str_memccpy1, c_memccpy, len_memccpy);
	printf("ft_memccpy : %s\n", str_memccpy3);
	
	//memmove 확인
	char str_memmove1[30] = "I want to play witcher3";
	//char str_memmove2[30];
	printf("======memmove======\n");
	memmove(str_memmove1, str_memmove1 + 4, 7);
	printf("%s\n", str_memmove1);
	//ft_memmove(str_memmove1, str_memmove1 + 4, 7);
	//printf("%s\n", str_memmove1);
	

	//memchr 확인
	char str_memchr[50] = "I want to stop this fucking shit";
	int number1;
	int number2;
	printf("======memchr======\n");
	number1 = (int)memchr(str_memchr, 'p', 40) - (int)str_memchr + 1;
	printf("%d\n", number1);
	number2 = (int)ft_memchr(str_memchr, 'p', 40) - (int)str_memchr + 1;
	printf("%d\n", number2);
	

	//memcmp 확인
	char str_memcmp1[30] = "ab\x02";
	char str_memcmp2[30] = "ab\xff";
	int i_memcmp = 8;
	int a = 100;
	int b = 200;
	char d = b;
	char c = a - d;
	printf("======memcmp======\n");
	printf("%d ", memcmp(str_memcmp1, str_memcmp2, i_memcmp));
	printf("%d\n", ft_memcmp(str_memcmp1, str_memcmp2, i_memcmp));
	printf("idi : %d %d %d %d\n", (char)c, (unsigned char)a, (unsigned char)b, d);
	
	//strlen 확인
	char str_strlen[30] = "1234567";
	printf("%lu\n", strlen(str_strlen));
	printf("%lu\n", ft_strlen(str_strlen));
	

	//strlcpy 확인
	char str_strlcpy1[30] = "1234\0as";
	char str_strlcpy2[10];
	char str_strlcpy3[10];
	int	c_strlcpy = 10;
	printf("======strlcpy======\n");
	printf("%lu\n%s\n", strlcpy(str_strlcpy2, str_strlcpy1, c_strlcpy), str_strlcpy2);
	printf("%lu\n%s\n", ft_strlcpy(str_strlcpy3, str_strlcpy1, c_strlcpy), str_strlcpy3);
	printf("%d %c\n", '\x0', '\x41');
	

	//strlcat 확인
	char	str_strlcat1[15] = "abcdefghikjlmno";
	char	str_strlcat2[30] = "idiot";
	char	str_strlcat3[15] = "abcdefghijklmno";
	char	str_strlcat4[30] = "0123456789";
	int	i_strlcat = 5;
	printf("======strlcat======\n");
	printf("%lu\n%s\n", strlcat(str_strlcat1, str_strlcat2, i_strlcat), str_strlcat1);
	printf("%lu\n%s\n", ft_strlcat(str_strlcat3, str_strlcat4, i_strlcat), str_strlcat3);
	


	//strchr 확인
	char	str_strchr1[30] = "";
	char	c_strchr = 'a';
	printf("s : %s\n", strchr(str_strchr1, c_strchr));
	printf("ft : %s\n", ft_strchr(str_strchr1, c_strchr));
	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	char *d1 = strchr(src, '\0');
	char *d2 = ft_strchr(src, '\0');
	printf("strchr : %s\nft : %s\n", d1, d2);

	
	//strrchr 확인
	char	str_strrchr[30] = "I want to eat chocholate!!";
	char	c_strrchr = 'f';
	printf("%s\n", strrchr(str_strrchr, c_strrchr));
	printf("%s\n", ft_strrchr(str_strrchr, c_strrchr));
	*/
/*	
	//strnstr 확인
	char	str_strnstr[30] = "I want 1t to eat rice?!?!";
	char	find_strnstr[30] = "I want 1t to eat rice?!?!";
	int	i_strnstr = strlen(str_strnstr);
	printf("%s\n", strnstr(str_strnstr, find_strnstr, i_strnstr));
	printf("%s\n", ft_strnstr(str_strnstr, find_strnstr, i_strnstr));
char *s1 = "MZIRIBMZIRIBMZE123";
	char *s2 = "MZIRIBMZE";
	size_t max = strlen(s2);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);
	printf("%s %s\n", i1, i2);

	//strncmp 확인
	char	str_strncmp1[50] = "It is final motherfucker!!";
	char	str_strncmp2[50] = "Z";
	int	i_strncmp = 0;
	printf("%d\n", strncmp(str_strncmp1, str_strncmp2, i_strncmp));
	printf("%d\n", ft_strncmp(str_strncmp1, str_strncmp2, i_strncmp));

	char *s1 = "\200";
	char *s2 = "\0";
		
	printf("%d %d\n", strncmp(s1, s2, 1), ft_strncmp(s1, s2, 1));
	printf("%d %d\n", '\200', '\0');
*/	
/*
	//atoi 확인
	char	str_atoi[30] = "99999999999999999999999999";
	printf("atoi : %d\n", atoi(str_atoi));
	printf("ft_atoi : %d\n", ft_atoi(str_atoi));
*/	
/*	
	//isalpha 확인
	int	c_isalpha = 't';
	printf("isalpha : %d\n", isalpha(c_isalpha));
	printf("ft_isalpha : %d\n", ft_isalpha(c_isalpha));
	

	//isdigit 확인
	int	c_isdigit = '~';
	printf("isdigit : %d\n", isdigit(c_isdigit));
	printf("ft_isdigit : %d\n", ft_isdigit(c_isdigit));


	//isalnum 확인
	int	c_isalnum = '~';
	printf("isalnum : %d\n", isalnum(c_isalnum));
	printf("ft_isalnum : %d\n", ft_isalnum(c_isalnum));
	

	//isascii 확인
	int	c_isascii = 127;
	printf("isascii : %d\n", isascii(c_isascii));
	printf("ft_isascii : %d\n", ft_isascii(c_isascii));
	

	//isprint 확인
	int	c_isprint = 126;
	printf("isprint : %d\n", isprint(c_isprint));
	printf("ft_isprint : %d\n", ft_isprint(c_isprint));


	//toupper 확인
	int	c_toupper = '!';
	printf("toupper : %c\n", toupper(c_toupper));
	printf("ft_toupper : %c\n", ft_toupper(c_toupper));

	//tolower 확인
	int	c_tolower = '!';
	printf("tolower : %c\n", tolower(c_tolower));
	printf("ft_tolower : %c\n", ft_tolower(c_tolower));
*/

/*
	//calloc check

		int size = 0;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	if (memcmp(d1, d2, size * sizeof(int)))
		printf("fuck you\n");
	free(d1);
	free(d2);


	//strdup check	
	char *str;
	char *tmp = "HAHAHA \0 tu me vois pas !";

	str = ft_strdup(tmp);
	printf("strd : %s\n", ft_strdup(tmp));
	free(str);

	//substr check
	char	*s_substr = "fuck you idiot";
	printf("%s\n", ft_substr(s_substr, 400, 20));
	

	//ft_strjoin check
	char	*s_strjoin1 = "fuck";
	char	*s_strjoin2 = "you";
	printf("%s\n", ft_strjoin(s_strjoin1, s_strjoin2));


	//ft_strtrim check
	char	*s_strtrim1 = "a";
	char	*s_strtrim2 = "f\n\t ";
	printf("%s\n", ft_strtrim(s_strtrim1, s_strtrim2));
	char *s1 = "abc";
	char *s2 = "lorem ipsum dolor sit amet";
	char *s3 = "";
	char s4[10];
	s4[0] = '1';
	char *ret = ft_strtrim(s1, "abc");
	printf("s1 : %s\ns2 : %s\n", ret, ft_strtrim(s2, "tel"));
	printf("%d\n%s", strcmp(ret, s3), s4);

*/	
	//ft_split check
	char	*s_split = "";
	char	c_split = ' ';
	char	**result = ft_split(s_split, c_split);
	printf("%s\n", s_split);
	if (!s_split)
		printf("fuck\n");
	for (int i = 0; i<12; i++)
		printf("%s\n", *result++);
/*
	//ft_itoa check
	int	n_itoa = -2147483647;
	printf("%s %s %s\n", ft_itoa(n_itoa), ft_itoa(123), ft_itoa(0));
	

	//ft_strmapi check
	char	*s_strmapi = "FUCK YOU IDIOT";
	
	printf("%s\n", ft_strmapi(s_strmapi, ft_lowup));


	//ft_putchar_fd check
	char	c_putchar = 'a';
	ft_putchar_fd(c_putchar, 1);
	

	//ft_putstr_fd check
	char	*s_putstr = "fuck you idiot";
	ft_putstr_fd(s_putstr, 1);

	//ft_putendl_fd check
	char	*s_putendl = "fuck you idiot";
	ft_putendl_fd(s_putendl, 1);
	
	
	//ft_putnbr_fd check
	int	n_putnbr = 0;
	ft_putnbr_fd(n_putnbr, 1);


	//ft_lstadd_front check
	t_list *l_lstadd = ft_lstnew(strdup("nyacat"));
	t_list *n_lstadd = ft_lstnew(strdup("OK"));

	ft_lstadd_front(&l, n);
	printf("%s\n", l->content);
	printf("%s\n", l->next->content);
	if (l == n)
		printf("yaho\n");
	if (!strcmp(l->content, "OK"))
		printf("si\n");	

	//ft_lstadd_back check
	t_list	*a_lst_b = ft_lstnew(strdup("nyacat"));
	t_list	*b_lst_b = ft_lstnew(strdup("OK"));
	t_list	*c_lst_b = ft_lstnew(strdup("fuck"));

	ft_lstadd_back(&a_lst_b, b_lst_b);
	ft_lstadd_back(&a_lst_b, c_lst_b);
	printf("a : %s\nb : %s\n", a_lst_b->content, b_lst_b->content);
	printf("c : %s\n", a_lst_b->next->next->content);
	
	//ft_lstiter check
	t_list	*l_lstiter = ft_lstnew(strdup("SIBAL"));
	ft_lstiter(l_lstiter, rm_low);
	printf("%s\n", l_lstiter->content);

	
	//ft_lstmap check
	t_list	*lst_lstmap = ft_lstnew(strdup("sibal"));
	t_list	*ret_lstmap;
	printf("lst : %s\n", lst_lstmap->content);
	//lst_lstmap->next = ft_lstnew(strdup("fuck"));
	ret_lstmap = ft_lstmap(lst_lstmap, (void *)rm_low, (void *)0);
	printf("ret : %s \n", ret_lstmap->content);
	*/
}
