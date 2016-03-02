#include <iostream>
#include <string>

#include "Example.h"
#include "om.h"

using namespace std;

int main() {

    try
    {
        ObjectPtr<Example> p (new Example); // user-defined new
        ObjectPtr<Example> other = p;
        cout << other->area()<< endl;
        kill(other);
        kill(p);
        cout << p->area()<< endl;

    }
    catch (std::bad_alloc & x)
    {
        std::cout << x.what() << std::endl; // display exception
        return 0;
    }
    catch (std::invalid_argument &y) {
        std::cout << y.what() << std::endl; // display exception
        return 12;
    }
    return 1;
}