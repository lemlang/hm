//
// Created by amz on 21.11.15.
//

#ifndef CPP_HM_EXAMPLE_H
#define CPP_HM_EXAMPLE_H
#include <iostream>
#include <memory>


class Example {
    int width, height;
public:
    int wtf = 11;
    void* set_values (int,int);
    int area ();
};


#endif //CPP_HM_EXAMPLE_H
