#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include "../utils/utils.hpp"
# include "reverse_iterator.hpp"

namespace	ft
{
	template <class T>
	class bst_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		template <class _T, class _const_node> friend class bst_const_iterator;
		public:
			typedef typename T::value_type	value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

		protected:
			T*		_node;
			T*		_last_node;
		
		public:
			bst_iterator() : _node(NULL), _last_node(NULL) {}
			bst_iterator(T* node, T* last_node) : _node(node), _last_node(last_node) {}
			bst_iterator(const bst_iterator& bst_it) : _node(bst_it._node), _last_node(bst_it._last_node) {}
			~bst_iterator() {}

			T*	base() const { return (this->_node); }
			bst_iterator&	operator=(const bst_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				this->_node = bst_it._node;
				this->_last_node = bst_it._last_node;
				return (*this);
			}

			reference	operator*() const
			{ return *(this->_node->value); }
			pointer	operator->() const
			{
				return ((this->_node->value));
			}
			bst_iterator&	operator++()
			{
				T*	prev = this->_node;
				if (prev->right == NULL || prev->right == this->_last_node)
				{
					if (prev->parent == NULL)
					{
						if (this->_node == this->_last_node)
							std::cout << this->_last_node->value->first;
						else
							this->_node = this->_last_node;
						return (*this);
					}
					else
					{
						
						if (prev->right == this->_last_node)
						{
							this->_node = this->_last_node;
							return (*this);
						}
						if (prev->parent->right == prev)
						{
							while (prev->parent && prev == prev->parent->right)
								prev = prev->parent;
							// if (prev->parent == NULL)
							// {
							// 	this->_node = this->_last_node;
							// 	std::cout << this->_last_node->value->first;
							// 	return (*this);
							// }
							if (prev == prev->parent->left)
								prev = prev->parent;
						}
						else
						{
							prev = prev->parent;
						}
					}
				}
				else
				{
					prev = prev->right;
					while (prev->left)
						prev = prev->left;
				}
				this->_node = prev;
				return (*this);
			}
			bst_iterator	operator++(int)
			{
				bst_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			bst_iterator&	operator--()
			{
				T*	prev = this->_node;
				if (prev->left == NULL)
				{
					
					if (prev->parent == NULL)
					{
						std::cout << this->_node->left->value->first;
						return (*this);
					}
					else
					{
						if (prev == prev->parent->right)
							prev = prev->parent;
						else
						{
							while (prev->parent && prev == prev->parent->left)
								prev = prev->parent;
							if (prev->parent == NULL)
							{
								std::cout << this->_node->left->value->first;
								return (*this);
							}
							if (prev == prev->parent->right)
								prev = prev->parent;
						}
					}
				}
				else
				{
					prev = prev->left;
					while (prev->right && prev->right != this->_last_node)
						prev = prev->right;
				}
				this->_node = prev;
				return (*this);
			}
			bst_iterator	operator--(int)
			{
				bst_iterator	tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template <class T, class const_node>
	class bst_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, const_node>
	{
		public:
			typedef typename const_node::value_type	value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
		
		private:
			const_node*		_cnode;
			const_node*		_last_cnode;

		public:
			bst_const_iterator() : _cnode(NULL), _last_cnode(NULL) {}
			bst_const_iterator(const_node* node, const_node* last_node) : _cnode(node), _last_cnode(last_node) {}
			bst_const_iterator(T* node, T* last_node) : 
				_cnode(reinterpret_cast<const_node*>(node)), _last_cnode(reinterpret_cast<const_node*>(last_node)) {}
			bst_const_iterator(const bst_const_iterator& bst_it) : _cnode(bst_it._cnode), _last_cnode(bst_it._last_cnode) {}
			bst_const_iterator(const bst_iterator<T>& bst_it) : _cnode(reinterpret_cast<const_node*>(bst_it._node)),
				_last_cnode(reinterpret_cast<const_node*>(bst_it._last_node)){}
			~bst_const_iterator() {}

			const_node*	base() const { return (this->_cnode); }
			bst_const_iterator&	operator=(const bst_const_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				this->_cnode = bst_it._cnode;
				this->_last_cnode = bst_it._last_cnode;
				return (*this);
			}

			bst_const_iterator&	operator=(const bst_iterator<T>& bst_it)
			{
				this->_cnode = reinterpret_cast<const_node*>(bst_it._node);
				this->_last_cnode = reinterpret_cast<const_node*>(bst_it._last_node);
				return (*this);
			}

			reference	operator*() const
			{ return *(this->_cnode->value); }
			pointer	operator->() const
			{
				return (this->_cnode->value);
			}
			bst_const_iterator&	operator++()
			{
				const_node*	prev = this->_cnode;
				
				if (prev->right == NULL || prev->right == this->_last_cnode)
				{
					if (prev->parent == NULL)
					{
						if (this->_cnode == this->_last_cnode)
							std::cout << this->_last_cnode->value->first;
						else
							this->_cnode = this->_last_cnode;
						return (*this);
					}
					else
					{
						if (prev->right == this->_last_cnode)
						{
							this->_cnode = this->_last_cnode;
							return (*this);
						}
						if (prev->parent->right == prev)
						{
							while (prev->parent && prev == prev->parent->right)
								prev = prev->parent;
							// if (prev->parent == NULL)
							// {
							// 	this->_cnode = this->_last_cnode;
							// 	return (*this);
							// 	std::cout << this->_last_cnode->value->first;
							// 	return (*this);
							// }
							if (prev == prev->parent->left)
								prev = prev->parent;
						}
						else
							prev = prev->parent;
					}
				}
				else
				{
					prev = prev->right;
					while (prev->left)
						prev = prev->left;
				}
				
				this->_cnode = prev;
				return (*this);
			}
			bst_const_iterator	operator++(int)
			{
				bst_const_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			bst_const_iterator&	operator--()
			{
				const_node*	prev = this->_cnode;
				if (prev->left == NULL)
				{
					if (prev->parent == NULL)
					{
						std::cout << this->_cnode->left->value->first;
						return (*this);
					}
					else
					{
						if (prev == prev->parent->right)
							prev = prev->parent;
						else
						{
							while (prev->parent && prev == prev->parent->left)
								prev = prev->parent;
							if (prev->parent == NULL)
							{
								std::cout << this->_cnode->left->value->first;
								return (*this);
							}
							if (prev == prev->parent->right)
								prev = prev->parent;
						}
					}
				}
				else
				{
					prev = prev->left;
					while (prev->right && prev->right != this->_last_cnode)
						prev = prev->right;
				}
				this->_cnode = prev;
				return (*this);
			}
			bst_const_iterator	operator--(int)
			{
				bst_const_iterator	tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template<class Node>
	bool	operator==(const ft::bst_iterator<Node>& lhs, const ft::bst_iterator<Node>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template<class Node, class const_node>
	bool	operator==(const ft::bst_iterator<Node>& lhs, const ft::bst_const_iterator<Node, const_node>& rhs)
	{ return (lhs.base() == reinterpret_cast<Node*>(rhs.base())); }

	template<class Node, class const_node>
	bool	operator==(const ft::bst_const_iterator<Node, const_node>& lhs, const ft::bst_iterator<Node>& rhs)
	{ return (reinterpret_cast<Node*>(lhs.base()) == rhs.base()); }

	template<class Node, class const_node>
	bool	operator==(const ft::bst_const_iterator<Node, const_node>& lhs, const ft::bst_const_iterator<Node, const_node>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template<class Node>
	bool	operator!=(const ft::bst_iterator<Node>& lhs, const ft::bst_iterator<Node>& rhs)
	{ return (lhs.base() != rhs.base()); }

	template<class Node, class const_node>
	bool	operator!=(const ft::bst_iterator<Node>& lhs, const ft::bst_const_iterator<Node, const_node>& rhs)
	{ return (lhs.base() != reinterpret_cast<Node*>(rhs.base())); }

	template<class Node, class const_node>
	bool	operator!=(const ft::bst_const_iterator<Node, const_node>& lhs, const ft::bst_iterator<Node>& rhs)
	{ return (reinterpret_cast<Node*>(lhs.base()) != rhs.base()); }

	template<class Node, class const_node>
	bool	operator!=(const ft::bst_const_iterator<Node, const_node>& lhs, const ft::bst_const_iterator<Node, const_node>& rhs)
	{ return (lhs.base() != rhs.base()); }
}

#endif