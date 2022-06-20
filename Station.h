#ifndef INC_235LAB6_STATION_H
#define INC_235LAB6_STATION_H
#include "Vector.h"
#include "Queue.h"
#include "Stack.h"
#include "Car.h"

template<typename T>
class Station: public Deque<T> {
private:
    Vector<T> train;
    Queue<T> queue;
    Stack<T> stack;
    T turnTableCar;
    bool empty = true;

public:
    Station() = default;
    ~Station() = default;

    string addCar(const T& car) { //Add:station
        if (empty){
            turnTableCar = car;
            empty = false;
            return "OK";
        }
        else { throw string ("Turntable occupied!"); }

    }

    string removeCar() { //Remove:station
        if (empty) {throw string ("Turntable empty!");}
        else {
            train.push(turnTableCar);
            empty = true;
            return "OK";
        }
    }


    string topCar() { //Top:station
        if (empty) {throw string ("Turntable empty!");}
        else {
            stringstream out;
            out << turnTableCar;
            return out.str();
        }
    }

    size_t sizeTrain() {  //train can it be size_t type
        return train.size();
    }

    //TODO toString for train -> TRAIN

    string addQueue() { //Add:queue
        if (empty) {throw string ("Turntable empty!");}
        else {
            queue.push(turnTableCar);
            empty = true;
            return "OK";
        }
    }

    string removeQueue() { //Remove:queue
        if (empty){
            turnTableCar = queue.top();
            empty = false;
            queue.pop();
            return "OK";
        }
        else { throw string ("Turntable occupied!"); }
    }

    string topQueue() {
        stringstream out;
        out << queue.top();
        return out.str();
    }

    size_t sizeQueue() {
        return queue.size();
    }


    string addStack() { //Add:stack
        if (empty) {throw string ("Turntable empty!");}
        else {
            stack.push(turnTableCar);
            empty = true;
            return "OK";
        }
    }

    string removeStack() { //Remove:stack
        if (empty){
            turnTableCar = stack.top();
            empty = false;
            stack.pop();
            return "OK";
        }
        else { throw string ("Turntable occupied!"); }
    }

    string topStack() {
        stringstream out;
        out << stack.top();
        return out.str();

    }


    size_t sizeStack() {
        return stack.size();
    }

    string find(T car) {
        bool found = false;
        string index;
        stringstream iss;

        if ((car == turnTableCar) && (!empty)){
            throw string ("Turntable");
            found = true;
        }

        else if (queue.size() > 0){
            for (int i = 0; i < queue.size(); ++i){
                if (queue.at(i) == car){
                    found = true;
                    index = "Queue[" + to_string(i) + "]";
                    return index;
                }
            }
        }

        if (stack.size() > 0){
            for (int i = 0; i < stack.size(); ++i){
                if (stack.at(i) == car){
                    found = true;
                    index = "Stack[" + to_string(i) + "]";
                    return index;
                }
            }
        }

        if (train.size() > 0){
            for (int i = 0; i < train.size(); ++i){
                if (train.at(i) == car){
                    found = true;
                    index = "Train[" + to_string(i) + "]";
                    return index;
                }
            }
        }

        throw string ("Not Found!");

    }

    const string TraintoString() {
        if (train.size() == 0){
            return "";
        }
        else { return train.toString(); }
    }

    const string QueuetoString() {
        if (queue.size() == 0){
            return "";
        }
        else { return queue.toString(); }
    }

    const string StacktoString() {
        if (stack.size() == 0){
            return "";
        }
        else { return stack.toString(); }
    }


};
#endif //INC_235LAB6_STATION_H
