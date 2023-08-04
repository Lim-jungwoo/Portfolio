#ifndef BST_HPP
# define BST_HPP

# include "bst_iterator.hpp"

namespace ft
{
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
			BST_Node(BST_Node* parent = NULL, BST_Node* left = NULL, BST_Node* right = NULL) :
				value(), parent(parent), left(left), right(right) {}
			BST_Node(const BST_Node& bst) : value(bst.value), parent(bst.parent),
				left(bst.left), right(bst.right) {}
			
			virtual ~BST_Node() {}

			BST_Node	&operator=(const BST_Node& bst)
			{
				if (bst == *this)
					return (*this);
				value = bst.value; parent = bst.parent;
				left = bst.left; right = bst.right;
				return (*this);
			}
			bool	operator==(const BST_Node& bst)
			{
				if (value == bst.value)
					return (true);
				return (false);
			}
	};

	template <class T, class Compare = ft::less<T>, class Node = ft::BST_Node<T>,
		class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
	class Binary_search_tree
	{
		public:
			typedef Binary_search_tree	self;
			typedef self&	self_reference;
			typedef T		value_type;
			typedef Node		node_type;
			typedef Node*		node_pointer;
			typedef Node_Alloc	node_alloc;
			typedef ft::BST_iterator<Node, Compare>	iterator;
			typedef ft::BST_const_iterator<Node, Compare>	const_iterator;
			typedef size_t	size_type;

			node_pointer	_last_node;
			node_alloc		_node_alloc;

			Binary_search_tree(const node_alloc& node_alloc_init = node_alloc()) :
				_node_alloc(node_alloc_init)
			{
				//맨 처음 만들어질 때 메모리를 1을 할당하고 _last_node를 만든다.
				//parent, left, right가 모두 _last_node이다.
				_last_node = _node_alloc.allocate(1);
				_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
			}

			~Binary_search_tree()
			{
				_node_alloc.destroy(_last_node);
				_node_alloc.deallocate(_last_node, 1);
			}

			ft::pair<iterator, bool>	insertPair(value_type to_insert)
			{
				Node*	new_node = _node_alloc.allocate(1);
				//일단 new_node에 allocate를 이용하여 메모리 할당
				Node*	prev_node = _last_node;
				//prev_node에 _last_node를 저장
				Node*	start_node = _last_node->parent;
				//start_node에 _last_node의 parent를 저장
				//만약 값이 아예 없었다면 _last_node->parent에는 _last_node가 저장되어있을 것

				bool	side = true;

				while (start_node != _last_node)
				{//start_node가 _last_node가 될 때까지 반복
				//만약 값이 없었다면 start_node는 _last_node였을 것이므로
				//이 반복문은 그냥 넘어간다.
					int	curkey = start_node->value.first;
					//start_node의 value의 first값을 curkey에 저장
					if (curkey == to_insert.first)
					//curkey가 to_insert.first와 같다면 원래 값이 존재했었다는 뜻이므로
					//제대로 작동안됐다는 뜻으로 false를 반환하는 것인가?
					//_start_node와 _last_node가
						return (ft::make_pair(iterator(start_node, _last_node), false));
					prev_node = start_node;
					if (to_insert.first > curkey)
					{
						side = true;
						start_node = start_node->right;
					}
					else
					{
						side = false;
						start_node = start_node->left;
					}
				}
				_node_alloc.construct(new_node, Node(to_insert, prev_node, _last_node, _last_node));

				if (prev_node == _last_node)
					_last_node->parent = new_node;
				else if (side == true)
					prev_node->right = new_node;
				else
					prev_node->left = new_node;
				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first += 1;
				return (ft::make_pair(iterator(new_node, _last_node), true));
			}

			void	removeByKey(value_type to_remove)
			{ _removeByKey(_last_node->parent, to_remove); }

			node_pointer	searchByKey(value_type to_remove)
			{
				node_pointer	node = _last_node->parent;

				while (node != _last_node)
				{
					if (node->value.first == to_remove.first)
						return (node);
					if (node->value.first > to_remove.first)
						node = node->left;
					else
						node = node->right;
				}
				return (node);
			}

			void	swap(self& x)
			{
				if (&x == this)
					return ;
				node_pointer	save = _last_node;
				_last_node = x._last_node;
				x._last_node = save;
			}

			size_type	max_size() const
			{ return (node_alloc().max_size()); }
			
		
		private:
			node_pointer	_BST_get_lower_node(node_pointer root)
			{//어떻게 사용되는 거여
				while (root != _last_node && root->left != _last_node)
					root = root->left;
				return (root);
			}
			node_pointer	_BST_get_higher_node(node_pointer root)
			{//어떻게 사용되는 거여
				while (root != _last_node && root->right != _last_node)
					root = root->right;
				return (root);
			}

			void	_replaceNodeInParent(node_pointer node, node_pointer new_node)
			{
				if (node->parent != _last_node)
				{
					if (_last_node->parent == node)
						_last_node->parent = new_node;
					if (node == node->parent->left)
						node->parent->left = new_node;
					else
						node->parent->right = new_node;
				}
				else
					_last_node->parent = new_node;
				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first -= 1;
				new_node->parent = node->parent;
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void	_replaceDoubleChildren(node_pointer& to_remove, node_pointer new_node)
			{
				if (new_node->parent != _last_node)
				{
					if (new_node->parent != to_remove)
						new_node->parent->left = new_node->right;
				}
				new_node->parent = to_remove->parent;
				if (to_remove->left != new_node)
					new_node->left = to_remove->left;
				if (to_remove->right != new_node)
					new_node->right = to_remove->right;
				
				if (to_remove->parent != _last_node)
				{
					if (to_remove->parent->left == to_remove)
						to_remove->parent->left = new_node;
					else if (to_remove->parent->right == to_remove)
						to_remove->parent->right = new_node;
				}
				else
					_last_node->parent = new_node;
				
				if (to_remove->left != _last_node && to_remove->left != new_node)
					to_remove->left->parent = new_node;
				if (to_remove->right != _last_node && to_remove->right != new_node)
					to_remove->right->parent = new_node;
				if (to_remove->parent != _last_node)
				{
					to_remove->left = _last_node;
					to_remove->right = _last_node;
					to_remove->parent = new_node;
				}

				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first -= 1;

				_node_alloc.destroy(to_remove);
				_node_alloc.deallocate(to_remove, 1);
			}

			void	_removeByKey(node_pointer node, value_type to_remove)
			{
				if (to_remove.first < node->value.first)
				{
					_removeByKey(node->left, to_remove);
					return ;
				}
				if (to_remove.first > node->value.first)
				{
					_removeByKey(node->right, to_remove);
					return ;
				}
				if (node->left != _last_node && node->right != _last_node)
				{
					node_pointer	successor = _BST_get_lower_node(node->right);
					_replaceDoubleChildren(node, successor);
					return ;
				}
				else if (node->left != _last_node)
					_replaceNodeInParent(node, node->left);
				else if (node->right != _last_node)
					_replaceNodeInParent(node, node->right);
				else
					_replaceNodeInParent(node, _last_node);
			}
	};
}

#endif