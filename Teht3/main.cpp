#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Chef {
    public:
        Chef(string name) : chefName(name) {
            cout << "Chef " << chefName << " konstruktor" << endl;
        }

        virtual ~Chef() {
            cout << "Chef " << chefName << " destruktori" << endl;
        }

        string getName() const {
            return chefName;
        }

        int makeSalad(int ingredientCount) {
            int portions = ingredientCount / 5;
            cout << "Chef " << chefName << " with " << ingredientCount << " items can make salad " << portions << " portions" << endl;
            return portions;
        }

        int makeSoup(int ingredientCount) {
            int portions = ingredientCount / 3;
            cout << "Chef " << chefName << " with " << ingredientCount << " items can make soup " << portions << " portions" << endl;
            return portions;
        }

    private:
        string chefName;
};

class ItalianChef : public Chef {
    public:
        ItalianChef(string name) : Chef(name), password("pizza"), flour(0), water(0) {
            cout << "ItalianChef " << name << " konstruktor" << endl;
        }

        ~ItalianChef() {
            cout << "ItalianChef destruktori" << endl;
        }

        bool askSecret(string inputPassword, int flourAmount, int waterAmount) {
            if (inputPassword == password) {
                cout << "Password ok!" << endl;
                return makePizza(flourAmount, waterAmount);
            } else {
                cout << "Incorrect password!" << endl;
                return false;
            }
        }

    private:
        bool makePizza(int flourAmount, int waterAmount) {
            flour = flourAmount;
            water = waterAmount;
            int pizzas = min(flour / 5, water / 5);
            cout << "ItalianChef " << getName() << " with " << flour << " flour and " << water << " water can make " << pizzas << " pizzas" << endl;
            return pizzas > 0;
        }

        string password;
        int flour;
        int water;
};

int main() {
    cout << "Kumman kokin haluaisitte tekevan ruokanne tanaan? (Luigi / Kape): ";
    string selectedChef;
    cin >> selectedChef;

    transform(selectedChef.begin(), selectedChef.end(), selectedChef.begin(), ::tolower);

    Chef* chef = nullptr;

    if (selectedChef == "luigi") {
        chef = new ItalianChef("Luigi");
    } else if (selectedChef == "kape") {
        chef = new Chef("Kape");
    } else {
        cout << "Kyseista kokkia ei ole" << endl;
        return 1;
    }

    string choice;
    cout << "Valitse: Salaatti, Keitto tai Pizza: ";
    cin >> choice;

    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    if (choice == "salaatti" || choice == "1") {
        int items;
        cout << "Anna ainesten maara: ";
        cin >> items;
        chef->makeSalad(items);
    } else if (choice == "keitto" || choice == "2") {
        int items;
        cout << "Anna ainesten maara: ";
        cin >> items;
        chef->makeSoup(items);
    } else if (choice == "pizza" || choice == "3") {
        ItalianChef* italianChef = dynamic_cast<ItalianChef*>(chef);
        if (italianChef) {
            string password;
            cout << "Anna salasana: ";
            cin >> password;

            int flour, water;
            cout << "Anna jauhojen maara: ";
            cin >> flour;
            cout << "Anna veden maara: ";
            cin >> water;

            italianChef->askSecret(password, flour, water);
        } else {
            cout << "Pizzaa voi valmistaa vain Luigi!" << endl;
        }
    } else {
        cout << "Virheellinen valinta!" << endl;
    }

    delete chef;
    return 0;
}
