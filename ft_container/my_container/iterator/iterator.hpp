#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterators_traits.hpp"
# include <exception>
# include <typeinfo>
# include <string>

//delete
# include <iostream>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T 			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <bool is_valid, class T, bool is_random>
	struct iterator_tag
	{
		typedef T	type;
		static const bool	value = is_valid;
		static const bool	random = is_random;
	};

	template <class T>
	struct is_iterator_tag : public iterator_tag<false, T, false> {};

	template <>
	struct is_iterator_tag<ft::input_iterator_tag> :
		public iterator_tag<true, ft::input_iterator_tag, false> {};
	
	template <>
	struct is_iterator_tag<ft::output_iterator_tag> :
		public iterator_tag<true, ft::output_iterator_tag, false> {};
	
	template <>
	struct is_iterator_tag<ft::forward_iterator_tag> :
		public iterator_tag<true, ft::forward_iterator_tag, false> {};
	
	template <>
	struct is_iterator_tag<ft::bidirectional_iterator_tag> :
		public iterator_tag<true, ft::bidirectional_iterator_tag, false> {};
	
	template <>
	struct is_iterator_tag<ft::random_access_iterator_tag> :
		public iterator_tag<true, ft::random_access_iterator_tag, true> {};

	//iterator형이 제대로 들어오지 않을 경우도 있으므로 예외사항을 만든다.
	template <class T>
	class InvalidIteratorException : public std::exception
	{
		public:
			std::string	msg;
			InvalidIteratorException() : msg(" is not iterator" + std::string(typeid(T).name())) {}
			// virtual ~InvalidIteratorException() throw() {}
			virtual ~InvalidIteratorException() throw() {}
			//이것이 없으면 제대로 작동하지 않는데 왜 그런지를 모르겠네
			const char *what() const throw()
			{
				return (msg.c_str());
			}
	};

	template <class InputIterator>
	void	_advance(InputIterator& it, typename ft::iterator_traits<InputIterator>::difference_type n,
		ft::input_iterator_tag)
	{
		for (typename ft::iterator_traits<InputIterator>::difference_type i = 0; i < n; i++)
			++it;
	}

	template <class InputIterator>
	void	_advance(InputIterator& it, typename ft::iterator_traits<InputIterator>::difference_type n,
		ft::output_iterator_tag)
	{
		for (typename ft::iterator_traits<InputIterator>::difference_type i = 0; i < n; i++)
			++it;
	}

	template <class InputIterator>
	void	_advance(InputIterator& it, typename ft::iterator_traits<InputIterator>::difference_type n,
		ft::forward_iterator_tag)
	{
		for (typename ft::iterator_traits<InputIterator>::difference_type i = 0; i < n; i++)
			++it;
	}

	template <class InputIterator>
	void	_advance(InputIterator& it, typename ft::iterator_traits<InputIterator>::difference_type n,
		ft::bidirectional_iterator_tag)
	{
		for (typename ft::iterator_traits<InputIterator>::difference_type i = 0; i < n; i++)
			++it;
	}

	template <class InputIterator>
	void	_advance(InputIterator& it, typename ft::iterator_traits<InputIterator>::difference_type n,
		ft::random_access_iterator_tag)
	{
		it += n;
	}
	
	//advance와 distance도 InputIterator가 iterator가 아닌 다른 타입일 때 예외를 던져야 할 것 같다.
	template <class InputIterator, class Distance>
	void	advance(InputIterator& it, Distance n,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
	{
		if (!(ft::is_iterator_tag<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
			throw (ft::InvalidIteratorException<typename ft::is_iterator_tag<typename ft::iterator_traits<InputIterator>::iterator_category>::type>());
		ft::_advance(it, n, typename ft::iterator_traits<InputIterator>::iterator_category());
	}

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	_distance(InputIterator first, InputIterator last,
		ft::input_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	tmp = 0;
		while (first != last)
		{
			++first; ++tmp;
		}
		return (tmp);
	}

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	_distance(InputIterator first, InputIterator last,
		ft::output_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	tmp = 0;
		while (first != last)
		{
			++first; ++tmp;
		}
		return (tmp);
	}

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	_distance(InputIterator first, InputIterator last,
		ft::forward_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	tmp = 0;
		while (first != last)
		{
			++first; ++tmp;
		}
		return (tmp);
	}

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	_distance(InputIterator first, InputIterator last,
		ft::bidirectional_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	tmp = 0;
		while (first != last)
		{
			++first; ++tmp;
		}
		return (tmp);
	}

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	_distance(InputIterator first, InputIterator last,
		ft::random_access_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	tmp = last - first;
		return (tmp);
	}

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	distance(
		InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
	{
		if (!(ft::is_iterator_tag<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
			throw (ft::InvalidIteratorException<typename ft::is_iterator_tag<typename ft::iterator_traits<InputIterator>::iterator_category>::type>());
		return (ft::_distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category()));
	}
}

#endif