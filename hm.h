//
// Created by amz on 21.11.15.
//

#ifndef CPP_HM_HM_H
#define CPP_HM_HM_H


#define MAXMEMSIZE 0x400000L


typedef struct {
    void* pointer;
    int generation;
} memblock;


class hms {
    static hms *hms_instance;
    int* M;
    int next = 0;
    hms();
public:
    static hms* instance();
    memblock* allocate();
};


template < typename T > class hmp {
private:
    memblock* intermediate;
    int generation;

public:
    hmp(T* candidate) {
        this->intermediate = hms::instance()->allocate();
        this->intermediate->pointer = candidate;
        this->intermediate->generation++;
        this->generation = this->intermediate->generation;
        std::cout << "constructor "<< (long)this->intermediate << std::endl;
        std::cout<< std::endl;
    }
    hmp(const hmp<T>& p) : intermediate(p.intermediate) {
        this->generation = p.generation;
        std::cout << "copy constructor"<< std::endl;
    }
    ~hmp() {
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
    hmp<T>& operator = (const hmp<T>& p) {
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

    friend void kill(hmp<T> anypointer){
       if( anypointer.intermediate->pointer != NULL && anypointer.intermediate->generation == anypointer.generation) {
            std::cout << "killem! "<< anypointer.intermediate->pointer << std::endl;
            anypointer.intermediate->generation++;
           ((T*)(anypointer.intermediate->pointer))->~T();
           free(anypointer.intermediate->pointer);
            //delete ((T*)(anypointer.intermediate->pointer));
        } else {
            std::cout << "cannot kill: already dead!" << std::endl;
        }
    }
};





#endif //CPP_HM_HM_H
