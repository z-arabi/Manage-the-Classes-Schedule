#ifndef Floor_H
#define Floor_H

#include <iostream>
#include <memory>
#include "classroom.h"

class Floor
{
    private:
    size_t no_of_classes{0};
    std::string name;
    std::shared_ptr<Classroom> pc;  // pointer to one of the classes in the floor

    int findInd(std::vector<std::shared_ptr<Classroom>> seq , std::shared_ptr<Classroom> target);
    int index{0};
    
    public:
    Floor(const char* name, std::shared_ptr<Classroom> pc);
    Floor(const char* name, size_t no_of_classes , ...);
    ~Floor();
    size_t noOfClasses();
    void show() const;
    std::shared_ptr<Classroom> operator[](int i);
    bool moveSeats(int source, int dest, size_t no);  // source and dest are indices of classrooms
    size_t noOfSeats(int i);  // No of seats of the i-th class starting from pc
    size_t noOfSeats();  // No of seats of the whole floor
    double getTemperature();  // Average of temperature of all the classes
    void setPointer(std::shared_ptr<Classroom> a); // Sets the pc to another class in the floor
};

#endif