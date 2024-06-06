//
// Created by fsemerar on 10/24/23.
//

#ifndef ADVANCED_CPLUSPLUS_CAT_H
#define ADVANCED_CPLUSPLUS_CAT_H

using namespace std;

namespace cats {

    class Cat {
    private:
        bool happy;
        string name;

    public:
        void jump() const;

        Cat();

        Cat(bool happy, string name) {
            this->happy = happy;
            this->name = name;
        };

        Cat(const Cat &other) : happy(other.happy), name(other.name) { 
            cout << "Cat created by copying" << endl; 
        };

        ~Cat();

        string toString();

        void setName(string name) { this->name = name; };

        void speak() { cout << this->name << endl; };
    };
}

#endif //ADVANCED_CPLUSPLUS_CAT_H
