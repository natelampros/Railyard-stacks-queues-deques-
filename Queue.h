#ifndef INC_235LAB6_QUEUE_H
#define INC_235LAB6_QUEUE_H
#include "Deque.h"

template<typename T>
class Queue{
private:
    Deque<T> deque;
public:
    Queue() = default;
    ~Queue() = default;

    void push(T data){
        deque.push_back(data);
    }
    void pop(){
        if (deque.size() == 0){
            throw string ("Queue empty!");
        }
        else { deque.pop_front(); }
    }
    T& top(){
        if (deque.size() == 0){
            throw string ("Queue empty!");
        }
        else { return deque.front(); }
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
#endif //INC_235LAB6_QUEUE_H
