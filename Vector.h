#ifndef INC_235LAB6_VECTOR_H
#define INC_235LAB6_VECTOR_H
#include "Deque.h"

template<typename T>
class Vector{
private:
    Deque<T> deque;
public:

    Vector() = default;
    ~Vector() = default;

    void push(const T data){
        deque.push_back(data);
    }
    void pop(){
        if (deque.size() == 0){
            throw string ("Empty");
        }
        else { deque.pop_back(); }
    }
    T& top(){
        if (deque.size() == 0){
            throw string ("Empty");
        }
        else { return deque.back(); }
    }

    size_t size(){
        return deque.size();
    }

    T& at(size_t index){
        return deque.at(index);
    }

    string toString() const{
        return deque.toString();
    }

};
#endif //INC_235LAB6_VECTOR_H
