//
// Created by piotr on 31.03.2017.
//

#include <iostream>
#include "Matrix.h"


using namespace algebra;
using std::cout;
using std::endl; 


int main(){
    std::complex<double> tab[][3] = {{7 + 1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
    Matrix bob{"[1 1 1;1 1 1;1 1 1]"};
    cout << bob.Print() << endl;

    Matrix b{tab};

    cout << tab[0][0] << endl;

    std::string orbits = "365.24";
    std::string::size_type sz; // alias of size_t
    double earth = std::stod (orbits,&sz);
    cout << "The moon completes " << earth << " orbits per Earth year.\n";
    
    return 0;
};

