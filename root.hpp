#ifndef _ZERO_H_
#define _ZERO_H_

#include "cell.hpp"

class root : public cell {

private:
    float energy;
    float water; 

public:
    root(Coords coords);
    virtual ~root();
    
    void tick();
    bool SpendRequest(float neededE, float neededW);
    void getResource(char type, float amount);
    
    //�� � ��� �������� ������� � ���� ���������, ����� �������� ��� ��������� ����� ���� �����
};

#endif