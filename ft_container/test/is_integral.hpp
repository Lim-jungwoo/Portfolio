#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <bool is_integral>
	struct is_integral_base
	//value를 static const로 선언하는 이유를 알아야한다.
	{ static const bool	value = is_integral; };

	template <class T>
	//템플릿 특수화를 통해 특정 자료형을 제외한 나머지는 기본적으로 false로 한다.
	struct is_integral : public is_integral_base<false> {};

	template <>
	struct is_integral<bool> : public is_integral_base<true> {};

	template <>
	struct is_integral<char> : public is_integral_base<true> {};

	template <>
	struct is_integral<signed char> : public is_integral_base<true> {};

	template <>
	struct is_integral<short int> : public is_integral_base<true> {};

	template <>
	struct is_integral<int> : public is_integral_base<true> {};

	template <>
	struct is_integral<long int> : public is_integral_base<true> {};

	template <>
	struct is_integral<long long int> : public is_integral_base<true> {};

	template <>
	struct is_integral<unsigned char> : public is_integral_base<true> {};

	template <>
	struct is_integral<unsigned short int> : public is_integral_base<true> {};

	template <>
	struct is_integral<unsigned int> : public is_integral_base<true> {};

	template <>
	struct is_integral<unsigned long int> : public is_integral_base<true> {};

	template <>
	struct is_integral<unsigned long long int> : public is_integral_base<true> {};
}

#endif