#ifndef MAP_HPP
# define MAP_HPP

# include "bst.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key	key_type;
			typedef T	mapped_type;
			typedef ft::pair<key_type, mapped_type>	value_type;
			typedef Compare	key_compare;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef typename ft::Binary_search_tree<value_type, key_compare>::iterator	iterator;
			typedef typename ft::Binary_search_tree<value_type, key_compare>::const_iterator	const_iterator;
			typedef typename ft::reverse_iterator<iterator>	reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t	size_type;

		private:
			allocator_type	_alloc;
			Compare			_comp;
			Binary_search_tree<value_type, Compare>	_bst;
		
		public:
			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;

				protected:
					Compare	comp;
					value_compare(Compare c) : comp(c) {}
				
				public:
					bool	operator()(const value_type& lhs, const value_type& rhs) const
					{ return (comp(lhs.first, rhs.first)); }
			};

			explicit map(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _bst() {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
				: _alloc(alloc), _comp(comp), _bst()
			{
				bool	is_valid;
				if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
					throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::type>());
				insert(first, last);
			}

			map(const map &x) : _alloc(x._alloc), _comp(x._comp), _bst()
			{ insert(x.begin(), x.end()); }

			~map() { clear(); }

			iterator	begin()
			{ return (iterator(_bst._last_node->left, _bst._last_node)); }
			const_iterator	begin() const
			{ return (const_iterator(_bst._last_node->left, _bst._last_node)); }
			void	clear()
			{ erase(begin(), end()); }
			size_type	count(const key_type& k) const
			{
				const_iterator	begin = begin();
				const_iterator	end = end();
				while (begin != end)
					if ((*(begin++)).first == k)
						return (1);
				return (0);
			}

			bool	empty() const
			{ return (_bst._last_node->parent == _bst._last_nmode); }
			iterator	end()
			{ return (iterator(_bst._last_node, _bst._last_node)); }
			const_iterator	end() const
			{ return (const_iterator(_bst._last_node, _bst._last_node)); }
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{ return (ft::make_pair(lower_bound(k), upper_bound(k))); }
			ft::pair<iterator, iterator>	equal_range(const key_type& k);
			{ return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			void	erase(iterator position)
			{ erase((*position).first); }
			size_type	erase(const key_type& k)
			{
				if (find(k) == end())
					return (0);
				_bst.removeByKey(ft::make_pair(k, mapped_type()));
				return (1);
			}
			void	erase(iterator first, iterator last)
			{
				while (first != last)
					erase((*(first++)).first);
			}

			iterator	find(const key_type& k)
			{ return (iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst.last_node)); }
			const_iterator	find(const key_type& k) const
			{ return (const_iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst.last_node)); }
			allocator_type	get_allocator() const { return (_alloc); }

			ft::pair<iterator, bool>	insert(const value_type& val)
			{ return (_bst.insertPair(val)); }
			iterator	insert(iterator position, const value_type& val)
			{
				(void)position;
				return (_bst.insertPair(val).first);
			}
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last,
				typename ft::enable_if<ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				bool	is_valid;
				if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
					throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::type>());
				difference_type	n = ft::distance(first, last);
				while (n--)
					insert(*(first++));
			}

			key_compare	key_comp() const
			{ return (key_compare()); }

			iterator	lower_bound(const key_type& k)
			{//k이상인 값을 반환
			//upper_bound는 k초과인 값을 반환이라 조금 다르다.
				iterator	begin = begin();
				iterator	end = end();

				while (begin != end)
				{
					if (_comp((*begin).first, k) == false)
						break ;
					begin++;
				}
				return (begin);
			}
			const_iterator	lower_bound(const key_type& k) const
			{ return (const_iterator(lower_bound(k))); }

			size_type	max_size() const
			{ return (_bst.max_size()); }
			map&	operator=(const map& x)
			{
				if (&x == this)
					return (*this);
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}
			mapped_type&	operator[](const key_type& k)
			{
				iterator	tmp = find(k);
				if (tmp == end())
					insert(ft::make_pair(k, mapped_type()));
				tmp = find(k);
				return ((*tmp).second);
			}
			reverse_iterator	rbegin()
			{ return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin() const
			{ return (const_reverse_iterator(end())); }
			reverse_iterator	rend()
			{ return (reverse_iterator(begin())); }
			const_reverse_iterator	rend() const
			{ return (const_reverse_iterator(begin())); }
			size_type	size() const
			{ return (_bst._last_node->value.first); }
			void	swap(map& x)
			{ _bst.swap(x._bst); }

			iterator	upper_bound(const key_type& k)
			{//k보다 큰 값을 반환
				iterator	begin = begin();
				iterator	end = end();
				while (begin != end)
				{
					if (_comp(k, (*begin).first))
						break ;
					begin++;
				}
				return (begin);
			}
			const_iterator	upper_bound(const key_type& k) const
			{ return (const_iterator(upper_bound(k))); }

			value_compare	value_comp() const
			{ return (value_compare(key_compare())); }
		
	};

	// template <class Key, class T, class Compare, class Alloc>
	// bool	operator==(const map<Key, T, Compare, Alloc>& lhs,
	// 	const map<Key, T, Compare, Alloc>& rhs);

	// template <class Key, class T, class Compare, class Alloc>
	// bool	operator!=(const map<Key, T, Compare, Alloc>& lhs,
	// 	const map<Key, T, Compare, Alloc>& rhs);

	// template <class Key, class T, class Compare, class Alloc>
	// bool	operator<(const map<Key, T, Compare, Alloc>& lhs,
	// 	const map<Key, T, Compare, Alloc>& rhs);

	// template <class Key, class T, class Compare, class Alloc>
	// bool	operator<=(const map<Key, T, Compare, Alloc>& lhs,
	// 	const map<Key, T, Compare, Alloc>& rhs);

	// template <class Key, class T, class Compare, class Alloc>
	// bool	operator>(const map<Key, T, Compare, Alloc>& lhs,
	// 	const map<Key, T, Compare, Alloc>& rhs);

	// template <class Key, class T, class Compare, class Alloc>
	// bool	operator>=(const map<Key, T, Compare, Alloc>& lhs,
	// 	const map<Key, T, Compare, Alloc>& rhs);

	// template <class Key, class T, class Compare, class Alloc>
	// void	swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y);
	
}


#endif