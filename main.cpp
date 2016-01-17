#include <iostream>
#include <string>

#include "Example.h"
#include "hm.h"

using namespace std;

int main() {
    string text("hello");

    try
    {
        hmp<Example> p(new Example); // user-defined new
        p->set_values(3,5);
        std:cout << "example " << std::endl;
        hmp<Example> other = p;
        other = p;
        hmp<Example> other2(other);
        cout << p->area()<< endl;

    }
    catch (std::bad_alloc & x)
    {
        std::cerr << x.what() << std::endl; // display exception
        return 11;
    }
    return 0;
}