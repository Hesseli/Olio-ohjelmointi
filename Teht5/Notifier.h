#ifndef NOTIFIER_H
#define NOTIFIER_H
#include "Follower.h"

#include <string>

class Notifier {
    public:
        Notifier();
        void add(Follower*);
        void remove(Follower*);
        void print();
        void post(string);

    private:
        Follower *followers = nullptr;
};

#endif // NOTIFIER_H
