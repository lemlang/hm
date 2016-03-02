//
// Created by amz on 21.11.15.
//

#ifndef CPP_HM_HM_H
#define CPP_HM_HM_H

#include <cstdlib>


#define MAXMEMSIZE 0x400000L


typedef struct {
    void* pointer;
    int generation;
} memblock;


class ObjectManagement {
    static ObjectManagement *system_instance;
    int* M;
    int next = 0;
    ObjectManagement();
public:
    static ObjectManagement * instance();
    memblock* allocate();
};


template < typename T > class ObjectPtr {
private:
    memblock* intermediate;
    int generation;

public:
    ObjectPtr(T* candidate) {
        this->intermediate = ObjectManagement::instance()->allocate();
        this->intermediate->pointer = candidate;
        this->intermediate->generation++;
        this->generation = this->intermediate->generation;
        std::cout << "constructor "<< (long)this->intermediate << std::endl;
        std::cout<< std::endl;
    }
    ObjectPtr(const ObjectPtr<T>& p) : intermediate(p.intermediate) {
        this->generation = p.generation;
        std::cout << "copy constructor"<< std::endl;
    }
    ~ObjectPtr() {
        std::cout << "destructor called on smart pointer"<< std::endl;
    }
    T&  operator*() {
        std::cout << "memebr override *"<< std::endl;
        if( this->intermediate->pointer != NULL && this->intermediate->generation == this->generation) {
            return (T&) (this->intermediate->pointer);
        } else {
            throw std::invalid_argument("p is NULL");
        }
    }
    T* operator->()  {
        if( this->intermediate->pointer != NULL && this->intermediate->generation == this->generation) {
        std::cout << "memeber override -> "<< this->intermediate->pointer<< std::endl;
            return (T*) (this->intermediate->pointer);
        } else {
            throw std::bad_alloc();
        }
    }
    ObjectPtr<T>& operator = (const ObjectPtr<T>& p) {
        std::cout << "Assignment operator"<< std::endl;
        if (this != &p) // Avoid self assignment
        {

            // Copy the data and reference pointer
            // and increment the reference count
            this->intermediate = p.intermediate;
            this->generation = p.generation;
        }
        return *this;
    }
    T& operator()(){
        std::cout << "function operator override " << std::endl;
        return (T&)this;
    }

    friend void kill(ObjectPtr<T> anypointer){
       if( anypointer.intermediate->pointer != NULL && anypointer.intermediate->generation == anypointer.generation) {
            std::cout << "killem! "<< anypointer.intermediate->pointer << std::endl;
            anypointer.intermediate->generation++;
           ((T*)(anypointer.intermediate->pointer))->~T();
           std::free(anypointer.intermediate->pointer);
            //delete ((T*)(anypointer.intermediate->pointer));
        } else {
            std::cout << "cannot kill: already dead!" << std::endl;
        }
    }
};

template<class T> class Object {

public:
    Object() : self(NULL) {
        std::cout << " Object constructor " << std::endl;
    }

private:
    ObjectPtr<T> self;
};



#endif //CPP_HM_HM_H
