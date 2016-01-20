#include <iostream>
#include <string>

#include "Example.h"
#include "ExampleB.h"
#include "hm.h"

using namespace std;

int main() {

    try
    {
        hmp<Example> p (new Example); // user-defined new
        p->set_values(3,5);
        std:cout << "example " << std::endl;
        hmp<Example> other = p;
        other = p;
        hmp<Example> other2= other;
        cout << other->area()<< endl;
        kill(other);
        kill(p);
        cout << p->area()<< endl;
        //hmp<ExampleB> pointb (new ExampleB(p));

    }
    catch (std::bad_alloc & x)
    {
        std::cout << x.what() << std::endl; // display exception
        return 11;
    }
    catch (std::invalid_argument &y) {
        std::cout << y.what() << std::endl; // display exception
        return 12;
    }
    return 0;
}