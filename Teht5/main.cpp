#include <iostream>
#include "Follower.h"
#include "Notifier.h"

using namespace std;

int main()
{
    Notifier n;
    Follower a("Tupu");
    Follower b("Hupu");
    Follower c("Lupu");

    n.add(&a);
    n.add(&b);
    n.add(&c);

    n.print();

    n.post("Tottoroo komppanja");

    n.remove(&b);

    n.post("Komppanjassa heratys!");

    return 0;
}
