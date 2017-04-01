//
// Created by piotr on 31.03.2017.
//

#include <iostream>
#include "Matrix.h"


using namespace nets;
using std::cout;
using std::endl; 


int main(){
    Matrix bob{"[1 1 1;1 1 1;1 1 1]"};
    cout << bob.print_str() << endl;

    std::string orbits = "365.24";
    std::string::size_type sz; // alias of size_t
    double earth = std::stod (orbits,&sz);
    cout << "The moon completes " << earth << " orbits per Earth year.\n";
    
    return 0;
};

