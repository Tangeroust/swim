#include "swimmer.h"

Swimmer::Swimmer() : distTravel(0.0){
    cout << "\nEnter swimmer name: ";
    cin >> name;

    while(true)
    {
        cout << "How many meters per second does a swimmer swim: ";
        cin >> speed;

        if(cin.good()) break;

        cin.ignore(10, '\n');
        cin.clear();

        cout << "\nError: incorrect data entry. Try again!\n";
    }
}

Swimmer::~Swimmer()
{   }

void Swimmer::increaseDistTravel(double time) {
    distTravel += time * speed;
}

double Swimmer::getDistTravel() const {
    return distTravel;
}

string Swimmer::getName() const {
    return name;
}