#ifndef _ROOT_H_
#define _ROOT_H_
#include "cell.h"

class root : public cell {
public:
	root (float x, float y, cell* parent);
private:
	void grow();
	void produce();
};

#endif