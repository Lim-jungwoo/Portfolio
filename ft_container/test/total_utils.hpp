#ifndef TOTAL_UTILS_HPP
# define TOTAL_UTILS_HPP

#include <sstream>

namespace ft
{
	template <typename T>
	std::string	to_string(T n)
	{//T자료형 n을 받아서 string형으로 변환하여 리턴
		std::ostringstream	ss;
		ss << n;
		return (ss.str());
	}

	template <class Arg1, class Arg2, class Result>
	struct	binary_function
	{//다른 기능들을 사용하기 위한 기본 베이스
	//arg1, arg2, result 3개의 인자를 사용한다.
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template <class T>
	struct less : binary_function<T, T, bool>
	{//operator()를 오버로딩하여 T자료형 x,y를 받아와서 x가 y보다 작으면 1을 리턴, x가 y보다 크면 0을 리턴
		bool	operator()(const T& x, const T& y) const { return (x < y); }
	};

	template <class T1, class T2>
	struct pair
	{//자료형이 다른 것들을 쌍으로 연결
		public:
			typedef T1	first_type;
			typedef T2	second_type;
			first_type	first; //첫번째 자료형의 인자
			second_type	second; //두번째 자료형의 인자

			//pair기본 생성자, 첫번째와 두번째 자료형의 객체를 생성만 함
			pair() : first(), second() {}

			//pair인자 생성자
			pair(const first_type& f, const second_type& s) : first(f), second(s) {}

			template <class f_t, class s_t>
			//pair 복사생성자
			//따로 template으로 자료형을 정해주어 다른 자료형의 pair가 오더라도 자료형을 변경하여 복사 생성 가능
			//당연히 std::string에서 int로 변환 같이 아예 불가능한거는 작동 안됨
			pair(const pair<f_t, s_t>& p) : first(p.first), second(p.second) {}
			pair(const pair<first_type, second_type>& p) : first(p.first), second(p.second) {}

			//pair 대입연산자
			pair&	operator=(const pair& p)
			{
				if (*this == p)
					return (*this);
				this->first = p.first;
				this->second = p.second;
				return (*this);
			}
	};
	
	template <class T1, class T2>
	//pair가 서로 같은지 확인하는 ==오버로딩
	bool	operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	//pair가 서로 다른지 확인하는 !=오버로딩
	bool	operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool	operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{//왼쪽 pair의 첫번째 값이 오른쪽 pair의 첫번째 값보다 작으면 1
	//왼쪽 pair의 첫번째 값이 오른쪽 pair의 첫번째 값이하이고,
	//왼쪽 pair의 두번째 값이 오른쪽 pair의 두번째 값보다 작으면 1
		return (lhs.first < rhs.first ||
			(!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	
	template <class T1, class T2>
	bool	operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(rhs < lhs); }

	template <class T1, class T2>
	bool	operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return (rhs < lhs); }

	template <class T1, class T2>
	bool	operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs < rhs); }

	template <class T1, class T2>
	ft::pair<T1,T2>	make_pair(T1 x, T2 y)
	{ return (ft::pair<T1,T2>(x,y)); }

	template <bool Cond, class T = void> struct enable_if {};
	//Cond가 true가 아닐 때 실행된다. type이 정해져있지 않으므로 치환 오류가 발생한다.
	template <class T> struct enable_if<true, T> { typedef T type; };
	//첫번째 인자가 true일 때 실행된다.

	template <bool is_integral>
	struct is_integral_base
	{
		static const bool	value = is_integral;
	};

	template <typename T>
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
	
	class input_iterator_tag {};
	class output_iterator_tag {};
	class forward_iterator_tag {};
	class bidirectional_iterator_tag {};
	class random_access_iterator_tag {};

	template <bool is_valid, typename T>
	struct valid_iterator_tag_base
	{
		typedef T	type;
		const static bool	value = is_valid;
	};

	template <typename T>
	//input_iterator_tagged  이건 어따 쓰는 거임?
	struct is_input_iterator_tagged : public valid_iterator_tag_base<false, T> {};

	template <>
	struct is_input_iterator_tagged<ft::input_iterator_tag> :
		public valid_iterator_tag_base<true, ft::input_iterator_tag> {};
	
	template <>
	struct is_input_iterator_tagged<ft::forward_iterator_tag> :
		public valid_iterator_tag_base<true, ft::forward_iterator_tag> {};
	
	template <>
	struct is_input_iterator_tagged<ft::bidirectional_iterator_tag> :
		public valid_iterator_tag_base<true, ft::bidirectional_iterator_tag> {};
	
	template <>
	struct is_input_iterator_tagged<ft::random_access_iterator_tag> :
		public valid_iterator_tag_base<true, ft::random_access_iterator_tag> {};
	/////////////////////////////////////////////

	template <typename T>
	struct is_ft_iterator_tagged : public valid_iterator_tag_base<false, T> {};

	template <>
	struct is_ft_iterator_tagged<ft::input_iterator_tag> :
		public valid_iterator_tag_base<true, ft::input_iterator_tag> {};

	template <>
	struct is_ft_iterator_tagged<ft::output_iterator_tag> :
		public valid_iterator_tag_base<true, ft::output_iterator_tag> {};

	template <>
	struct is_ft_iterator_tagged<ft::forward_iterator_tag> :
		public valid_iterator_tag_base<true, ft::forward_iterator_tag> {};

	template <>
	struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag> :
		public valid_iterator_tag_base<true, ft::bidirectional_iterator_tag> {};

	template <>
	struct is_ft_iterator_tagged<ft::random_access_iterator_tag> :
		public valid_iterator_tag_base<true, ft::random_access_iterator_tag> {};
	
	template <typename T>
	//iterator tag가 잘못되었을 때 던지는 exception
	//제대로 사용하는지 확인해봐야 한다.
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

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	//이거 있어도 되는지 확인해야됨
	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	distance(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	rtn = 0;
		while (first != last)
		{
			first++;
			rtn++;
		}
		return (rtn);
	}

	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};

	template <class T>
	//양방향 iterator 클래스를 iterator를 상속받아서 만든다.
	//양방향만 만드는 이유가 뭘까 아마 map에서 사용하는 것 같다.
	//안쓰는 거 같은데
	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;

		private:
			pointer	_elem;
	};

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator	iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			reverse_iterator() : _elem() {}
			explicit reverse_iterator(iterator_type it) : _elem(it) {}

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : _elem(rev_it.base()) {}

			virtual ~reverse_iterator() {}

			iterator_type	base() const { return (_elem); }
			reference	operator*() const
			{
				iterator_type	tmp = _elem;
				return (*(--tmp));
			}

			reverse_iterator	operator+(difference_type n) const
			{ return (reverse_iterator(_elem - n)); }

			reverse_iterator&	operator++()
			{
				--_elem;
				return (*this);
			}

			reverse_iterator	operator++(int)
			{
				reverse_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			reverse_iterator&	operator+=(difference_type n)
			{
				_elem -= n;
				return (*this);
			}

			reverse_iterator	operator-(difference_type n) const
			{ return (reverse_iterator(_elem + n)); }

			reverse_iterator&	operator--()
			{
				++_elem;
				return (*this);
			}

			reverse_iterator	operator--(int)
			{
				reverse_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			reverse_iterator&	operator-=(difference_type n)
			{
				_elem += n;
				return (*this);
			}

			pointer	operator->() const { return &(operator*()); }

			reference	operator[](difference_type n) const { return (this->base()[-n - 1]); }

		private:
			iterator_type	_elem;
	};
	
	template <class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }
	
	template <class Iterator_L, class Iterator_R>
	bool	operator==(const reverse_iterator<Iterator_L>& lhs,
		const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() == rhs.base()); }
	
	template <class Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }
	
	template <class Iterator_L, class Iterator_R>
	bool	operator!=(const reverse_iterator<Iterator_L>& lhs,
		const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() != rhs.base()); }
	
	template <class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }
	
	template <class Iterator_L, class Iterator_R>
	bool	operator<(const reverse_iterator<Iterator_L>& lhs,
		const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() > rhs.base()); }

	template <class Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator_L, class Iterator_R>
	bool	operator<=(const reverse_iterator<Iterator_L>& lhs,
		const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() >= rhs.base()); }
	
	template <class Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); }
	
	template <class Iterator_L, class Iterator_R>
	bool	operator>(const reverse_iterator<Iterator_L>& lhs,
		const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() < rhs.base()); }
	
	template <class Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }
	
	template <class Iterator_L, class Iterator_R>
	bool	operator>=(const reverse_iterator<Iterator_L>& lhs,
		const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() <= rhs.base()); }
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); }

	template <class Iterator_L, class Iterator_R>
	bool	operator-(const reverse_iterator<Iterator_L>& lhs,
		const reverse_iterator<Iterator_R>& rhs)
	{ return (lhs.base() - rhs.base()); }

	template <class InputIterator1, class InputIterator2>
	//first2가 first1보다 크면 true리턴
	//first1과 first2가 아예 같다면 true리턴
	//다른 경우 모두 false 리턴
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	//Compare함수로 비교
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
	
	template <typename T>
	struct BST_Node
	{
		public:
			typedef T	value_type;
			
			value_type	value;
			BST_Node*	parent;
			BST_Node*	left;
			BST_Node*	right;

			BST_Node() : value(), parent(NULL), left(NULL), right(NULL) {}

			BST_Node(BST_Node* parent = NULL, BST_Node* left = NULL,
				BST_Node* right = NULL) : value(), parent(parent), left(left), right(right) {}
			
			BST_Node(const BST_Node& bst) : value(bst.value), parent(bst.parent), left(bst.left), right(bst.right) {}

			virtual ~BST_Node() {}

			BST_Node	&operator=(const BST_Node& bst)
			{
				if (bst == *this)
					return (*this);
				this->value = bst.value;
				this->parent = bst.parent;
				this->left = bst.left;
				this->right = bst.right;
				return (*this);
			}

			bool	operator==(const BST_Node& bst)
			{
				if (this->value == bst.value)
					return (true);
				return (false);
			}
	};

	template <class Data_T>
	struct Doubly_Linked_node
	{
		public:
			Doubly_Linked_node	*prev;
			Doubly_Linked_node	*next;
			Data_T				data;

			Doubly_Linked_node() : prev(NULL), next(NULL) {}

			Doubly_Linked_node(const Data_T& val) : prev(NULL), next(NULL), data(val) {}

			Doubly_Linked_node(const Data_T& val,
				Doubly_Linked_node *prev, Doubly_Linked_node *next) : prev(prev), next(next), data(val) {}
	};
}


#endif