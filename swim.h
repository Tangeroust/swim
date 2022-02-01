#pragma once

#include <thread>
#include <vector>
#include <ctime>
#include <mutex>
#include <set>

#include "swimmer.h"
#include "place.h"

using std::vector;    using std::ref;
using std::thread;    using std::mutex;
using std::multiset;

class Swim {
private:
    int numbSwimmer;
    double distance;
    mutex block;
    vector <thread> track;
    multiset <Place> place;
    vector <Swimmer> swimmer;

    void oneTrack(Swimmer& oneSwim, double allDist, multiset <Place>& finTime);

public:
    explicit Swim(int numbSwimmer, double distance);
    ~Swim();

    void start();
    void end();
};


