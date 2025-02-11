#ifndef FOLLOWER_H
#define FOLLOWER_H

using namespace std;

#include <iostream>

class Follower {
    public:
        Follower(string);
        string getName();
        void post(string);
        Follower *next = nullptr;

    private:
        string name;

};

#endif // FOLLOWER_H
