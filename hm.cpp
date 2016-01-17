//
// Created by amz on 21.11.15.
//
#include <exception> // for std::bad_alloc
#include <new>
#include <cstdlib> // for malloc() and free()
#include <iostream>

#include "hm.h"

hms*  hms::hms_instance = NULL;
hms::hms() {
    M = (int*)calloc (MAXMEMSIZE + 1, sizeof(memblock)); /* allocate main memory array */
    std::cout << "M calloc"<< std::endl;
}


hms* hms::instance() {
    if(!hms::hms_instance) {
        hms::hms_instance = new hms;
    }
    return hms::hms_instance;
}

memblock* hms::allocate() {

    return (memblock*) &M[++next];
}
