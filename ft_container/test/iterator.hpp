#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterators_traits.hpp"

namespace ft
{
	//************************iterator
	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
	//************************************iterator tag

	template <bool is_valid, typename T, bool is_random>
	struct valid_iterator_tag_base
	{
		typedef T	type;
		static const bool	value = is_valid;
		static const bool	random = is_random;
	};

	template <class T>
	struct is_ft_iterator_tagged : public valid_iterator_tag_base<false, T, false> {};

	template <>
	struct is_ft_iterator_tagged<ft::input_iterator_tag> :
		public valid_iterator_tag_base<true, ft::input_iterator_tag, false> {};
	
	template <>
	struct is_ft_iterator_tagged<ft::output_iterator_tag> :
		public valid_iterator_tag_base<true, ft::output_iterator_tag, false> {};
	
	template <>
	struct is_ft_iterator_tagged<ft::forward_iterator_tag> :
		public valid_iterator_tag_base<true, ft::forward_iterator_tag, false> {};
	
	template <>
	struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag> :
		public valid_iterator_tag_base<true, ft::bidirectional_iterator_tag, false> {};
	
	template <>
	struct is_ft_iterator_tagged<ft::random_access_iterator_tag> :
		public valid_iterator_tag_base<true, ft::random_access_iterator_tag, true> {};

	//random_access iterator일 때는 +나 -를 사용하여 바로 계산
	//다른 iterator일 때는 ++과 --를 계속해서 계산
	template <class InputIterator, class Distance>
	void	advance(InputIterator& it, Distance n)
	{
		bool	is_random = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::random;
		if (is_random == true)
			it += n;
		else
		{
			for (Distance i = 0;  i < n; i++)
				++it;
		}
	}
	//random_access iterator일 때는 +나 -를 사용하여 바로 계산
	//다른 iterator일 때는 ++과 --를 계속해서 계산
	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	distance(
		InputIterator first, InputIterator last)
	{
		bool	is_random = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::random;
		typename ft::iterator_traits<InputIterator>::difference_type	tmp = 0;
		if (is_random == true)
			tmp = last - first;
		else
		{
			while (first != last)
				++first; ++tmp;
		}
		return (tmp);
	}

	//**************************iterator tag가 잘못되었을 때 던지는 exception
	template <typename T>
	class InvalidIteratorException : public std::exception
	{
		private:
			std::string	_msg;
		
		public:
			InvalidIteratorException() throw() { _msg = "Is invalid iterator tag : " + std::string(typeid(T).name()); }
			InvalidIteratorException (const InvalidIteratorException&) throw() {}
			InvalidIteratorException&	operator=(const InvalidIteratorException&) throw() {}
			virtual ~InvalidIteratorException() throw() {}
			virtual const char* what() const throw() { return (_msg.c_str()); }
	};

}



#endif