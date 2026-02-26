#ifndef _LEAF_H_
#define _LEAF_H_
#include "cell.h"

class leaf : public cell {
public:
	leaf (float x, float y, cell* parent);
private:
	void grow();
	void produce();
};

#endif