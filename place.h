#include "swimmer.h"
#include <ctime>

using std::time_t;

class Place{
private:
    string name;
    time_t finTime;

public:
    explicit Place(string text = "N/A", time_t fTime = 0);
    ~Place();

    string getName() const;
    time_t getTime() const;

    friend bool operator < (const Place& pLeft, const Place& pRight);
    friend bool operator == (const Place& pLeft, const Place& pRight);
};