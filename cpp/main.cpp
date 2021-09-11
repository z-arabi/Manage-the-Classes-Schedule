#include <iostream>
#include "aphw2.h"
#include "gtest/gtest.h"

#include "floor.h"
#include "classroom.h"

int main(int argc, char **argv)
{
    // ::testing::InitGoogleTest(&argc, argv);
    // std::cout << "RUNNING TESTS ..." << std::endl;
    // int ret{RUN_ALL_TESTS()};
    // if (!ret)
    //     std::cout << "<<<SUCCESS>>>" << std::endl;
    // else
    //     std::cout << "FAILED" << std::endl;

    auto a = std::make_shared<Classroom>("411", 40);
    auto b = std::make_shared<Classroom>("413", 30);
    auto c = std::make_shared<Classroom>("415", 20);
    // a->setLeft(c);
    // c->setRight(a);
    // b->setLeft(a);
    // a->setRight(b);
    // c->setLeft(b);
    // b->setRight(c);
    // a->setSeats(5);
    // std::cout << a->getTemperature() << std::endl;
    // std::cout << b->getTemperature() << std::endl;
    // std::cout << c->getTemperature() << std::endl;
    // Floor f4{"4", b};
    // std::cout << f4.noOfClasses() << " " << f4.noOfSeats() << std::endl;
    // std::cout << "**" << f4.noOfSeats(1) << std::endl;
    // std::cout << "**" << f4.operator[](1)->noOfSeats() << std::endl;
    // if ( f4.operator[](-8) == c)
    //     std::cout << "true" << std::endl;  
    // std::cout << "temp is" << f4.getTemperature() << std::endl;
    // f4.setPointer(a);
    // std::cout << f4.noOfSeats(0) << std::endl;
    // std::cout << f4.moveSeats(0,1,10) << "**" << f4.noOfSeats(0) << std::endl;
    // f4.show();
    // show(a);
    // show(f4);
    // f4[0]->show();

    Floor f4{"Fourth", 3, c,b,a};
    std::cout << f4.noOfClasses() << std::endl;
    std::cout << "**" << f4.noOfSeats(1) << std::endl;
    f4.show();

    f4.setPointer(a);
    f4[0]->show();

    return 0;
}
