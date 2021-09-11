#include "classroom.h"
#include <vector>
#include <memory>
#include <typeinfo>
#include <cmath>
#include <bits/stdc++.h> 

int Classroom::no = 0;

Classroom::Classroom(const char* name, size_t seats): name{name},seats{seats}
{
    // std::cout << "Constructing " << this << " " << typeid(this).name() << " " << &seq << std::endl;
    std::cout << "Constructing..." << std::endl;
    place=0;
    seq.push_back(0);
    no++;
}

Classroom::~Classroom()
{
    std::cout << "Destructing..." << std::endl;
    seq.clear();
}

void Classroom::setRight(std::shared_ptr<Classroom> r)
{
    this->seq.push_back(r);
}

void Classroom::setLeft(std::shared_ptr<Classroom> l)
{
    seq.insert(seq.begin(), l);
    place++;
}

std::shared_ptr<Classroom> Classroom::getRight()
{
    return seq[place+1];
}

std::shared_ptr<Classroom> Classroom::getLeft()
{
    return seq[place-1];
}

double Classroom::getTemperature(bool random)
{
    int sigma{3};
    double mean{27};
    double min{mean-3*sigma};
    double max{mean+3*sigma};
    
    // srand(time(0));
    // srandom(time(NULL));
    
    if (random)
    {
        temperature = round (( (max - min) * ( static_cast<double>(rand()) / RAND_MAX ) + min )*100.0) / 100.0;
    }

    guass_output = ( 1/(sigma*sqrt(2*M_PI)) )*exp( -pow((temperature-mean),2)/(2*pow(sigma,2)) );
    // std::cout << temperature << "  " << guass_output << std::endl; 

    return temperature;
}

size_t Classroom::noOfSeats()
{
    return this->seats;

}

void Classroom::show() const
{
    std::cout << std::left << std::setfill(' ') << std::setw(7) << "Class:" << name << " ,"
              << std::left << std::setfill(' ') << std::setw(7) << "Seats:" << seats << " ,"
              << std::left << std::setfill(' ') << std::setw(13) << "Temperature:" << temperature << std::endl;
    
}

std::vector<std::shared_ptr<Classroom>> Classroom::getSeq()
{
    return seq;
}

int Classroom::totalObjects()
{
    return no;
}

void Classroom::setSeats(size_t number)
{
    this->seats = number;
}

std::string Classroom::getName()
{
    return name;
}
