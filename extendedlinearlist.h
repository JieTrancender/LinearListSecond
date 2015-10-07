#ifndef EXTENDEDLINEARLIST_H
#define EXTENDEDLINEARLIST_H

#include "linearlist.h"

template <typename anytype>
class ExtendedLinearList : public LinearList<anytype>
{
public:
	virtual ~ExtendedLinearList(){};
	virtual void clear() = 0;
	virtual void push_back(const anytype &element) = 0;
};

#endif//end of extendedlinearlish.h
