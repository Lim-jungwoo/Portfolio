#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "random_access_iterator.hpp"

namespace	ft
{
	template <typename T, class Allocator=std::allocator<T> >
	class vector
	{
		//member type
		public:
			typedef T			value_type;
			typedef Allocator	allocator_type;
			typedef typename allocator_type::size_type	size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef ft::random_access_iterator<value_type>	iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
			
		private:
			allocator_type	_alloc; //allocator_type을 저장
			pointer			_start; //할당된 메모리의 첫 주소를 저장
			pointer			_size; //할당된 메모리에서 진짜 값이 있는 맨 마지막 메모리 주소를 저장
			pointer			_capacity; //할당된 메모리의 맨 마지막 주소를 저장

		public:
			//기본 벡터 생성자
			explicit	vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _start(NULL), _size(NULL), _capacity(NULL) {}
			//벡터의 크기가 인자로 들어왔을 때 생성자
			explicit	vector(size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _start(NULL), _size(NULL), _capacity(NULL)
			{
				_start = _alloc.allocate(n);
				_capacity = _start + n;
				_size = _start;
				while (n--)
				{
					_alloc.construct(_size, val);
					_size++;
				}
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type());
			
			vector(const vector& x);

			~vector();

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				bool	is_valid;
				if (!(is_valid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
					throw (ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::type>());
				size_type	copy_size = last - first;
				if (copy_size > max_size())
					throw (std::length_error("vector"));

				if (copy_size > capacity())
				{//복사할 범위가 capacity보다 클 때
					pointer	new_start;
					pointer	new_size;
					pointer	new_capacity;

					new_start = _alloc.allocate(copy_size);
					new_size = new_start;
					new_capacity = new_start + copy_size;
					for (size_type i = 0; i < copy_size; i++)
						_alloc.construct(new_size++, *(first + i));
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					_alloc.deallocate(_start, size());
					_start = new_start;
					_size = new_size;
					_capacity = new_capacity;
				}
				else
				{
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					_size = _start;
					for (size_type i = 0; i < copy_size; i++)
					{
						_alloc.construct(_size++, *(first + i));
					}

				}
			}

			void	assign(size_type n, const value_type& val)
			{//n만큼 val을 할당
				if (n > capacity())
				{//새로 할당할 메모리가 원래 capacity보다 클 때
					pointer	new_start;
					pointer	new_size;
					pointer	new_capacity;

					new_start = _alloc.allocate(n);
					new_size = new_start;
					new_capacity = new_start + n;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(new_size++, val);
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					_alloc.deallocate(_start, capacity());
					_start = new_start;
					_size = new_size;
					_capacity = new_capacity;
				}
				else
				{
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					_size = _start;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_size++, val);
				}
			}

			reference	at(size_type n)
			{
				if ((size_type)(_size - _start) <= n )
					throw (std::out_of_range("vector"));
				return (*this)[n];
			}

			const_reference	at(size_type n) const
			{
				if ((_size - _start) <= n )
					throw (std::out_of_range("vector"));
				return (*this)[n];
			}
			
			reference	back() { return (*(_size-1)); }
			const_reference	back() const { return (*(_size-1)); }
			iterator	begin() { return (_start); }
			const_iterator	begin() const { return (_start); }
			size_type	capacity() const { return (_capacity - _start); }
			void	clear()
			{
				for (size_t i = 0; i < size(); i++)
					_alloc.destroy(_start + i);
				_size = _start;
			}
			
			bool	empty() const { return (size() == 0 ? true : false); }
			iterator	end() { return (_size); }
			const_iterator	end() const { return (_size); }

			iterator	erase(iterator position)
			{
				pointer	pos = &(*position);
				if (&(*position) + 1 == _size)
					_alloc.destroy(&(*position));
				else
				{
					_alloc.destroy(&(*position));
					for (long i = 0; i < _size - &(*position) - 1; i++)
					{
						_alloc.construct(&(*position) + i, *(&(*position) + i + 1));
						_alloc.destroy(&(*position) + i + 1);
					}
				}
				_size -= 1;
				return (iterator(pos));
			}
			iterator	erase(iterator first, iterator last)
			{
				pointer	pos = &(*first);
				for (long i = 0; &(*first) + i != &(*last); i++)
					_alloc.destroy(&(*first) + i);
				for (long i = 0; i < _size - &(*last); i++)
				{
					_alloc.construct(pos + i, *(&(*last) + i));
					_alloc.destroy(&(*last) + i);
				}
				_size -= (&(*last) - pos);
				return (iterator(pos));
			}

			reference	front() { return (*_start); }
			const_reference	front() const { return (*_start); }
			allocator_type	get_allocator() const { return (_alloc); }

			iterator	insert(iterator position, const value_type& val)
			{
				size_type	pos = &(*position) - _start;
				size_type	behind = _size - &(*position);
				if (capacity() >= size() + 1)
				{
					for (size_type i = 0; i < behind; i++)
					{
						value_type	tmp = *(_size - i - 1);
						_alloc.construct(_size - i, tmp);
						_alloc.destroy(&(*_size) - i - 1);
					}
					_size++;
					_alloc.construct(&(*position), val);
				}
				else
				{
					pointer	new_start = pointer();
					pointer	new_size = pointer();
					pointer	new_capacity = pointer();
					size_type	capacity_size = (capacity() * 2 > 0) ? capacity() * 2 : 1;

					new_start = _alloc.allocate(capacity_size);
					new_size = new_start + size();
					new_capacity = new_start + capacity_size;
					size_type	i;
					for (i = 0; i < pos; i++)
						_alloc.construct(new_start + i, *(_start + i));
					_alloc.construct(new_start + i, val);
					for (i = 0; i < behind; i++)
						_alloc.construct(new_size - i, *(_size - i - 1));
					for (i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					if (_start)
						_alloc.deallocate(_start, capacity());
					_start = new_start;
					_size = new_size + 1;
					_capacity = new_capacity;
				}
				return (iterator(_start + pos));
			}

			void	insert(iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return ;
				if (n + size() > max_size())
					throw (std::length_error("vector"));
				size_type	pos = &(*position) - _start;
				size_type	spare = _capacity - _start;
				size_type	behind = _size - &(*position);
				if (spare >= n)
				{
					for (size_type i = 0; i < size() - pos; i++)
						_alloc.construct(_size - i + (n - 1), *(_size - i - 1));
					_size += n;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&(*position) + i, val);
				}
				else
				{
					pointer	new_start = pointer();
					pointer	new_size = pointer();
					pointer	new_capacity = pointer();

					size_type	capacity_size = (capacity() > 0) ? capacity() * 2 : 1;
					if (capacity_size < size() + n)
						capacity_size = size() + n;
					new_start = _alloc.allocate(capacity_size);
					new_size = new_start + size() + n;
					new_capacity = new_start + capacity_size;

					size_type	i;
					for (i = 0; i < pos; i++)
						_alloc.construct(new_start + i, *(_start + i));
					for (size_type j = 0; j < n; j++)
						_alloc.construct(new_start + i + j, val);
					for (i = 0; i < behind; i++)
						_alloc.construct(new_size - i - 1, *(_size - i - 1));
					
					for (i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					_alloc.deallocate(_start, capacity());

					_start = new_start;
					_size = new_size;
					_capacity = new_capacity;
				}
			}
			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				bool is_valid;
				if (!(is_valid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
					throw (ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());

				size_type	dist = ft::distance(first, last);
				size_type	pos = &(*position) - _start;
				size_type	spare = _capacity - _size;
				size_type	behind = _size - &(*position);
				if (spare >= dist)
				{
					for (size_type i = 0; i < size() - pos; i++)
						_alloc.construct(_size - i + (dist - 1), *(_size - i - 1));
					_size += dist;
					for (size_type i = 0; &(*first) + i != &(*last); i++)
						_alloc.construct(&(*position) + i, *(first + i));
				}
				else
				{
					pointer	new_start = pointer();
					pointer	new_size = pointer();
					pointer	new_capacity = pointer();

					size_type	capacity_size = (capacity() > 0) ? capacity() * 2 : 1;
					if (capacity_size < size() + dist)
						capacity_size = size() + dist;
					new_start = _alloc.allocate(capacity_size);
					new_size = new_start + size() + dist;
					new_capacity = new_start + capacity_size;

					for (size_type i = 0; i < pos; i++)
						_alloc.construct(new_start + i, *(_start + i));
					for (size_type i = 0; i < dist; i++)
						_alloc.construct(new_start + pos + i, *(first + i));
					for (size_type i = 0; i < behind; i++)
						_alloc.construct(new_size - i - 1, *(_size - i - 1));
					
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					_alloc.deallocate(_start, capacity());
					_start = new_start;
					_size = new_size;
					_capacity = new_capacity;
				}
			}

			size_type	max_size() const { return allocator_type().max_size(); }
			vector&	operator=(const vector& x)
			{
				if (x == *this)
					return (*this);
				clear();
				insert(begin(), x.begin(), x.end());
				return (*this);
			}
			reference	operator[] (size_type n) { return *(_start + n); }
			const_reference	operator[] (size_type n) const { return *(_start + n); }

			void	pop_back()
			{
				if (_size)
				{//vector안에 인자가 있을 때
					_alloc.destroy(_size - 1);
					_size--;
				}
			}

			void	push_back(const value_type &val)
			{
				if (_size == _capacity)
				{
					if (_size)
					{//vector안에 인자가 있을 때
						pointer	new_start;
						pointer	new_size;
						pointer	new_capacity;

						new_start = _alloc.allocate(capacity() * 2);
						new_capacity = new_start + capacity() * 2;
						new_size = new_start;
						for (size_type i = 0; i < size(); i++)
							_alloc.construct(new_size++, *(_start + i));
						_alloc.construct(new_size++, val);
						for (size_type i = 0; i < size(); i++)
							_alloc.destroy(_start + i);
						_alloc.deallocate(_start, capacity());
						_start = new_start;
						_size = new_size;
						_capacity = new_capacity;
					}
					else
					{//vector안에 인자가 없을 때
						_start = _alloc.allocate(1);
						_capacity = _start + 1;
						_size = _start;
						_alloc.construct(_size, val);
						_size++;
					}
				}
				else
				{
					_alloc.construct(_size, val);
					_size++;
				}
			}

			reverse_iterator	rbegin() { return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin() const { return (reverse_iterator(end())); }
			reverse_iterator	rend() { return (reverse_iterator(begin())); }
			const_reverse_iterator	rend() const { return (reverse_iterator(begin())); }

			void	reserve(size_type n)
			{
				if (n > max_size())
				//n이 max_size보다 크면 length_error를 던져야 한다.
					throw (std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"));
				if (n <= capacity())
				//n이 capacity이하이면 아무 작동 안함
					return ;
				else
				{//n이 capacity보다 크면 작동
					if (size() == 0)
					{//인자가 없을 때
						_start = _alloc.allocate(n);
						_size = _start;
						_capacity = _start + n;
					}
					else
					{//인자가 있을 때
						pointer	new_start;
						pointer	new_size;
						pointer	new_capacity;

						new_start = _alloc.allocate(n);
						new_size = new_start;
						new_capacity = new_start + n;
						for (size_type i = 0; i < size(); i++)
							_alloc.construct(new_size++, *(_start + i));
						for (size_type i = 0; i < size(); i++)
							_alloc.destroy(_start + i);
						_alloc.deallocate(_start, capacity());
						_start = new_start;
						_size = new_size;
						_capacity = new_capacity;
					}
				}
			}

			void	resize(size_type n, value_type val = value_type())
			{
				if (n > max_size())
					throw (std::length_error("vector"));
				if (n < size())
				{
					while (size() > n)
					{
						--_size;
						_alloc.destroy(_size);
					}
				}
				else
					insert(end(), n - size(), val);
			}
			
			size_type	size() const { return (_size - _start); }
			void	swap(vector& x)
			{
				if (x == *this)
					return ;
				allocator_type	tmp_alloc = x._alloc;
				pointer	tmp_start = x._start;
				pointer	tmp_size = x._size;
				pointer	tmp_capacity = x._capacity;
				
				x._alloc = _alloc;
				x._start = _start;
				x._size = _size;
				x._capacity = _capacity;
				_alloc = tmp_alloc;
				_start = tmp_start;
				_size = tmp_size;
				_capacity = tmp_capacity;
			}
	};

	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator	lhs_begin = lhs.begin();
		typename ft::vector<T>::const_iterator	rhs_begin = rhs.begin();
		while (lhs_begin != lhs.end())
		{
			if (rhs_begin == rhs.end() || *lhs_begin != *rhs_begin)
				return (false);
			lhs_begin++;
			rhs_begin++;
		}
		return (true);

		// return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{ return (!(lhs == rhs)); }

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{ return (!(rhs < lhs)); }

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{ return (rhs < lhs); }

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{ return (!(lhs < rhs)); }

	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{ x.swap(y); }
}


#endif