#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <iostream>

//线性表抽象类
template <typename anytype>
class LinearList
{
public:
	virtual ~LinearList(){};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual anytype &get(int theIndex) const = 0;
	virtual int indexOf(const anytype &theElement) const = 0;
	virtual void erase(int theIndex) = 0;
	virtual void insert(int theIndex, const anytype &theElement) = 0;
	virtual void output(std::ostream &out) const = 0;	//把线性表插入输出流out
};


#endif	//linearlist.h
 
