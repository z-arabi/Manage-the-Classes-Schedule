#ifndef Classroom_H
#define Classroom_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Classroom
{
    private:
    std::string name{};
    size_t seats{};  //  No of seats of the class
    std::shared_ptr<Classroom> left;  // A smart pointer to the class to the left of this class
    std::shared_ptr<Classroom> right;  // A smart pointer to the class to the right of this class
    double temperature{27};

    // variables I've added to the class
    std::vector<std::shared_ptr<Classroom>> seq{};
    size_t place{0};
    double guass_output{0.13};
    
    public:    
    Classroom(const char* name, size_t seats);
    ~Classroom();
    std::shared_ptr<Classroom> getRight();
    std::shared_ptr<Classroom> getLeft();
    void setRight(std::shared_ptr<Classroom> r);
    void setLeft(std::shared_ptr<Classroom> l);
    double getTemperature(bool random=true);
    size_t noOfSeats();
    void show() const;

    // function to get the seq which is private variable
    std::vector<std::shared_ptr<Classroom>> getSeq();
    void setSeats(size_t number);
    std::string getName();

    // no as public variable
    static int no;
    // it is neccassary if you declare no as private variable
    static int totalObjects();
  
};

#endif