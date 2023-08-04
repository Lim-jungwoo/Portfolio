#ifndef BST_HPP
# define BST_HPP

# include "iterator/bst_iterator.hpp"

namespace ft
{
	template <class T>
	struct bst_node
	{
		public:
			typedef T											value_type;

			value_type*	value;
			bst_node*	parent;
			bst_node*	left;
			bst_node*	right;

			bst_node(bst_node* parent = NULL, bst_node* left = NULL, bst_node* right = NULL) :
				value(NULL), parent(parent), left(left), right(right) {}
			bst_node(const bst_node& bst) :
				value(bst.value), parent(bst.parent), left(bst.left), right(bst.right) {}
			
			~bst_node() {}

			bst_node&	operator=(const bst_node& bst)
			{
				if (bst == *this)
					return (*this);
				this->value = bst.value; this->parent = bst.parent;
				this->left = bst.left; this->right = bst.right;
				return (*this);
			}
			bool	operator==(const bst_node& bst)
			{
				if (this->value == bst.value)
					return (true);
				return (false);
			}
	};

	template <class T, class Key, class Map, class Compare = ft::less<Key>, class Alloc = std::allocator<T>,
		class Node = ft::bst_node<T> >
	class bst
	{
		public:
			typedef T										value_type;
			typedef Key										key_type;
			typedef Node*									node_type;
			typedef ft::bst_node<ft::pair<const Key, const Map> >	const_node;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef ft::bst<value_type, key_type, key_compare, allocator_type, Node>	bst_type;
			typedef ft::bst_iterator<Node>						iterator;
			typedef ft::bst_const_iterator<Node, const_node>	const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef size_t									size_type;
			typedef typename Alloc::template rebind<ft::bst_node<value_type> >::other	node_allocator;

			node_type			root_node;
			node_type			first_node;
			node_type			last_node;
			node_type			tmp_node;
			size_type			count_node;
			allocator_type		value_alloc;
			node_allocator		node_alloc;
			key_compare			comp;

			bst(const allocator_type& va = allocator_type(), const node_allocator& na = node_allocator(),
				const key_compare& comp = key_compare()) :
				value_alloc(va), node_alloc(na), comp(comp)
			{
				last_node = node_alloc.allocate(1);
				node_alloc.construct(last_node, Node());
				root_node = NULL;
				first_node = last_node;
				count_node = 0;
			}

			bst(value_type& val, const allocator_type& va = allocator_type(),
				const node_allocator& na = node_allocator(), const key_compare& comp = key_compare()) :
				value_alloc(va), node_alloc(na), comp(comp)
			{
				first_node = node_alloc.allocate(1);
				node_alloc.construct(first_node, Node());
				last_node = node_alloc.allocate(1);
				node_alloc.construct(last_node, Node(NULL, first_node, NULL));
				first_node->value = value_alloc.allocate(1);
				value_alloc.construct(first_node->value, val);
				root_node = first_node;
				count_node = 1;
			}

			~bst()
			{
				std::cout << "bst destruct\n";
			}

			iterator	begin()
			{
				node_type	ret = find_min();
				if (ret == NULL)
					return (this->end());
				return (iterator(ret, last_node));
			}
			const_iterator	begin() const
			{
				node_type	ret = find_min();
				if (ret == NULL)
					return (this->end());
				return (const_iterator(ret, this->last_node));
			}

			void	clear()
			{
				this->erase(this->begin(), this->end());
			}

			bool		empty() const
			{ return (this->count_node == 0); }

			iterator	end()
			{
				node_type	prev = this->last_node;
				return (iterator(prev, this->last_node));
			}
			const_iterator	end() const
			{
				node_type	prev = this->last_node;
				return (const_iterator(prev, this->last_node));
			}

			pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}
			pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			void	full_node_change(node_type change)
			{//왼쪽 자식, 오른쪽 자식이 둘 다 있을 때 위치를 바꿔주는 함수
			//삭제할 때 용이하게 위치를 바꿔주기 위해서 사용
				node_type	prev = change->left;
				while (prev->right && prev->right != this->last_node)
					prev = prev->right;
				if (prev->parent->left == prev)
				{//왼쪽으로만 하나 이동했을 때
					if (prev->left)
					{//바꿀 값이 왼쪽 자식 노드가 있음
						prev->parent->left = prev->left;
						prev->left->parent = prev->parent;
					}
					else
						prev->parent->left = NULL;
				}
				else
				{//왼쪽으로 하나 이동한 후 가장 오른쪽으로 이동했을 때
					if (prev->left)
					{
						prev->parent->right = prev->left;
						prev->left->parent = prev->parent;
					}
					else
						prev->parent->right = NULL;
				}
				change->left->parent = prev;
				change->right->parent = prev;
				prev->left = change->left;
				prev->right = change->right;
				if (change == root_node)
				{//바꿀 노드가 root인 경우
					prev->parent = NULL;
					this->root_node = prev;
				}
				else
				{//바꿀 노드가 root가 아닌 경우
					prev->parent = change->parent;
				}
			}

			void	free_node(node_type nod)
			{
				node_type	free_pos = nod;
				node_type	new_last_node_left = nod;
				if (new_last_node_left == find_max())
				{//가장 큰 값을 지워야 한다면 last_node에 새롭게 left를 넣어야한다.
					if (new_last_node_left->left)
					{
						new_last_node_left = new_last_node_left->left;
						while (new_last_node_left->right && new_last_node_left != this->last_node)
							new_last_node_left = new_last_node_left->right;
					}
					else if (new_last_node_left->parent)
					{
						new_last_node_left = new_last_node_left->parent;
					}
					if (root_node == find_max() && new_last_node_left == root_node)
						new_last_node_left = NULL;
					else
					{
						new_last_node_left->right = this->last_node;

					}
					this->last_node->left = new_last_node_left;
				}
				if (free_pos->left == NULL && (free_pos->right == NULL || free_pos->right == this->last_node))
				{//왼쪽과 오른쪽이 없으면 그냥 부모와 연결만 끊으면 된다.
					if (free_pos->parent)
					{
						if (free_pos->parent->left == free_pos)
							free_pos->parent->left = NULL;
						else if (free_pos->right == this->last_node)
							free_pos->parent->right = this->last_node;
						else
							free_pos->parent->right = NULL;
					}
					else
					{
						root_node = NULL;
					}
				}
				else if (free_pos->left == NULL && (free_pos->right != NULL && free_pos->right != this->last_node))
				{//왼쪽이 없고 오른쪽이 있으면 부모와 자식을 연결시켜주면 된다.
					if (free_pos->parent)
					{
						if (free_pos->parent->left == free_pos)
						{
							free_pos->parent->left = free_pos->right;
							free_pos->right->parent = free_pos->parent;
						}
						else
						{
							free_pos->parent->right = free_pos->right;
							free_pos->right->parent = free_pos->parent;
						}
					}
					else
					{
						root_node = free_pos->right;
						free_pos->right->parent = NULL;
					}
				}
				else if (free_pos->left != NULL && (free_pos->right == NULL || free_pos->right == this->last_node))
				{//왼쪽이 있고 오른쪽이 없으면 부모와 자식을 연결시켜주면 된다.
					if (free_pos->parent)
					{
						if (free_pos->parent->left == free_pos)
						{
							free_pos->parent->left = free_pos->left;
							free_pos->left->parent = free_pos->parent;
						}
						else
						{
							free_pos->parent->right = free_pos->left;
							free_pos->left->parent = free_pos->parent;
						}
					}
					else
					{
						root_node = free_pos->left;
						free_pos->left->parent = NULL;
					}
				}
				else
				{//왼쪽이 있고 오른쪽이 있을 때
					full_node_change(free_pos);
				}
				value_alloc.destroy(free_pos->value);
				value_alloc.deallocate(free_pos->value, 1);
				node_alloc.destroy(free_pos);
				node_alloc.deallocate(free_pos, 1);
				count_node--;
			}

			size_type	erase(const key_type& k)
			{
				iterator	erase_pos = this->find(k);
				
				if (erase_pos == this->end())
					return (0);
				node_type	prev = this->root_node;
				if (this->root_node == NULL)
					return (0);
				while (1)
				{					
					if (prev)
					{
						if (prev->value->first == k)
							break ;
						else if (prev->value->first < k)
						{
							if (prev->right && prev->right != this->last_node)
								prev = prev->right;
							else
								return (0);
						}
						else
						{
							if (prev->left)
								prev = prev->left;
							else
								return (0);
						}
					}
					else
						break ;
				}
				free_node(prev);
				if (this->count_node == 0)
				{
					this->root_node = NULL;
					this->last_node->right = NULL;
					this->last_node->left = NULL;
				}
				return (1);
			}
			void	erase(iterator first, iterator last)
			{
				if (this->root_node == NULL)
					return ;
				while (first != last)
					this->erase((*(first++)).first);
			}

			iterator	find(const key_type& k)
			{
				node_type	prev = this->root_node;
				if (this->last_node == this->root_node)
					return (this->end());
				while (1)
				{					
					if (prev)
					{
						if (prev->value->first == k)
							return (iterator(prev, last_node));
						else if (prev->value->first < k)
						{
							if (prev->right && prev->right != this->last_node)
								prev = prev->right;
							else
								return (this->end());
						}
						else
						{
							if (prev->left)
								prev = prev->left;
							else
								return (this->end());
						}
					}
					else
						break ;
				}
				return (this->end());
			}
			const_iterator	find(const key_type& k) const
			{
				node_type	prev = this->root_node;
				if (this->last_node == this->root_node)
					return (this->end());
				while (1)
				{					
					if (prev)
					{
						if (prev->value->first == k)
							return (const_iterator(prev, last_node));
						else if (prev->value->first < k)
						{
							if (prev->right && prev->right != this->last_node)
								prev = prev->right;
							else
								return (this->end());
						}
						else
						{
							if (prev->left)
								prev = prev->left;
							else
								return (this->end());
						}
					}
					else
						break ;
				}
				return (this->end());
			}

			node_type		find_min() const
			{
				node_type	ret = root_node;
				if (ret == NULL)
					return (ret);
				while (1)
				{
					if (ret->left)
						ret = ret->left;
					else
						break ;
				}
				return (ret);
			}

			node_type		find_max()
			{//root를 받아서 맨 오른쪽으로 이동한 노드를 리턴
				node_type	ret = root_node;
				if (ret == NULL)
					return (ret);
				while (1)
				{
					// if (ret->right)
					// 	std::cout << "ret right : " << ret->right->value->first << std::endl;
					if (ret->right && ret->right != this->last_node)
					{
						// std::cout << "ret right : " << ret->right->value << std::endl;
						ret = ret->right;
					}
					else
						break ;
				}
				return (ret);
			}

			allocator_type	get_allocator() const { return (this->value_alloc); }
			//map에서 따로 구현해야 한다. 값이 다르게 나온다.

			ft::pair<iterator, bool>	insert(const value_type& val)
			{
				iterator	k_position = this->find(val.first);
				if (k_position == this->end())
				{
					tmp_node = last_node;
					if (tmp_node->left)
						tmp_node->left->right = NULL;
					tmp_node->left = NULL;
					tmp_node->right = NULL;
					tmp_node->value = value_alloc.allocate(1);
					value_alloc.construct(tmp_node->value, val);
					node_type	prev = this->root_node;
					while (1)
					{
						if (prev)
						{
							if (prev->value->first < val.first)
							{
								if (prev->right && prev->right != this->last_node)
									prev = prev->right;
								else
								{
									prev->right = this->tmp_node;
									this->tmp_node->parent = prev;
									break ;
								}
							}
							else
							{
								if (prev->left)
									prev = prev->left;
								else
								{
									prev->left = this->tmp_node;
									this->tmp_node->parent = prev;
									break ;
								}
							}
						}
						else
							break ;
					}
					if (this->root_node == NULL)
					{
						this->root_node = this->tmp_node;
					}
					this->last_node = node_alloc.allocate(1);
					this->find_max()->right = this->last_node;
					this->last_node->left = this->find_max();
					// std::cout << "max : " << this->find_max()->value->first << std::endl;
					this->find_max()->right = this->last_node;
					count_node++;
					// ft::pair<iterator, bool> p1 = ft::pair<iterator, bool>(iterator(this->tmp_node, this->last_node), true);

					
					return (ft::pair<iterator, bool>(iterator(this->tmp_node, this->last_node), true));
				}
				return (ft::pair<iterator, bool>(k_position, false));
			}

			key_compare	key_comp() const
			{ return (key_compare()); }

			iterator	lower_bound(const key_type& k)
			{
				iterator	begin = this->begin();
				iterator	end = this->end();

				while (begin != end)
				{
					if (comp((*begin).first, k) == false)
						break ;
					begin++;
				}
				return (begin);
			}

			const_iterator	lower_bound(const key_type& k) const
			{ return (const_iterator(lower_bound(k))); }

			size_type	max_size() const
			{//max_size는 map에서 따로 구현해야 될 것 같다.
			//값이 다르게 나온다.
				return (allocator_type().max_size());
			}

			reverse_iterator	rbegin()
			{ return (reverse_iterator(this->end())); }
			const_reverse_iterator	rbegin() const
			{ return (const_reverse_iterator(this->end())); }
			reverse_iterator	rend()
			{ return (reverse_iterator(this->begin())); }
			const_reverse_iterator	rend() const
			{ return (const_reverse_iterator(this->begin())); }
			
			void	swap(bst<T, Key, Map, Compare, Alloc, Node>& x)
			{
				// if (x == *this)
				// 	return ;
				node_type	tmp_root = x.root_node;
				node_type	tmp_first = x.first_node;
				node_type	tmp_last = x.last_node;
				size_type	tmp_count = x.count_node;
				allocator_type	tmp_value_alloc = x.value_alloc;
				node_allocator	tmp_node_alloc = x.node_alloc;
				key_compare	tmp_compare = x.comp;
				x.root_node = this->root_node;
				x.first_node = this->first_node;
				x.last_node = this->last_node;
				x.count_node = this->count_node;
				x.value_alloc = this->value_alloc;
				x.node_alloc = this->node_alloc;
				x.comp = this->comp;
				this->root_node = tmp_root;
				this->first_node = tmp_first;
				this->last_node = tmp_last;
				this->count_node = tmp_count;
				this->value_alloc = tmp_value_alloc;
				this->node_alloc = tmp_node_alloc;
				this->comp = tmp_compare;
			}

			iterator	upper_bound(const key_type& k)
			{
				iterator	begin = this->begin();
				iterator	end = this->end();

				while (begin != end)
				{
					if (comp(k, (*begin).first))
						break ;
					begin++;
				}
				return (begin);
			}
			const_iterator	upper_bound(const key_type& k) const
			{ return (const_iterator(upper_bound(k))); }

			
	};

}


#endif