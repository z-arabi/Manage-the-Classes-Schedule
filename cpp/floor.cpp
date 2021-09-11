#include "floor.h"
#include <bits/stdc++.h>
#include <cstdarg> 

Floor::Floor(const char* name, std::shared_ptr<Classroom> pc):name{name},pc{pc}
{
    std::cout << "Constructing..." << std::endl;
    index = findInd(pc->getSeq(),0);
    // std::cout<< index << std::endl;
}

Floor::Floor(const char* name, size_t no_of_classes , ...)
{
    std::cout << "Constructing..." << std::endl;
    this->name = name;
    this->no_of_classes = no_of_classes;

    va_list valist;
    
    va_start(valist,no_of_classes);
    for(size_t i{0} ; i< no_of_classes ; i++)
    {
        if (i==0)
        {
            pc = va_arg(valist,std::shared_ptr<Classroom>);
            // std::cout << pc->noOfSeats() << " " << no_of_classes  << std::endl;
            // std::cout << typeid(va_arg(valist,std::shared_ptr<Classroom>)).name() << std::endl;
            // std::cout << i << std::endl;
        }
        else
        {
            //  std::cout << va_arg(valist, std::shared_ptr<Classroom>)->noOfSeats() << std::endl;
            pc->setRight(va_arg(valist, std::shared_ptr<Classroom>));
            // std::cout << i << std::endl;

        } 
    }
    va_end(valist);    

    index=0;
}

Floor::~Floor()
{
    std::cout << "Destructing..." << std::endl;
}

int Floor::findInd(std::vector<std::shared_ptr<Classroom>> seq , std::shared_ptr<Classroom> target)
{
     std::vector<std::shared_ptr<Classroom>>::iterator it = std::find(seq.begin(), seq.end(), target); 
  
    // If element was found 
    if (it != seq.end()) 
    { 
        // calculating the index 
        int index = distance(seq.begin(), it); 
        return index;
    } 
    else 
    { 
        // If the element is not present in the vector 
        return -1;
    } 
}

size_t Floor::noOfClasses()
{
    return pc->getSeq().size();
}

void Floor::show() const
{
    std::cout << "Floor:  " << name << "\n"
              << "        Average Temperature: " << const_cast<Floor *>(this)->getTemperature() << "\n"
              << "        No of Seats: " << const_cast<Floor *>(this)->noOfSeats() << "\n"
              << "        No of Classes: " << const_cast<Floor *>(this)->noOfClasses() << std::endl;
    
    for (int i{0} ; i<static_cast<int>(pc->getSeq().size()) ; i++)
    {
        if (i==index)
            std::cout<< "        Class: " << pc->getName() << ",  Seats: " << pc->noOfSeats() 
                     << ",  Temperature: " << pc->getTemperature(0) << std::endl;
        else
            std::cout<< "        Class: " << pc->getSeq()[i]->getName() 
                     << ",  Seats: " << pc->getSeq()[i]->noOfSeats() 
                     << ",  Temperature: " << pc->getSeq()[i]->getTemperature(0) << std::endl;
        

    }  

}

std::shared_ptr<Classroom> Floor::operator[](int i)
{
    int mod{0};

    if (i<0)
        i = i % static_cast<int>(pc->getSeq().size()) + pc->getSeq().size();

    mod = (index+i) % pc->getSeq().size();

    std::cout << "mod,operator " << mod << " " << i << std::endl;
    if (mod==index)
        return pc;
    else
        return pc->getSeq()[mod];
}

bool Floor::moveSeats(int source, int dest, size_t no)
{
    size_t seat;

    if (source==index)
        seat = pc->noOfSeats();
    else
        seat = pc->getSeq()[source]->noOfSeats();
    
    std::cout << "inside seat " << seat << std::endl;

    if (seat >= no)
    {
        if (source==index)
            pc->setSeats(seat-no);
        else
            pc->getSeq()[source]->setSeats(seat-no);
        
        if (dest==index)
            pc->setSeats(seat+no);
        else
            pc->getSeq()[source]->setSeats(seat+no);

        return true;

    }
    else
    {
        return false;
    }
    

}

size_t Floor::noOfSeats()
{
    int sum{0};
    for(int i{0} ; i < static_cast<int>(pc->getSeq().size()) ; i++)
    {
        if (i==index)
            sum += pc->noOfSeats();
        else
            sum += pc->getSeq()[i]->noOfSeats();
    }

    return sum;    
}

size_t Floor::noOfSeats(int i)
{
    int mod = (index+i) % pc->getSeq().size();
    std::cout << "mod " << mod << std::endl;
    if (mod==index)
        return pc->noOfSeats();
    else
        return pc->getSeq()[mod]->noOfSeats();
}

double Floor::getTemperature()
{
    double temp;

    for(int i{0} ; i < static_cast<int>(pc->getSeq().size()) ; i++)
    {
        if (i==index)
            temp += pc->getTemperature(false);
        else
            temp += pc->getSeq()[i]->getTemperature(false);
    }

    return round(temp/pc->getSeq().size()*100.0)/100.0 ;

}

void Floor::setPointer(std::shared_ptr<Classroom> a)
{
    pc = a;
}