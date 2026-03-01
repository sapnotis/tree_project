#ifndef _POI_H_
#define _POI_H_

#include "cell.hpp"
#include "producer.hpp"
#include <vector>

class POI {
private:
    Coords coords;
    float radius;
    char type;
public:
    POI(Coords coords, float radius, char type);
    virtual ~POI();
    Coords getCoords();
    char getType();
    void produceRequest(producer* producer);
};

// ���������� ������� (�������� �����)
// extern POI* g_lights[10]; //������ ���������� �����
// extern int g_light_count; //������� ���������� �����
// extern POI* g_minerals[10]; // ����������
// extern int g_mineral_count;

extern std::vector<POI*> lights;
extern std::vector<POI*> lakes;

#endif