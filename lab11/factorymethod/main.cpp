//
// Created by piotr on 18.05.2017.
//


#include <iostream>
#include <complex>
#include <vector>
#include "FactoryMethod.h"

int main(){
    std::cout << factoryMethod::Sum(2,1) << '\n';
    int z=67;
    std::cout << factoryMethod::Value(&z) << '\n';
    std::vector<int> a {1,2,3,4,5,6,7};
    std::cout << factoryMethod::Avrage(a);


}
