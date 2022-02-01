#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::string;

class Swimmer {
private:
    string name;
    float speed;
    double distTravel;

public:
    Swimmer();
    ~Swimmer();

    void increaseDistTravel(double time);
    double getDistTravel() const;
    string getName() const;
};


