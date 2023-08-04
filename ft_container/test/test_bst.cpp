#include "vector.hpp"
#include <utility>
#include <map>
#include <iterator>
#include <vector>

template <class T>
class bst
{//data값을 가지고 parent, left, right로 연결
	public:
		typedef T	value_type;

		value_type	data;
		bst*		parent;
		bst*		left;
		bst*		right;

		//기본생성자는 사용하지 않지만 선언은 해준다.
		bst() : data(), parent(NULL), left(NULL), right(NULL) {}

		//data는 비어있는 상태로 parent, left, right의 값을 받아오고
		//parent, left, right의 기본 값은 NULL로 한다.
		bst(bst* parent = NULL, bst* left = NULL, bst* right = NULL) :
			data(), parent(parent), left(left), right(right) {}
		
		//bst 복사 생성자
		bst(const bst& bst_copy) : data(bst_copy.data), parent(bst_copy.parent),
			left(bst_copy.left), right(bst_copy.right) {}
};

template <class T>
class bst_it
{//간단한 bst_iterator
	public:
		T*	_node; //현재 node
		T*	_last_node; //현재 node의 가장 큰 값
	
	bst_it() : _node(), _last_node() {}
	~bst_it() {}
	bst_it(T* node) : _node(node)
	{//node만 인자로 받고 last_node를 설정하여 생성
		T*	prev = node;
		while (prev->parent)
		//prev를 root로 올린다.
			prev = prev->parent;
		//right이 있는 경우 계속 right으로 내려간다.
		while (prev->right)
			prev = prev->right;		
		_last_node = prev;
	}
	bst_it(T* node, T* last_node) : _node(node), _last_node(last_node) {}

	bst_it&	operator++()
	{
		T*	prev = _node;

		if (prev->right == NULL)
		{//node가 오른쪽이 없을 때
			if (prev->parent == NULL)
			{//node가 parent가 없을 때
			//seg가 떠야하지만 일단 자신 반환
				return (*this);
			}
			else
			{//node가 parent가 있을 때			
				if (prev->parent->right == prev)
				{//node->parent의 오른쪽이 node일 때
					while (prev->parent && prev == prev->parent->right)
					//node->parent가 있으면서
					//node가 node->parent의 오른쪽이 아닐 때까지 node->parent로 계속 이동
						prev = prev->parent;
					if (prev->parent == NULL)
					{//root까지 올라갔는데 값이 없으므로 ++이 제대로 작동할 수 없다.
						return (*this);						
					}
					else if (prev == prev->parent->left)
					//node가 node->parent의 왼쪽이 되었을 때 최종적으로 node->parent로 이동
						prev = prev->parent;
				}
				else
				{//node->parent의 왼쪽이 node일 때
				//node를 node->parent로 이동
					prev = prev->parent;
				}
			}
		}
		else
		{//node가 오른쪽이 있을 때
			prev = prev->right;
			while (prev->left)
				prev = prev->left;
			//node를 right로 이동한 후 left가 없을 때까지 left로 계속 이동
			//마지막 left로 이동한 것이 node가 된다.
		}
		_node = prev;
		return *this;
	}

	bst_it&	operator--()
	{
		T*	prev = _node;

		if (prev->left == NULL)
		{//node가 왼쪽이 없을 때
			if (prev->parent == NULL)
			{//node가 parent이 없을 때
			//seg가 떠야 하지만 일단 자신을 반환
				return (*this);
			}
			else
			{//node가 parent이 있을 때
				if (prev == prev->parent->right)
				//node->parent의 오른쪽이 node일 때 node를 parent로 이동
					prev = prev->parent;
				else
				{
				//parent로 계속 이동할 때 결국 오른쪽이 아니었다면 seg를 띄워야된다.
					while (prev->parent && prev == prev->parent->left)
					//node->parent의 왼쪽이 node일 때 node가 parent의 왼쪽이 아닐 때까지
					//parent가 있으면 parent로 계속 이동
						prev = prev->parent;
					if (prev->parent == NULL)
					//root까지 올라갔음에도 없다는 것으므로 --정상 작동 불가
						return (*this);
					if (prev == prev->parent->right)
					//node->parent의 오른쪽이 되었을 때 최종적으로 node->parent로 이동
						prev = prev->parent;
				}
			}
		}
		else
		{//node가 왼쪽이 있을 때
			prev = prev->left;
			while (prev->right)
				prev = prev->right;
			//node를 left로 이동한 후 right가 없을 때까지 right로 계속 이동
			//마지막 right로 이동한 것이 node가 된다.
		}
		_node = prev;
		return (*this);
	}
};


template <class T>
bool	operator==(const bst<T>& lhs, const bst<T>& rhs)
{ return (lhs.data == rhs.data); }

template <class T>
bool	operator!=(const bst<T>& lhs, const bst<T>& rhs)
{ return (!(lhs.data == rhs.data)); }

template <class T>
bool	operator<(const bst<T>& lhs, const bst<T>& rhs)
{ return (lhs.data < rhs.data); }

template <class T>
bool	operator<=(const bst<T>& lhs, const bst<T>& rhs)
{ return (!(rhs.data < lhs.data)); }

template <class T>
bool	operator>(const bst<T>& lhs, const bst<T>& rhs)
{ return (rhs.data < lhs.data); }

template <class T>
bool	operator>=(const bst<T>& lhs, const bst<T>& rhs)
{ return (!(lhs.data < rhs.data)); }


template <class T>
void	bst_insert(bst<T> *bst_data, T data)
{
	bst_data->data = data;
	bst_data->parent = NULL;
	bst_data->left = NULL;
	bst_data->right = NULL;
}

template <class T>
void	bst_push_back(bst<T> *origin, bst<T> *bst)
{//origin에 bst를 넣는다.
	::bst<T>*	prev = origin;
	while (prev->parent)
	//값을 넣을 bst<T>의 root로 올라간다.
		prev = prev->parent;
	while (1)
	{//값에 따라서 계속 내려가면서 값이 있는지 확인하고 빈 자리에 값을 넣는다.
		if (prev->data == bst->data)
		{//값이 같으면 그냥 종료
			return ;
		}
		else if (prev->data < bst->data)
		{//값이 크면 right로 내려가기
			if (prev->right)
			//right가 있을 때 right로 내려간다.
				prev = prev->right;
			else
			{//right가 없다면 right에 bst를 넣어준다.
				prev->right = bst;
				bst->parent = prev;
				return ;
			}
		}
		else
		{//값이 작으면 left로 내려가기
			if (prev->left)
			//left가 있을 때 left로 내려간다.
				prev = prev->left;
			else
			{//left가 없을 때 left에 bst를 넣어준다.
				prev->left = bst;
				bst->parent = prev;
				return ;
			}
		}
	}
}

template <class T>
void	bst_print(bst<T> bst_data)
{ std::cout << "bst : " << bst_data.data << std::endl; }

template <class Pair, class first_type>
void	insert_pair(Pair *r_pair, Pair *i_pair)
{
	first_type	*prev = &r_pair->first;
	//맨 먼저 루트 노드로 올라가야한다.
	while (prev->parent)
		prev = prev->parent;
	if (*prev == i_pair->first)
	//r_pair와 i_pair가 같으면 그냥 종료
		return ;
	//r_pair의 크기와 i_pair의 크기를 비교해서 먼저 i_pair의 값을 가지고 있는 것이 있었는지 확인
	//만약 값을 가지고 있었다면 그냥 종료하고, 값이 없었다면 값을 삽입한다.
	while (1)
	{//값이 있었다면 그냥 종료될 것이고, 값이 없다면 prev에 삽입될 위치가 저장될 것
		if (*prev == i_pair->first)
			return ;
		else if (*prev > i_pair->first) //삽입될 값이 작은 경우
		{
			if (prev->left != NULL) //왼쪽이 있을 경우에만 prev를 왼쪽으로 바꾼다.
				prev = prev->left;
			else
				break ;
		}
		else if (*prev < i_pair->first) //삽입될 값이 큰 경우
		{
			if (prev->right != NULL) //오른쪽이 있을 경우에만 prev를 오른쪽으로 바꾼다.
				prev = prev->right;
			else
				break ;
		}
	}
	if (*prev > i_pair->first)
	{
		prev->left = &i_pair->first;
		i_pair->first.parent = prev;
		std::cout << "prev : " << prev->left->data << std::endl;
		std::cout << "parent : " << i_pair->first.parent->data << std::endl;
	}
	else if (*prev < i_pair->first)
	{
		prev->right = &i_pair->first;
		i_pair->first.parent = prev;
	}
}

template <class Pair, class first>
void	pair_print(Pair pair)
{
	int i = 0;
	//일단 root로 올라가기
	first	*prev = &pair.first;
	
	while (1)
	{
		if (prev->parent == NULL)
			break ;
		prev = prev->parent;
	}
	//root에 root를 저장
	first	*root = prev;

	//last에 가장 오른쪽을 저장 
	first	*last = prev;
	while (1)
	{
		if (last->right == NULL)
			break ;
		last = last->right;
	}
	std::cout << "last : " << last->data << std::endl;
	//std::cout << "pair[" << i << "] : " << prev->data << std::endl;
	//맨 왼쪽으로 내려가기
	while (1)
	{
		if (prev->left == NULL)
			break ;
		prev = prev->left;
	}
	//std::cout << "pair[" << i << "] : " << prev->data << std::endl;
	//왼쪽, 부모, 오른쪽 순으로 출력하기
	while (1)
	{
		if (prev)
			std::cout << "pair[" << i << "] : " << prev->data << std::endl;
		i++;
		if (prev == last)
			break ;
		//현재 노드가 오른쪽이라면 현재 노드보다 큰 값이 나올 때까지 부모노드로 올라간다.
		//현재 노드가 오른쪽이라면 부모 노드가 현재 노드보다 작으므로 이미 출력했을 것이다.
		//따라서 출력된 값을 건너뛰기 위해 부모노드들을 건너뛰는 것이다.

		if (prev->parent == NULL && prev->right == NULL)
			break ;
		int	pass = 0;		
		
		if (prev->parent && prev->right == NULL)
		{
			first	*check = prev;
			while (check->data > check->parent->data)
			{
				check = check->parent;
				pass = 1;
			}
			if (check != root)
				prev = check;
		}
		if ((prev->parent && prev->right == NULL) || pass == 1)
		//부모 노드가 있으면서 오른쪽이 없으면 그냥 부모로 올라가기
			prev = prev->parent;
		else
		{//부모 노드가 있으면서 오른쪽이 있다면 오른쪽으로 가기
			prev = prev->right;
			//오른쪽으로 갔는데 왼쪽이 존재한다면 제일 왼쪽으로 가기
			while (1)
			{
				if (prev->left)
					prev = prev->left;
				else
					break ;
			}
		}
	}
}

struct	invalid {};


int main(void)
{
	//****************************std::map 확인
	// std::map<int, int>	map1;
	// std::pair<std::map<int, int>::iterator, bool>	p1;
	// std::pair<std::map<int, int>::iterator, bool>	p2;
	
	// // int	num1 = 10;
	// // int num2 = 10;
	// map1.insert(std::pair<int, int>(1, 20));
	// map1.insert(std::pair<int, int>(-2, 20));
	// map1.insert(std::pair<int, int>(-1, 20));
	// map1.insert(std::pair<int, int>(3, 20));
	// p1 = map1.insert(std::pair<int, int>(1, 20));
	// p2 = map1.insert(std::pair<int, int>(-200, 20));
	// std::map<int, int>::iterator	map_it1;
	// map_it1 = map1.find(1);
	// std::cout << "first : " << map_it1->first << ", second : " << map_it1->second;
	// std::cout << "p1 : " << p1.second << ", p2 : " << p2.second;


	//*******************pair가 제대로 작동하는지 체크
	// bst<int>	bst1(NULL, NULL, NULL);
	// bst<int>	bst2(NULL, NULL, NULL);
	// bst<int>	bst3(NULL, NULL, NULL);
	// bst<int>	bst4(NULL, NULL, NULL);
	// bst<int>	bst5(NULL, NULL, NULL);
	// bst<int>	bst6(NULL, NULL, NULL);
	// bst<int>	bst7(NULL, NULL, NULL);
	// bst<int>	bst8(NULL, NULL, NULL);
	// bst<int>	bst9(NULL, NULL, NULL);
	// bst<int>	bst10(NULL, NULL, NULL);
	// int	num = 100;
	// int	num2 = 20001;
	// int	num3 = 1000;
	// int	num4 = 132;
	// int	num5 = 199;
	// int	num6 = 200;
	// int	num7 = 20000;
	// int	num8 = 2100;
	// int	num9 = 20;
	// int	num10 = -200;

	// bst_insert(&bst1, num);
	// bst_insert(&bst2, num2);
	// bst_insert(&bst3, num3);
	// bst_insert(&bst4, num4);
	// bst_insert(&bst5, num5);
	// bst_insert(&bst6, num6);
	// bst_insert(&bst7, num7);
	// bst_insert(&bst8, num8);
	// bst_insert(&bst9, num9);
	// bst_insert(&bst10, num10);
	// ft::pair<bst<int>, int>	p1 = ft::make_pair<bst<int>, int>(bst1, num2);
	// ft::pair<bst<int>, int>	p2(bst2, num2);
	// ft::pair<bst<int>, int>	p3(bst3, num3);
	// ft::pair<bst<int>, int>	p4(bst4, num4);
	// ft::pair<bst<int>, int>	p5(bst5, num5);
	// ft::pair<bst<int>, int>	p6(bst6, num6);
	// ft::pair<bst<int>, int>	p7(bst7, num7);
	// ft::pair<bst<int>, int>	p8(bst8, num8);
	// ft::pair<bst<int>, int>	p9(bst9, num9);
	// ft::pair<bst<int>, int>	p10(bst10, num10);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p2);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p3);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p4);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p5);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p6);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p7);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p8);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p9);
	// insert_pair<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(&p1, &p10);
	// pair_print<ft::pair<bst<int>, int>, ft::pair<bst<int>, int>::first_type>(p1);


	//**************************bst_iterator 작동 확인
	// bst<int>	bst1(NULL, NULL, NULL);
	// bst<int>	bst2(NULL, NULL, NULL);
	// bst<int>	bst3(NULL, NULL, NULL);
	// int	num1 = -3;
	// int	num2 = 1;
	// int	num3 = -9;
	// bst_insert(&bst1, num1);
	// bst_insert(&bst2, num2);
	// bst_insert(&bst3, num3);
	// bst_push_back(&bst1, &bst2);
	// bst_push_back(&bst2, &bst3);

	// bst_it<bst<int> >	bst_it1(&bst1);
	// std::cout << bst_it1._node->data;
	// ++bst_it1;
	// std::cout << bst_it1._node->data;
	// ++bst_it1;
	// std::cout << bst_it1._node->data;
	// --bst_it1;
	// std::cout << bst_it1._node->data;
	// --bst_it1;
	// std::cout << bst_it1._node->data;
	// --bst_it1;
	// std::cout << bst_it1._node->data;
	// --bst_it1;
	// std::cout << bst_it1._node->data;


	//**************************bst<pair>확인
	// bst<ft::pair<int, int> >	bst1(NULL, NULL, NULL);
	// bst<ft::pair<int, int> >	bst2(NULL, NULL, NULL);
	// bst<ft::pair<int, int> >	bst3(NULL, NULL, NULL);
	// ft::pair<int, int>	p1(1, 10);
	// ft::pair<int, int>	p2(2, 20);
	// ft::pair<int, int>	p3(3, 30);
	// bst_insert(&bst1, p1);
	// bst_insert(&bst2, p2);
	// bst_insert(&bst3, p3);
	// bst_push_back(&bst1, &bst2);
	// bst_push_back(&bst1, &bst3);
	// bst_it<bst<ft::pair<int, int> > >	it1(&bst1);
	// ++it1;
	// ++it1;
	// std::cout << "first : " << it1._node->data.first;
	// std::cout << ", second : " << it1._node->data.second << std::endl;
	// --it1;
	// std::cout << "first : " << it1._node->data.first;
	// std::cout << ", second : " << it1._node->data.second << std::endl;

	std::vector<int>	vec;
	vec.push_back(10);
	vec.push_back(4);
	vec.push_back(6);
	std::vector<int>::iterator	it1 = vec.begin();
	std::vector<int>::iterator	it2 = vec.end();
	typedef std::vector<int>::iterator	iter;
	std::reverse_iterator<iter>	r1(it1);
	std::reverse_iterator<iter>	r2(it2);
	// r1--;
	// r2++;
	if (it1 < it2)
		std::cout << "it1 < it2" << std::endl;
	else
		std::cout << "it1 >= it2" << std::endl;
	std::cout << "begin : " << *it1 << ", end : " << *(it2 - 1) << std::endl;
	std::cout << "r1 : " << *r1.base() << ", r2 : " << *(r2 + 1).base() << std::endl;
	if (r1 < (r2 + 1))
		std::cout << "r1 < r2" << std::endl;
	else
		std::cout << "r1 >= r2" << std::endl;
	std::cout << "r1 - r2 : " << r2 - r1 << std::endl;
	
}