#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "utils.hpp"

namespace ft
{
	template <class Iterator>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, Iterator>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::value_type			value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::reference			reference;
			//왜 그냥 Iterator형으로 했을까
			//typedef Iterator*	pointer;
			//typedef Iterator&	reference;
		
		private:
			pointer	_random_it;

		public:
			//NULL로 초기화하지 않는다면 어떻게 되나
			random_access_iterator() : _random_it(NULL) {}
			random_access_iterator(pointer it) : _random_it(it) {}
			random_access_iterator(const random_access_iterator& random_it) : _random_it(random_it._random_it) {}
			
			virtual ~random_access_iterator() {}

			pointer	base() const { return (_random_it); }
			reference	operator*() const { return (*_random_it); }
			random_access_iterator	operator+(difference_type n) const
			{ return (_random_it + n); }
			random_access_iterator&	operator++()
			{
				++_random_it;
				return (*this);
			}
			random_access_iterator	operator++(int)
			{
				random_access_iterator	tmp = *this;
				++_random_it;
				return (tmp);
			}
			random_access_iterator&	operator+=(difference_type n)
			{
				_random_it += n;
				return (*this);
			}

			random_access_iterator	operator-(difference_type n) const
			{ return (_random_it - n); }
			random_access_iterator&	operator--()
			{
				--_random_it;
				return (*this);
			}
			random_access_iterator	operator--(int)
			{
				random_access_iterator	tmp = *this;
				--_random_it;
				return (tmp);
			}
			random_access_iterator&	operator-=(difference_type n)
			{
				_random_it -= n;
				return (*this);
			}

			pointer	operator->() { return &(operator*()); }
			reference	operator[](difference_type n)
			{ return (base()[n]); }

			//이건 어따 쓰는 거여
			// operator	random_access_iterator<const Iterator>() const
			// { return (random_access_iterator<const Iterator>(_random_it)); }
	};

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type	operator==(
		const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{ return (lhs.base() == rhs.base()); }

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type	operator!=(
		const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{ return (lhs.base() != rhs.base()); }

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type	operator<(
		const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{ return (lhs.base() < rhs.base()); }

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type	operator>(
		const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{ return (lhs.base() > rhs.base()); }

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type	operator>=(
		const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{ return (lhs.base() >= rhs.base()); }

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type	operator<=(
		const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{ return (lhs.base() <= rhs.base()); }

	template <typename T>
	ft::random_access_iterator<T>	operator+(
		typename ft::random_access_iterator<T>::difference_type n,
		typename ft::random_access_iterator<T>& rai)
	{ return (&(*rai) + n); }

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type	operator-(
		const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{ return (lhs.base() - rhs.base()); }
}

#endif