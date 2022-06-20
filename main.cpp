#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Station.h"
#include "Deque.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "Car.h"

using namespace std;
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif


int main(int argc, char * argv[])
{
    VS_MEM_CHECK               // enable memory leak check

    Deque<string> myDeque;
    Vector<string> myVector;
    Queue<string> myQueue;
    Stack<string> myStack;

//    myDeque.push_back("1");
//    cout << myDeque.toString() << endl;
//    myDeque.push_back("2");
//    cout << myDeque.toString() << endl;
//    myDeque.push_back("3");
//    cout << myDeque.toString() << endl;
//
//    myDeque.push_front("6");
//    cout << myDeque.toString() << endl;
//
//    myDeque.push_front("5");
//    myDeque.push_front("4");
//    cout << myDeque.toString() << endl;





    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    Station<Car> station;

    for (string line; getline(in, line);) {
        try {
            string commandLine, item2;
            if (line.size() == 0) continue;

            istringstream iss(line);
            iss >> commandLine;
            if (commandLine == "Add:station") {
                out << line << " ";
                iss >> item2;
                Car newCar;

                newCar.setID(stoi(item2));

                station.addCar(newCar);

                out << "OK";
                out << endl;
            }

            else if (commandLine == "Add:queue") {
                out << line << " ";
                iss >> item2;

                station.addQueue();

                out << "OK";
                out << endl;
            }

            else if (commandLine == "Add:stack") {
                out << line << " ";
                iss >> item2;

                station.addStack();

                out << "OK";
                out << endl;
            }

            else if (commandLine == "Remove:station") {
                out << line << " ";
                iss >> item2;

                station.removeCar();

                out << "OK";
                out << endl;
            }

            else if (commandLine == "Remove:queue") {
                out << line << " ";
                iss >> item2;

                station.removeQueue();

                out << "OK";
                out << endl;
            }

            else if (commandLine == "Remove:stack") {
                out << line << " ";
                iss >> item2;

                station.removeStack();

                out << "OK";
                out << endl;
            }

            else if (commandLine == "Top:station") {
                out << line ;
                out << station.topCar();
                out << endl;
            }

            else if (commandLine == "Top:queue") {
                out << line ;
                out << station.topQueue();
                out << endl;
            }
            else if (commandLine == "Top:stack") {
                out << line ;
                out << station.topStack();
                out << endl;
            }

            else if (commandLine == "Size:queue") {
                out << line << " ";
                out << station.sizeQueue();
                out << endl;
            }
            else if (commandLine == "Size:stack") {
                out << line << " ";
                out << station.sizeStack();
                out << endl;
            }
            else if (commandLine == "Size:train") {
                out << line << " ";
                out << station.sizeTrain();
                out << endl;
            }

            else if (commandLine == "Queue") {
                out << line ;
                out << station.QueuetoString();
                out << endl;
            }
            else if (commandLine == "Stack") {
                out << line ;
                out << station.StacktoString();
                out << endl;
            }
            else if (commandLine == "Train") {
                out << line ;
                out << station.TraintoString();
                out << endl;
            }
            else if (commandLine == "Find") {
                out << line ;
                iss >> item2;

                Car newCar;
                newCar.setID(stoi(item2));

                out << " " << station.find(newCar);

                out << endl;
            }
        }
        catch (string error) {
            out << error << endl;
        }
    }


    return 0;
}
