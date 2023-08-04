#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	/*---------------------------------------------
	-------------apply_percent예외처리-------------
	---------------------------------------------*/

/*	
	//precision이 0보다 작고, *이 없을 때만 에러 발생
	printf("%.-3%\n"); //precision에 -가 들어왔다고 에러발생
	printf("%.%\n"); //.만 있을 때는 에러가 없다.
	printf("%.*%\n", 10); //'*'이 있고 precision이 0보다 크면 에러 없음
	//'*'이 있고 precision이 0보다 작아도 에러 없음
	printf("%.*%\n", -10);
	
	//width는 어떤 값이 들어오든 제대로 처리된다.
	printf("%10%\n");
	printf("%-10%\n");
	printf("%*%\n", -10);
*/


	/*---------------------------------------------
	-------------apply_char예외처리----------------
	---------------------------------------------*/

/*
	//(precision이 .뒤에 음수이거나 양수이거나 *일 때)이거나, flag에 0이 있을 때만 에러 발생
	char	apply_char_c = 'a';
	printf("%0c\n", apply_char_c); //flag에 0이 있을 때 에러 발생
	printf("%.4c\n", apply_char_c); //.다음에 양수가 있을 때 에러 발생
	printf("%.-4c\n", apply_char_c); //.다음에 음수가 있을 때 에러 발생
	printf("%.*c\n", 4, apply_char_c); //.다음에 '*'가 있을 때 에러 발생
	printf("%.c\n", apply_char_c); //.다음에 precision값이 없을 때는 에러 없음
	printf("%-c\n", apply_char_c); //flag에 -가 있을 때는 에러 없음

	//width는 어떤 값이 들어오든 제대로 처리된다.
	printf("%10c\n", apply_char_c);
	printf("%-10c\n", apply_char_c);

*/
	/*---------------------------------------------
	-------------apply_str예외처리-----------------
	---------------------------------------------*/

/*	
	//flag에 0이 있거나, (.이 있고 precision이 0보다 작고 precision에 *이 없을 때 에러 발생
	char	*apply_str_s = "checkerror";
	printf("%0s\n", apply_str_s); //flag에 0이 있을 때 에러 발생
	printf("%.-3s\n", apply_str_s); //precision이 음수이면  에러가 발생하고, precision의 절대값만큼 공백이 출력된다.
	printf("%.*s\n", -5, apply_str_s); //precision이 *이 있고, precision이 음수이면 precision값은 무시하고 그대로 출력이 된다. 에러 없음

	//precision이 .0이거나 .만 있을 때는 width만큼 공백만 출력
	printf("%10.s\n", apply_str_s); //precision이 .만 있을 때는 width만큼 공백만 출력
	printf("%10.0s\n", apply_str_s); //precision이 .0일 때도 width만큼 공백만 출력
	printf("%10.5s", apply_str_s); //precision이 양수이면 precision값만큼 문자열이 잘려서 출력이 되고, width에서 문자열 길이를 제외한 만큼 공백이 출력된다.

*/
	/*---------------------------------------------
	-------------apply_pointer예외처리-------------
	---------------------------------------------*/

/*
	//(precision이 .뒤에 음수이거나 양수이거나 *일 때)이거나, flag에 0이 있을 때 에러 발생
	void	*apply_pointer_p;
	printf("%.5p\n", apply_pointer_p); //precision이 양수이니까  에러 발생
	printf("%0p\n", apply_pointer_p); //flag에 0이 있으니 에러 발생
	printf("%.*p\n", 5, apply_pointer_p); //precision이 *이 있고 값이 양수이면 에러 발생
	printf("%.-5p\n", apply_pointer_p); //precision이 음수이니까 에러 발생
	printf("%.0p\n", apply_pointer_p); //precision이 0이여도 .뒤에 숫자가 있는 것이므로 에러 발생
	printf("%.p\n", apply_pointer_p); //precision이 .만 있으면 에러 없음

	//pointer가 0이고, precision이 .만 있으면 0x만 출력된다.
	apply_pointer_p = 0;
	printf("%.p\n", apply_pointer_p); //pointer가 0이고, precision이 .만 있어서 0x만 출력
	printf("%p\n", apply_pointer_p); //pointer가 0이고, precision이 없을 때는 0x0이 출력
	char	apply_pointer_c = 'a';
	apply_pointer_p = &apply_pointer_c;
	printf("%.p\n", apply_pointer_p); //pointer가 0이 아니고, precision이 .만 있을 때는 포인터 주소가 제대로 출력
*/

	/*---------------------------------------------
	-------------apply_int예외처리-----------------
	---------------------------------------------*/

/*	
	//precision이 음수이고, precision이 *이 아니라면 에러발생
	int	apply_int_d = 10;
	printf("%.-3d\n", apply_int_d); //precision이 음수이고, precision이 *가 아니면 에러발생
	printf("%.3d\n", apply_int_d); //preicision이 양수이고, precision이 *가 아니면 에러 없음
	printf("%.d\n", apply_int_d); //precision이 .만 있고, precision이 *가 아니면 에러 없음
	printf("%.*d\n", -3, apply_int_d); //precision이 음수이고, precision이 *이면 에러 없음
	//precision이 *이고 음수이면 precision은 없는 셈치고 출력
*/

	/*---------------------------------------------
	-------------apply_unint예외처리---------------
	---------------------------------------------*/

/*	
	//precision이 음수이고, precision이 *가 아니면 에러발생
	unsigned int	apply_unint_u = 10;
	printf("%.-3u\n", apply_unint_u); //precision이 음수이고, precision이 *가 아니면 에러발생
	printf("%.3u\n", apply_unint_u); //precision이 양수이고, precision이 *가 아니면 에러없음
	printf("%.u\n", apply_unint_u); //precision이 .만 있고, precision이 *가 아니면 에러 없음
	printf("%.*u\n", -3, apply_unint_u); //precision이 음수이고, *이 있을 때 에러 없음
	//precisiondl *이고 음수이면 precision은 없는 셈치고 출력
*/

	/*---------------------------------------------
	-------------apply_hex예외처리-----------------
	---------------------------------------------*/

/*	
	//precision이 음수이고, precision이 *가 아니면 에러발생
	int	apply_hex_x = 17;
	printf("%.-3x\n", apply_hex_x); //precision이 음수이고, precision이 *가 아니면 에러발생
	printf("%.3x\n", apply_hex_x); //precision이 양수이고, *이 없으면 에러 없음
	printf("%.x\n", apply_hex_x); //precision이 .만 있고, *이 없으면 에러 없음
	printf("%.*x\n", -3, apply_hex_x); //precision이 음수이고, *이 있으면 에러 없음
	printf("%-0x\n", apply_hex_x);
	ft_printf("%-0x\n", apply_hex_x);
*/

	/*---------------------------------------------
	-------------check_zero예외처리----------------
	---------------------------------------------*/

	//가변인자로 받은 변수가 0이고, precision이 .0이거나 .만 있을 경우에 width만큼 공백만 출력하고 종료
	int	check_zero_d = 0;
	printf("%10.0d\n", check_zero_d); //변수가 0이고, precision이 .0일 때 width만큼 공백 출력하고 종료
	printf("%10.d\n", check_zero_d); //변수가 0이고, precision이 .일 때 width만큼 공백 출력하고 종료
	printf("%10.5d\n", check_zero_d); //변수가 0이고, precision이 .숫자일 때 (width-precision)만큼 공백을 출력하고 precision만큼 0출력
	check_zero_d = 4;
	printf("%10.5d\n", check_zero_d);
	return (0);
}
