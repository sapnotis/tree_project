#include "root.hpp"
#include "stem.hpp"
#include "cell.hpp"
#include <iostream>

root::root(Coords coords) : cell(coords, nullptr) {
    energy = 10;
    water = 10;
}

root::~root() { }

void root::tick() {
    if ( this->alive )
        return;
    
    energy += 0.1;
    water += 0.1;
    
    // <- ��� �������� tick � ���� �����
}

bool root::SpendRequest(float neededE, float neededW) {
    if (energy >= neededE && water >= neededW) {
        energy -= neededE;
        water -= neededW;
        return true; // true = �������, ���������
    }
    return false; // false = �� �������
}

void root::getResource(char type, float amount) {
    if ( type=='e' )
        this->energy += amount;
    else if ( type=='w' )
        this->water += amount;
    else
        std::cout << "illegal char at getResource" << std::endl;
}