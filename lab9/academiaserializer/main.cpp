//
// Created by piotr on 04.05.2017.
//

#include <memory>
#include <iostream>


std::unique_ptr<int> GiveMeItForASec(std::unique_ptr<int> p) {
    ++(*p);
    return p;
}

int main(){
    std::unique_ptr<int> value=std::make_unique<int>(3);
    std::cout << *value;

    value=GiveMeItForASec(move(value));
    std::cout << *value;


    return 0;
}

