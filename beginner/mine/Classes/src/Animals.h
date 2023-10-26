//
// Created by fsemerar on 10/25/23.
//

#ifndef CLASSES_ANIMALS_H
#define CLASSES_ANIMALS_H

using namespace std;

namespace animals {

    class Cat {
    private:
        bool happy;

    protected:
        string name;

    public:
        Cat(bool happy, string name) {
            this->happy = happy;
            this->name = name;
        }

        Cat() { cout << "Cat constructor" << endl; };
        ~Cat(){};

        void setName(string name) { this->name = name; };
        void speak() { cout << "Cat from animals namespace: " + this->name << endl; };
    };

    class Soriano: public Cat {
    public:
        Soriano() { cout << "Soriano constructor" << endl; };
        void speak() { cout << "Soriano from animals namespace: " + this->name << endl; };
    };

}

#endif //CLASSES_ANIMALS_H
