#ifndef INC_235LAB6_STACK_H
#define INC_235LAB6_STACK_H
#include "Deque.h"

template<typename T>
class Stack{
private:
    Deque<T> deque;
public:
    Stack() = default;
    ~Stack() = default;

    void push(T data){
        deque.push_back(data);
    }
    void pop(){
        if (deque.size() == 0){
            throw string ("Stack empty!");
        }
        else { deque.pop_back(); }
    }
    T& top(){
        if (deque.size() == 0){
            throw string ("Stack empty!");
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

#endif //INC_235LAB6_STACK_H
