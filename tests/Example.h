//
// Created by amz on 21.11.15.
//

#ifndef CPP_HM_EXAMPLE_H
#define CPP_HM_EXAMPLE_H
#include <iostream>
#include <memory>
#include "om.h"

class Example: public Object {
    int width, height;
public:
    int wtf = 11;
    void* set_values (int,int);
    void* makeChain(ObjectPtr<Example> pointer);
    int area ();
private:
    ObjectPtr<Example> point(nullptr_t);
};


#endif //CPP_HM_EXAMPLE_H
