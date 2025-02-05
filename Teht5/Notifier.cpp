#include "Notifier.h"
#include "Follower.h"

Notifier::Notifier() {
    cout << "Luodaan notifikaattori" << endl;
}

void Notifier::add(Follower* newFollower) {
    if (followers == nullptr) {
        followers = newFollower;
    } else {
        Follower* start = followers;
        while (start -> next != nullptr) {
            start = start -> next;
        }
        start -> next = newFollower;
    }
    cout << newFollower->getName() << " alkoi seurata sinua!" << endl;
}

void Notifier::remove(Follower* target) {
    if (followers == nullptr) {
        cout << "Ei ole seuraajia poistettavaksi asti" << endl;
        return;
    }

    if (followers == target) {
        followers = followers->next;
        target -> next = nullptr;
    }

    Follower* start = followers;
    while (start -> next != nullptr && start -> next != target) {
        start = start -> next;
    }

    if (start -> next != nullptr && start -> next == target) {
        start -> next = target->next;
        target -> next = nullptr;
        cout << target->getName() << " eliminoitu" << endl;
    }
}




void Notifier::print() {
    Follower* start = followers;
    cout << "Seuraajat" << endl;
    while (start != nullptr) {
        cout <<  start->getName() << endl;
        start = start->next;
    }
}

void Notifier::post(string message) {
    cout << "Lahetetaan viesti: " << message << endl;
    Follower* start = followers;
    while (start != nullptr) {
        start->post(message);
        start = start->next;
    }
}
