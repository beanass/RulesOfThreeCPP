#include <iostream>
#include "stdio.h"

class Test {
public:
    int x;
    char* text;
    Test(int _x, char* _text) : x(_x)/*, text(_text)*/{
        text = copyString(_text);
    };
    Test(const Test& rhs) : x(rhs.x) {
        text = copyString(rhs.text);
    };

    Test& operator=(const Test& rhs) {
        x = rhs.x;
        delete[] text; // Speicher Lack zu vermeinden
        text = copyString(rhs.text);
        return *this;
    };
    // deconstructor gibt den speicher frei
    ~Test() {
        delete[] text;
    };

    //Die Funktion erstellt eine Kopie des übergebenen char-Array
    char* copyString(const char* src){
        char* copy = new char[strlen(src) + 1];
        strcpy(copy, src);
        return copy;
    };
};
int main() {
    Test t1(1, "Hello"); // Constructor
    Test t2(t1); // Copy-Constructor
    Test t3(3, "World");
    t1 = t3; // Copy-Assignment
    printf("t1: x = %d - text = %s\n", t1.x, t1.text);
    printf("t2: x = %d - text = %s\n", t2.x, t2.text);
    printf("t3: x = %d - text = %s\n", t3.x, t3.text);
    Test* t4 = new Test(4, "World");
    delete t4;
}