//
// Created by fsemerar on 10/24/23.
//

#include <iostream>
#include "Cat.h"
#include "Animals.h"

using namespace std;
using namespace animals;  // useful if different libraries have classes with the same name
using namespace cats;

void manipulate_pointer(double* pValue){
    cout << *pValue << endl;
    *pValue = 10.;
}

void manipulate_reference(double& value){
    cout << value << endl;
    value = 10.;
}

cats::Cat *createCat(string name){
    cats::Cat *pCat = new cats::Cat();  // new allocates on the heap
    pCat->setName(name);
    return pCat;
}

void show1(const int size, string texts[]){  // same as doing  string *texts
    cout << sizeof(texts) << endl;  // size of pointer!
    for (int i=0; i < size; i++){
        cout << texts[i] << endl;
    }
}
// (in general better to use std::vector or std::array, which encapsulate size information)
void show2(string (&texts)[3]){  // enforces the size of texts at compile time
    cout << sizeof(texts) << endl;  // size of array!
    for (int i=0; i < sizeof(texts)/sizeof(texts[0]); i++){
        cout << texts[i] << endl;
    }
}

int main(){

    // Object oriented programming
//    cats::Cat cat1(false, "Bob");
//    cat1.jump();
//    cout << cat1.toString() << endl;

    // Pointers
//    double value = 8.;
//    double* p_value = &value;
//    cout << *p_value << endl;
//    manipulate_pointer(&value);
//    cout << value << endl;
//    cout << *p_value << endl;

    // pointers in arrays
    // string a[] = {"one", "two", "three"};
    // for (int i = 0; i < sizeof(a) / sizeof(string); i++){
    //     cout << a[i] << " " << flush;
    // }
    // cout << endl;
    // string *p_a = a;
    // for (int i = 0; i < sizeof(a) / sizeof(string); i++, p_a++){
    //     cout << *p_a << " " << flush;
    // }
    // cout << endl;
    // string *p_a2 = &a[0];
    // string *p_a3 = &a[sizeof(a) / sizeof(string) - 1];
    // while(true){
    //     cout << *p_a2 << " " << flush;
    //     if (p_a2 == p_a3){
    //         break;
    //     }
    //     p_a2++;
    // }
    // cout << endl;

    // pointer arithmetic
//    const int NSTRINGS = 5;
//    string s[NSTRINGS] = {"1", "2", "3", "4", "5"};
//    string *pEnd = &s[NSTRINGS];
//    string *pCurrent = s;
//    while(pCurrent != pEnd){
//        cout << *pCurrent << endl;
//        pCurrent++;
//    }

    // reverse char array
//    char text[] = "ciao";
//    int len = sizeof(text) - 1;
//    char out[len + 1];

//    char *pText = &text[0];
//    char *pOut = &out[len - 1];
//    while(*pText != 0){  // null terminator is a character with a value of 0
//        *pOut = *pText;
//        pText++;
//        pOut--;
//    }
//    out[len] = text[len];  // null terminator
//    cout << out << endl;

    // references (basically an alias, simpler than pointers but less powerful)
//    double value = 9.;
//    double &value2 = value;
//    manipulate_reference(value);
//    const int value1 = 10;
//    const int *pValue1 = &value1;
//    int value3 = 11;
// //    pValue1 = &value2;
//    value2 = 12;  // but cannot do *pValue1 = 12;
//    cout << *pValue1 << endl;
//    const int * const pValue2 = &value1;  // cannot reassign the pointer

    // copy constructor
//    cats::Cat cat2;
//    cat2.setName("miaola");
//    cat2.speak();
//    cats::Cat cat3 = cat2;
//    cat3.speak();
//    cats::Cat cat4(cat2);
//    cat4.speak();

    // new operator
//    cats::Cat *pCat5 = new cats::Cat(true, "baffo");
//    pCat5->speak();
//    cout << sizeof(pCat5) << endl;
//    delete pCat5;  // calls destructor
//    cats::Cat *pCat = createCat("misha");
//    (*pCat).speak();  // a reference would go out of scope if declared within the function
//    delete pCat;  // but with new I need to explicitly deallocate memory by calling delete

    // allocating memory
//    cats::Cat *pCat6 = new cats::Cat[10];  // dynamically allocating array of 10, pCat6 is a pointer to the first Cat object
//    pCat6[5].setName("test");
//    pCat6[5].speak();  // by indexing into array (even if via a pointer), we reference an actual object instance (so no ->)
//    delete [] pCat6;
//    int *pMem = new int[12];
//    pMem[10] = 999;
//    cout << pMem[9] << " " << pMem[10] << endl;
//    delete [] pMem;

    // arrays and functions
//    string a[] = {"one", "two", "three"};
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++){
//        cout << to_string(i) + ": " + a[i] << endl;
//    }
//    show1(sizeof(a) / sizeof(a[0]), a);
//    show2(a);

    // namespaces
//    animals::Cat cat10(true, "fede");
//    cat10.speak();

    // inheritance: NB constructors are not inherited, so cannot run eg animals::Soriano cat11(true, "Jen");
    // animals::Soriano cat11;
    // cat11.setName("Jen");
    // cat11.speak();

    // static keyword for an instance var or function
    // virtual keyword for a class function

    // different from python
    // cout << -16 % 7 << endl;

    return 0;
}
