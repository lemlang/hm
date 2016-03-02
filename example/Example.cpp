//
// Created by amz on 21.11.15.
//

#include "Example.h"



void* Example::set_values(int i, int i1) {
    this->height = i;
    this->width = i1;
    return this;
}

void* Example::makeChain(ObjectPtr<Example> *point) {
    //this->point = point;
}


int Example::area() {
    return this->height*this->width;
}

