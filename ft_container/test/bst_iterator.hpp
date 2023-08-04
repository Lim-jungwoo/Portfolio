#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include "utils.hpp"

namespace ft
{
	template <typename T, class Compare>
	class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename T::value_type	value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer	pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference	reference;

			T*		_node;
			T*		_last_node;
			Compare	_comp;

			BST_iterator(const Compare& comp = Compare()) :
			//BST_iterator 기본생성자 아마 사용할 일 없을 것 같은데?
				_node(), _last_node(), _comp(comp) {}
			BST_iterator(T* node_p, T* last_node, const Compare& comp = Compare()) :
			//node_p와 last_node를 인자로 받아서 초기화
				_node(node_p), _last_node(last_node), _comp(comp) {}
			BST_iterator(const BST_iterator& bst_it) :
				_node(bst_it._node), _last_node(bst_it._last_node), _comp() {}
			virtual ~BST_iterator() {}

			BST_iterator	&operator=(const BST_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				_node = bst_it._node;
				_last_node = bst_it._last_node;
				_comp = bst_it._comp;
				return (*this);
			}

			bool	operator==(const BST_iterator& bst_it)
			{ return (_node == bst_it._node); }
			bool	operator!=(const BST_iterator& bst_it)
			{ return (_node != bst_it._node); }
			reference	operator*() const
			{ return (_node->value); }
			pointer	operator->() const
			{ return (&(_node->value)); }
			BST_iterator&	operator++()
			{
				T*	cursor = _node;

				if (_node->right == _last_node)
				{//_node의 오른쪽이 _last_node일 때
					cursor = _node->parent;
					while (cursor != _last_node && _comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
				//_node가 _last_node일 때
					_node = _last_node->right;
				else
				{//_node->right과 _node가 _last_node가 아닐 때
					cursor = _node->right;
					if (cursor == _last_node->parent && cursor->right == _last_node)
						_node = cursor;
					else
					{
						while (cursor->left != _last_node)
							cursor = cursor->left;
					}
					_node = cursor;
				}
				return (*this);
			}

			BST_iterator	operator++(int)
			{
				BST_iterator	tmp(*this);
				operator++();
				return (tmp);
			}

			BST_iterator&	operator--(void)
			{
				T*	cursor = _node;

				if (_node->left == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node && !_comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->left;
					if (cursor == _last_node->parent && cursor->left == _last_node)
						_node = cursor;
					else
					{
						while (cursor->right != _last_node)
							cursor = cursor->right;
					}
					_node = cursor;
				}
				return (*this);
			}
			BST_iterator	operator--(int)
			{
				BST_iterator	tmp(*this);
				operator--();
				return (tmp);
			}
	};

	template <typename T, class Compare>
	class BST_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename T::value_type	value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer	pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference	reference;

			T*		_node;
			T*		_last_node;
			Compare	_comp;

			BST_const_iterator(const Compare& comp = Compare()) :
				_node(), _last_node(), _comp(comp) {}
			BST_const_iterator(T* node_p, T* last_node, const Compare& comp = Compare()) :
				_node(node_p), _last_node(last_node), _comp(comp) {}
			BST_const_iterator(const BST_const_iterator& bst_it) :
				_node(bst_it._node), _last_node(bst_it._last_node), _comp() {}
			BST_const_iterator(const BST_iterator<T, Compare>& bst_it) :
				_node(bst_it._node), _last_node(bst_it._last_node), _comp() {}
			
			virtual ~BST_const_iterator() {}

			BST_const_iterator	&operator=(const BST_const_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				_node->bst_it._node;
				_last_node = bst_it._last_node;
				_comp = bst_it._comp;
				return (*this);
			}

			bool	operator==(const BST_const_iterator& bst_it)
			{ return (_node == bst_it._node); }
			bool	operator!=(const BST_const_iterator& bst_it)
			{ return (_node != bst_it._node); }
			reference	operator*() const
			{ return (&(_node->value)); }
			pointer	operator->() const
			{ return (&(_node->value)); }
			BST_const_iterator&	operator++()
			{
				T*	cursor = _node;

				if (_node->right == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node && _comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->right;
					if (cursor == _last_node->parent && cursor->right == _last_node)
						_node = cursor;
					else
					{
						while (cursor->left != _last_node)
							cursor = cursor->left;
					}
					_node = cursor;
				}
				return (*this);
			}

			BST_const_iterator	operator++(int)
			{
				BST_const_iterator	tmp(*this);
				operator++();
				return (tmp);
			}

			BST_const_iterator&	operator--()
			{
				T*	cursor = _node;

				if (_node->left == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node && !_comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->left;
					if (cursor == _last_node->parent && cursor->left == _last_node)
						_node = cursor;
					else
					{
						while (cursor->right != _last_node)
							cursor = cursor->right;
					}
					_node = cursor;
				}
				return (*this);
			}
			BST_const_iterator	operator--(int)
			{
				BST_const_iterator	tmp(*this);
				operator--();
				return (tmp);
			}
	};
}

#endif