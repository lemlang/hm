//
// Created by amz on 21.11.15.
//
#include <exception> // for std::bad_alloc
#include <new>
#include <cstdlib> // for malloc() and free()
#include <iostream>
#include <typeinfo>

#include "om.h"

ObjectManagement *ObjectManagement::system_instance = NULL;
ObjectManagement::ObjectManagement() {
    M = (int*)calloc (MAXMEMSIZE + 1, sizeof(memblock)); /* allocate main memory array */
    std::cout << "M calloc"<< std::endl;
}


ObjectManagement *ObjectManagement::instance() {
    if(!ObjectManagement::system_instance) {
        ObjectManagement::system_instance = new ObjectManagement;
    }
    return ObjectManagement::system_instance;
}

memblock*ObjectManagement::allocate() {

    return (memblock*) &M[++next];
}


void * operator new(std::size_t n) throw(std::bad_alloc)
{
    std::cout << "new " << n << std::endl;
    return malloc(n);
}
void operator delete(void * p, std::size_t sz ) throw()
{
    std::cout << "delete " << sz << " " << typeid(p).name() << " " << p << std::endl;
    free(p);
}
void operator delete(void * p) throw()
{
    std::cout << "delete " << typeid(p).name() << " " << p << std::endl;
    free(p);
}

void ObjectManagement::inject(ObjectPtr<Object> source, Object* target) {
    target->self  = source;
}
