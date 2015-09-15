#ifndef CHAINNODE_HPP
#define CHAINNODE_HPP

//链表节点的结构定义
template <typename anytype>
struct ChainNode
{
	anytype element;
	ChainNode<anytype> *next;
	ChainNode(){};//默认构造函数
	ChainNode(const anytype &element)
	{
		this->element = element;
	}
	ChainNode(const anytype &element, ChainNode<anytype> *next)
	{
		this->element = element;
		this->next = next;
	}
};

#endif
