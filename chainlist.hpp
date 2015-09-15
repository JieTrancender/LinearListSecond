#ifndef CHAINLIST_HPP
#define CHAINLIST_HPP

#include "linearlish.h"
#include "chainnode.hpp"

template <typename anytype>
class ChainList : public LinearList
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
	void erase(int index, const anytype &element);
	void output(std::ostream os) const;

protected:
	void checkIndex(int index) const;	//检查索引是否有效
	ChainNode<anytype> *m_first_node;
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
		m_first_node = nullptr;
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
	}
}

template <typename anytype>
anytype &get(int index) const
{
	try
	{
		checkIndex(index);
		ChainNode *temp = m_first_node;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp->element;
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}
}

#endif
