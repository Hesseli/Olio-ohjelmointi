#include "student.h"
#include <vector>
#include <algorithm>

int main () {
    int selection =0;
    vector<Student>studentList;

    do {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0: {
            string Name;
            int Age;
            cout << "Student's name? \n";
            cin >> Name;
            cout << "Student's Age? \n";
            cin >> Age;
            studentList.push_back(Student(Name, Age));
            break;
        }
        case 1: {
            cout << "Students: \n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 2: {
            sort(studentList.begin(), studentList.end(), [] (const Student &a, const Student &b) {
                return a.getName() < b.getName();
            });
            cout << "Students: \n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 3: {
            sort(studentList.begin(), studentList.end(), [] (const Student &a, const Student &b) {
                return a.getAge() < b.getAge();
            });
            cout << "Students: \n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 4: {
            string searchName;
            cout << "Student to be found? ";
            cin >> searchName;

            auto it = find_if(studentList.begin(), studentList.end(), [&] (const Student &s) {
                return s.getName() == searchName;
            });
            if (it != studentList.end()) {
                it -> printStudentInfo();
            } else {
                cout << "Student was not found \n";
            }
            break;
        }
        default:
        cout<< "Wrong selection, stopping..."<<endl;
        break;
    }
    }while(selection < 5);

return 0;
}
