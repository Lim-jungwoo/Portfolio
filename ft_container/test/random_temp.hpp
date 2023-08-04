#ifndef RANDOM_temp_HPP
# define RANDOM_temp_HPP

# include "utils.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef T*	pointer;
			typedef T&	reference;

			random_access_iterator() : _elem(NULL) {}
			random_access_iterator(pointer elem) : _elem(elem) {}
			random_access_iterator(const random_access_iterator& it) : _elem(it._elem) {}

			random_access_iterator	&operator=(const random_access_iterator& it)
			{
				if (this == &it)
					return (*this);
				this->_elem = it._elem;
				return (*this);
			}

			virtual ~random_access_iterator() {}

			pointer	base() const { return (this->_elem); }
			reference	operator*() const { return (*_elem); }
			pointer	operator->() { return &(this->operator*()); }
			random_access_iterator&	operator++()
			{
				_elem++;
				return (*this);
			}
			random_access_iterator	operator++(int)
			{
				random_access_iterator	rtn(*this);
				operator++();
				return (rtn);
			}
			random_access_iterator&	operator--()
			{
				_elem--;
				return (*this);
			}
			random_access_iterator	operator--(int)
			{
				random_access_iterator	rtn(*this);
				operator--();
				return (rtn);
			}
			random_access_iterator	operator+(difference_type n) const { return (_elem + n); }
			random_access_iterator	operator-(difference_type n) const { return (_elem - n); }
			random_access_iterator&	operator+=(difference_type n)
			{
				_elem += n;
				return (*this);
			}

			random_access_iterator&	operator-=(difference_type n)
			{
				_elem -= n;
				return (*this);
			}

			reference	operator[](difference_type n) { return (*(operator+(n))); }

			operator	random_access_iterator<const T>() const
			{ return (random_access_iterator<const T>(this->_elem)); }

		private:
			pointer	_elem;
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

	//**********************일단 T가 2개인 것은 주석처리
	// template <typename T_L, typename T_R>
	// typename ft::random_access_iterator<T_L>::difference_type	operator==(
	// 	const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	// { return (lhs.base() == rhs.base()); }

	// template <typename T_L, typename T_R>
	// typename ft::random_access_iterator<T_L>::difference_type	operator!=(
	// 	const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	// { return (lhs.base() != rhs.base()); }

	// template <typename T_L, typename T_R>
	// typename ft::random_access_iterator<T_L>::difference_type	operator<(
	// 	const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	// { return (lhs.base() < rhs.base()); }

	// template <typename T_L, typename T_R>
	// typename ft::random_access_iterator<T_L>::difference_type	operator>(
	// 	const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	// { return (lhs.base() > rhs.base()); }

	// template <typename T_L, typename T_R>
	// typename ft::random_access_iterator<T_L>::difference_type	operator<=(
	// 	const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	// { return (lhs.base() <= rhs.base()); }

	// template <typename T_L, typename T_R>
	// typename ft::random_access_iterator<T_L>::difference_type	operator>=(
	// 	const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	// { return (lhs.base() >= rhs.base()); }

	// template <typename T_L, typename T_R>
	// typename ft::random_access_iterator<T_L>::difference_type	operator-(
	// 	const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	// { return (lhs.base() - rhs.base()); }
}

#endif