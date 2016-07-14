//
// Created by amz on 19.01.16.
//

#ifndef CPP_HM_EXAMPLEB_H
#define CPP_HM_EXAMPLEB_H

#include "Example.h"
#include "om.h"

class ExampleB: public Object {
    ObjectPtr<Example> point;
public:
    void* setPoint(ObjectPtr<Example> point);

    ExampleB(ObjectPtr<Example> point) : point(point) { }
};


#endif //CPP_HM_EXAMPLEB_H
