#include <iostream>
#include <string>

#include "Example.h"
#include "ExampleB.h"
#include "om.h"

using namespace std;

int main() {

    try
    {
        ObjectPtr<Example> p (new Example); // user-defined new
        p->set_values(3,5);
        std:cout << "example " << std::endl;
        ObjectPtr<Example> other = p;
        other = p;
        ObjectPtr<Example> other2= other;
        cout <<"area "<< other->area()<< endl;
        kill(other);
        kill(other2);
        kill(p);
        cout <<"area "<< p->area()<< endl;
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