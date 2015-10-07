#ifndef CHAINLIST_HPP
#define CHAINLIST_HPP

#include "extendedlinearlist.h"
#include "linearlist.h"
#include "chainnode.hpp"
#include <sstream>

template <typename anytype>
class ChainList : public ExtendedLinearList<anytype>
{
public:
	//构造函数、复制构造函数、析构函数
	ChainList(int initialCapacity = 10);	//实质上构造函数并没有创建对象
	ChainList(const ChainList<anytype> &list);
	~ChainList();

	//抽象数据类型ADT方法
	bool empty() const { return m_list_size == 0; };
	int size() const { return m_list_size; };
	anytype &get(int index) const;
	int indexOf(const anytype &element) const;
	void erase(int index);
	void insert(int index, const anytype &element);
	void output(std::ostream &os) const;

	//扩展抽象数据类型ADT方法
	void clear();
	void push_back(const anytype &element);

	//友元函数重载运算符 <<
	template <typename T>
	friend std::ostream &operator<<(std::ostream &os, const ChainList<T> &list);

protected:
	void checkIndex(int index) const;	//检查索引是否有效
	ChainNode<anytype> *m_first_node;
	ChainNode<anytype> *m_last_node;
	int m_list_size;
};

//检查索引
template <typename anytype>
void ChainList<anytype>::checkIndex(int index) const
{
	if (0 > index || index >= m_list_size)
	{
		std::string str = "The index should be[0, m_list_size)";
		throw(str);
	}
}

//构造函数
template <typename anytype>
ChainList<anytype>::ChainList(int initialCapacity)
{
	try
	{
		if (initialCapacity < 0)
		{
			std::string str = "The initial capacity should be >= 0";
			throw(str);
		}
		m_first_node = nullptr;
		m_last_node = nullptr;
		m_list_size = 0;
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}
}

//复制构造函数
template <typename anytype>
ChainList<anytype>::ChainList(const ChainList<anytype> &list)
{
	m_list_size = list.m_list_size;
	if (m_list_size == 0)
		m_first_node = m_last_node = nullptr;
	else
	{
		//链表list非空
		ChainNode<anytype> *source_node = list.m_first_node;	//需要复制链表的节点
		m_first_node = new ChainNode<anytype>(source_node->element);	//复制链表的首元素
		source_node = source_node->next;
		ChainNode<anytype> *last_node = m_first_node;	//当前链表的最后一个节点
		while (source_node != nullptr)	//循环复制剩余元素
		{
			last_node->next = new ChainNode<anytype>(source_node->element);
			last_node = last_node->next;
			source_node = source_node->next;
		}
		last_node->next = nullptr;	//链表结束
		m_last_node = last_node;
	}
}

//析构函数
template <typename anytype>
ChainList<anytype>::~ChainList()
{
	while (m_first_node != nullptr)
	{
		ChainNode<anytype> *nextNode = m_first_node->next;
		delete m_first_node;
		m_first_node = nextNode;
	}
}


//获得索引index的值
template <typename anytype>
anytype &ChainList<anytype>::get(int index) const
{
	ChainNode<anytype> *temp = m_first_node;
	try
	{
		checkIndex(index);
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp->element;
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
		return temp->element;
	}
}

//返回元素element首次出现时的索引
//如果存在就返回首次出现的索引，如果不存在就返回-1
template <typename anytype>
int ChainList<anytype>::indexOf(const anytype &element) const
{
	ChainNode<anytype> *current_node = m_first_node;
	int index = 0;
	while (current_node != nullptr && current_node->element != element)
	{
		current_node = current_node->next;
		++index;
	}
	if (current_node == nullptr)
		return -1;
	else
		return index;
}

//删除索引为index的元素
template <typename anytype>
void ChainList<anytype>::erase(int index)
{
	try
	{
		checkIndex(index);
		ChainNode<anytype> *delete_node;
		if (index == 0)
		{
			delete_node = m_first_node;
			m_first_node = nullptr;
		}
		else
		{
			//指正p指向需要删除节点的前驱节点
			ChainNode<anytype> *p = m_first_node;
			for (int i = 0; i < index - 1; ++i)
			{
				p = p->next;
			}
			delete_node = p->next;
			p->next = p->next->next;
		}
		--m_list_size;
		delete delete_node;
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}
}

//类型转换
template <typename input,typename output>
output Convert(input element)
{
	output value;
	std::stringstream ss;
	ss << element;
	ss >> value;
	return value;
}

//在index位置插入元素element
template <typename anytype>
void ChainList<anytype>::insert(int index, const anytype &element)
{
	try
	{
		if (index < 0 || index > m_list_size)
		{
			std::string str = "The index should be [0," + Convert<int, std::string>(m_list_size) + "]";
			throw(str);
		}
		if (index == 0)
			m_first_node = new ChainNode<anytype>(element, m_first_node);
		else
		{

			ChainNode<anytype> *p = m_first_node;
			for (int i = 0; i < index - 1; ++i)
			{
				p = p->next;
			}
			p->next = new ChainNode<anytype>(element, p->next);
		}
		++m_list_size;
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}
}

//输出函数
template <typename anytype>
void ChainList<anytype>::output(std::ostream &os) const
{
	for (ChainNode<anytype> *iter = m_first_node; iter != nullptr; iter = iter->next)
	{
		os << iter->element;
	}
}

//重载运算符 <<
template <typename anytype>
std::ostream &operator<<(std::ostream &os, const ChainList<anytype> &list)
{
	list.output(os);
	return os;
}

//clear函数：删除所有链表节点
template <typename anytype>
void ChainList<anytype>::clear()
{
	while (m_first_node != nullptr)
	{
		ChainNode<anytype> *p = m_first_node->next;
		delete m_first_node;
		m_first_node = p;
	}
	m_list_size = 0;
}


//push_back函数:链表尾端插入元素element的节点
template <typename anytype>
void ChainList<anytype>::push_back(const anytype &element)
{
	ChainNode<anytype> *new_node = new ChainNode<anytype>(element, nullptr);
	if (m_first_node == nullptr)
		m_first_node = new_node;
	else
	{
		m_last_node->next = new_node;
		m_last_node = new_node;
	}
}
#endif
