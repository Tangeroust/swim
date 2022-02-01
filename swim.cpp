#include "swim.h"

Swim::Swim(int nS, double dist) : numbSwimmer(nS), distance(dist){
    for(int i = 0; i < numbSwimmer; i++)
    {
        Swimmer sr;
        swimmer.push_back(sr);
    }
}

Swim::~Swim(){

    for(int i = 0; i < numbSwimmer; i++)
        track[i].join();
}

void Swim::oneTrack(Swimmer& oneSwimer, double allDist, multiset <Place>& finTime){

    time_t realTime = time(nullptr);

    while(oneSwimer.getDistTravel() < allDist)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        oneSwimer.increaseDistTravel(1);
    }

    Place pl(oneSwimer.getName(), time(nullptr) - realTime);

    block.lock();
    finTime.insert(pl);
    block.unlock();
}

void Swim::start(){
    for(int i = 0; i < numbSwimmer; i++)
        track.emplace_back(&Swim::oneTrack, this, ref(swimmer[i]), distance, ref(place));

    time_t counter = 1;

    while(place.size() < numbSwimmer)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        cout << "\nTime: " << counter << "s";

        for(int i = 0; i < numbSwimmer; i++)
        {
            cout << "\n" << swimmer[i].getName() << " swam ";

            if(swimmer[i].getDistTravel() > distance) cout << distance;
            else cout << swimmer[i].getDistTravel();

            cout << " meters";
        }
        cout << "\n\n";

        counter++;
    }
}

void Swim::end(){

    multiset <Place> :: iterator it;
    it = place.begin();

    time_t lastRival = 0;

    cout << "\n\nResults:";

    for(int i = 1; it != place.end(); i++, it++)
    {
        if(lastRival == it->getTime()) i--;

        cout << "\n " << i << " place: " << it->getName() << " " << it->getTime() << "s";

        lastRival = it->getTime();
    }

}