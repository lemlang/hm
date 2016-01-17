//
// Created by amz on 21.11.15.
//

#include "Example.h"



Example* Example::set_values(int i, int i1) {
    this->height = i;
    this->width = i1;
    return this;
}

int Example::area() {
    return this->height*this->width;
}

