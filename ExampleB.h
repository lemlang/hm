//
// Created by amz on 19.01.16.
//

#ifndef CPP_HM_EXAMPLEB_H
#define CPP_HM_EXAMPLEB_H

#include "Example.h"
#include "hm.h"

class ExampleB {
    hmp<Example> point;
public:
    void* setPoint(hmp<Example> point);

    ExampleB(hmp<Example> point) : point(point) { }
};


#endif //CPP_HM_EXAMPLEB_H
