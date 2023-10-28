//
// Created by fsemerar on 10/24/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

struct Person {
    char name[50];
    int age;
    double weight;
};

class Test{
private:
    int *data;
    int len;
public:
    Test(int len): len(len){
        data = new int[len];
    };
    Test(int len, int *data): len(len){
        this->data = new int[len];
        for (int i = 0; i < len; i++){
            this->data[i] = data[i];
        }
    };
    Test (const Test &other): len(other.len){  // to avoid dangling pointer while copying object into multimap
        data = new int[len];
        for (int i = 0; i < len; i++){
            this->data[i] = other.data[i];
        }
    }
    // technically also need custom copy assignment operator for compliance with "rule of three"

    ~Test(){
        delete [] data;
    };

    const void print() const{
        for (int i = 0; i < this->len; i++) {
            cout << data[i] << endl;
        }
    }

    bool operator<(const Test &other) const{
        return this->data[0] < other.data[0];
    }
};

int main(){

//    Person p1 = {"Federico", 29, 70};
//
//    ofstream outputFile;
//    outputFile.open("test.bin", ios::binary);
//
//    if (outputFile.is_open()){
//        outputFile.write(reinterpret_cast<char *>(&p1), sizeof (p1));
//        outputFile.close();
//    } else{
//        cout << "could not write file" << endl;
//    }


//    vector<string> strings;
//    strings.push_back("1");
//    strings.push_back("2");
//    strings.push_back("3");
//    for(vector<string>::iterator it=strings.begin(); it!=strings.end(); it++){
//        cout << *it << endl;
//    }
//    vector<vector<string>> strings2(4, vector<string>(4, ""));


//    list<int> l = {1, 2, 3};
//    for(auto it = l.begin(); it != l.end(); it++){
//        if (*it == 3){
//            it = l.erase(it);
////            l.insert(it, 4);  // inserts just before 3
//        }
//    }
//    for(auto it = l.begin(); it != l.end(); it++){
//        cout << *it << endl;
//    }


//    map<int, Person> m = {{0, {"Fede", 29}},
//                          {5, {"Jen", 28}}};;
//    for(auto it = m.begin(); it != m.end(); it++){
//        cout << it->first << ": " << it->second.name << endl;
//    }


//    multimap<Test, int> mm;
//    int arr1[] = {1, 1, 1};
//    mm.insert(make_pair(Test(3, arr1), 1));
//    int arr2[] = {2, 2, 2};
//    mm.insert(make_pair(Test(3, arr2), 1));

    Test *pTest = new Test(10);
    pTest->print();

    return 0;
}
