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


template<class T>
class Ring {
private:
    T *data;
    int len;
    int pos;

public:
    class iterator;

public:
    Ring(int len){
        this->len = len;
        this->pos = 0;
        data = new T[len];
    }

    ~Ring(){
        delete [] data;
    }

    void add(T value){
        data[pos++] = value;
        if (len == pos){
            pos = 0;
        }
    }

    T &get(int i){
        return data[i];
    }

    int size() const{
        return this->len;
    }

    iterator begin(){
        return iterator(0, this);
    }
    iterator end(){
        return iterator(len, this);
    }
};


template<class T>
class Ring<T>::iterator{
private:
    int pos;
    Ring *ring;
public:
    iterator(int pos, Ring *ring): pos(pos), ring(ring){}

    iterator operator++(int){ // postfix
        iterator old = *this;
        ++(*this);
        return old;
    }
    iterator operator++(){ // prefix
        ++pos;
        return *this;
    }
    bool operator==(const iterator &other) const{
        return this->pos == other.pos;
    }
    bool operator!=(const iterator &other) const{
        return !(*this == other);
    }
    T& operator*() {
        return ring->get(pos);
    }
};


int main(){

//    Person p1 = {"Federico", 29, 70};

//    ofstream outputFile;
//    outputFile.open("test.bin", ios::binary);

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


//    list<int> l = {1, 2, 3, 5};
//    for(auto it = l.begin(); it != l.end(); it++){
//        if (*it == 3){
//            it = l.erase(it);
// //            l.insert(it, 4);  // inserts just before 3
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


//    multimap<Test, int> mm;  // allows multiple entries to have the same key
//    int arr1[] = {1, 1, 1};
//    mm.insert(make_pair(Test(3, arr1), 1));
//    int arr2[] = {2, 2, 2};
//    mm.insert(make_pair(Test(3, arr2), 1));

//     std::multimap<int, std::string> userMultimap;
//     userMultimap.insert({1, "Alice"});
//     userMultimap.insert({2, "Bob"});
//     userMultimap.insert({1, "Carol"}); // Adds another entry for key 1
//     auto range = userMultimap.equal_range(1);
//     for (auto it = range.first; it != range.second; ++it) {
//         std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
//     }


//    Test *pTest = new Test(10);
//    pTest->print();


//    Ring<string> textring(3);
//    textring.add("one");
//    textring.add("two");
//    textring.add("three");
//    textring.add("four");
//    for (int i = 0; i < textring.size(); i++) {
//        cout << textring.get(i) << endl;
//    }
//    for (Ring<string>::iterator it = textring.begin(); it != textring.end(); it++){
//        cout << *it << " " << flush;
//    }
//    cout << endl;
//    for (auto &text: textring){
//        cout << text << " " << flush;
//    }


//    struct {
//        string text;
//        int id;
//    } r1 = { "Hello", 7 }, r2 = { "Hi", 9 };


    int a = 10;
    int b = 11;
    function<int(int, int)> add = [&](int m, int n){ return a + b + m + n; };
    cout << add(3, 4) << endl;

    return 0;
}
