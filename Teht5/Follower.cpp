#include "Follower.h"
#include "Notifier.h"

using namespace std;

Follower::Follower(string n) {
    name = n;
    cout << getName() << " syntyi" << endl;
}

string Follower::getName() {
    return name;
}

void Follower::post(string message) {
    cout << name << " sai viestin " << message << endl;
}
