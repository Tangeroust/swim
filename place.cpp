#include "place.h"

Place::Place(string text, time_t fTime) : name(text), finTime(fTime)
{   }

Place::~Place()
{   }

string Place::getName() const {
    return name;
}

time_t Place::getTime() const {
    return finTime;
}

bool operator < (const Place& pLeft, const Place& pRight){
    return pLeft.finTime < pRight.finTime;
}

bool operator == (const Place& pLeft, const Place& pRight){
    return pLeft.finTime == pRight.finTime;
}