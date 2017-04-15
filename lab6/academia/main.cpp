//
// Created by piotr on 06.04.2017.
//
#include "StudentRepository.h"

int main(){
    academia::StudyYear y{3};
    
    y.Print();
    
    y.operator--();
    
    y.Print();
    
    
    return 0;
}
