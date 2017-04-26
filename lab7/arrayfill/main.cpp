//
// Created by piotr on 19.04.2017.
//

#include <iostream>
#include "ArrayFill.h"
#include <random>
#include <memory>

int main(){
    std::vector<int> vs;
    arrays::FillArray(24, arrays::SquaredFill {}, &vs);
    arrays::PrintArray(vs);

    return 0;
};

