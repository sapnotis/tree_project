#include "POI.hpp"
#include "cell.hpp"
#include "producer.hpp"
#include "root.hpp"
#include <cmath>

POI::POI(Coords coords_, float r_, char t_){
    radius = r_;
    type = t_;
    coords = coords_;
}

POI::~POI() { };

Coords POI::getCoords() {
    return this->coords;
};

char POI::getType() {
    return this->type;
};

void POI::produceRequest(producer* producer) {
    Coords cellcoords = producer->getData().coords;

    float dx = cellcoords.x - this->coords.x;
    float dy = cellcoords.y - this->coords.y;

    float dist = std::sqrt(dx*dx + dy*dy);

    if (dist <= radius) {
        cell* rootptr = producer->getData().root;
        root* zeroptr = ( root* ) &rootptr;
        zeroptr->getResource(this->type, 1);
    }
}

// ������� ���������� �������??? ���� ��� � �� �������, ������ �����
// POI* g_lights[10] = { nullptr };
// int g_light_count = 0;
// POI* g_minerals[10] = { nullptr };
// int g_mineral_count = 0;