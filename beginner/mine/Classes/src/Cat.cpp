//
// Created by fsemerar on 10/24/23.
//

#include <iostream>
#include <sstream>
#include "Cat.h"

using namespace std;

namespace cats {

    Cat::Cat(): happy(true), name("") {
        cout << "cat created" << endl;
    }

    Cat::~Cat() {
        cout << "cat destroyed" << endl;
    }

    void Cat::jump() const{  // const means no instance vars of the class are changed

        if (happy){
            cout << "happy!" << endl;
        } else{
            cout << "not happy!" << endl;
        }
    }

    string Cat::toString(){
        stringstream ss;

        ss << "Memory location: ";
        ss << this;

        return ss.str();
    }

}
