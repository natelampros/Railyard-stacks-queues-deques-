#ifndef INC_235LAB6_DEQUE_H
#define INC_235LAB6_DEQUE_H
#include "DequeInterface.h"
//#include "Car.h"
#include <string>
#include <sstream>

using namespace std;

template<typename T>
class Deque : public DequeInterface<T> {
private:

    size_t capacity = DEFAULT_CAPACITY;
    size_t num_items = 0;
    size_t front_index = 0;
    size_t rear_index = DEFAULT_CAPACITY - 1;
    T* the_data;



public:

    Deque(void) : capacity(DEFAULT_CAPACITY), num_items(0), front_index(0), rear_index(DEFAULT_CAPACITY - 1), the_data(new T[DEFAULT_CAPACITY]){}
    virtual ~Deque(void) { delete[] the_data;};

    void reallocate(){
        size_t new_capacity = 2 * capacity;
        T* new_data = new T[new_capacity];
        size_t old = front_index;

        for (size_t i = 0; i < num_items; ++i)
        {
            new_data[i] = the_data[old];
            old = (old + 1) % capacity;
        }

        front_index = 0;
        rear_index = num_items - 1;
        capacity = new_capacity;

        delete[] the_data;
        the_data = new T[capacity];
        for (size_t i = 0; i < num_items; ++i){
            the_data[i] = new_data[i];
        }
        //swap(the_data, new_data);
        delete[] new_data;
    }

    /** Insert item at front of deque */
    virtual void push_front(const T& value) {
        if(num_items == capacity){ reallocate(); }
        ++num_items;
        front_index = (front_index - 1) % capacity;
        the_data[front_index] = value;
    }

    /** Insert item at rear of deque */
    virtual void push_back(const T& value) {
        if(num_items == capacity){ reallocate(); }
        ++num_items;
        rear_index = (rear_index + 1) % capacity;
        the_data[rear_index] = value;
    }

    /** Remove the front item of the deque */
    virtual void pop_front(void) {
        num_items--;
        front_index = (front_index + 1) % capacity;
    }

    /** Remove the rear item of the deque */
    virtual void pop_back(void) {
        num_items--;
        rear_index = (rear_index - 1) % capacity;
    }

    /** Return the front item of the deque (Do not remove) */
    virtual T& front(void) {
        return the_data[front_index];
    }

    /** Return the rear item of the deque (Do not remove) */
    virtual T& back(void) {
        return the_data[rear_index];
    }

    /** Return the number of items in the deque */
    virtual size_t size(void) const {
        return num_items;
    }

    /** Return true if deque is empty */
    virtual bool empty(void) const {
        if (num_items == 0){
            return true;
        }
        return false;
    }

    /** Return item in deque at index (0 based) */
    virtual T& at(size_t index) {
        return the_data[index];
    }

    /** Return the deque items */
    virtual std::string toString(void) const {
        stringstream out;
        for (int i = front_index; i <= rear_index; ++i){
            out << the_data[i];
        }
        return out.str();
//        size_t tempIndex = front_index;
//        string deque = "";
//        for (int i = 0; i < size(); ++i){
//            deque = deque + " " + the_data[tempIndex];
//            tempIndex = (tempIndex + 1) % capacity;
//        }
//        return deque;
    }
};


#endif //INC_235LAB6_DEQUE_H
