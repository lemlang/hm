#include <iostream>
#include <string>

#include "Example.h"
#include "om.h"

using namespace std;

int main() {

    try
    {
        ObjectPtr<Example> p (new Example); // user-defined new
        cout << p->area()<< endl;
        kill(p);
        cout << p->area()<< endl;
        //ObjectPtr<Example> other = p;
        //ObjectPtr<Example> other2 (new Example);
        //other->makeChain(other2);
        //cout << other->area()<< endl;
        //kill(other);
        //kill(other2);
        //kill(p);

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