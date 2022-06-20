#ifndef INC_235LAB6_CAR_H
#define INC_235LAB6_CAR_H
#include <string>
#include <sstream>

using namespace std;

struct Car
{
    unsigned int id;
//    Car (unsigned int id) : CarId(id) {}
    Car() : id(0) {}
    ~Car() = default;

    bool operator==(const Car car) { return this->id == car.id; }
    bool operator!=(const Car car) { return this->id != car.id; }

    /** Return the Car as a string */
    string toString() const
    {
        stringstream out;
        out << " ";
        out << id;

        return out.str();
    }  //end toString()

    /** Make insertion operator friend for a Car */
    friend std::ostream& operator<< (ostream& os, const Car& c)
    {
        os << c.toString();
        return os;
    } // end operator<<
    void setID(int iD){
        id = iD;
    }
};
#endif //INC_235LAB6_CAR_H
