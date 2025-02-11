#include "student.h"


Student::Student(string n, int a) {
    Name = n;
    Age = a;
}

void Student::setAge(int a) {
    Age = a;
}

void Student::setName(string n) {
    Name = n;
}


int Student::getAge() const {
    return Age;
}

string Student::getName() const {
    return Name;
}

void Student::printStudentInfo() const {
    cout << "Name: " << Name << ", Age: " << Age << endl;
}

