//
// Created by piotr on 15.04.2017.
//

#include <iostream>
#include <map>
#include "WordCounter.h"


int main(){
    datastructures::WordCounter counter {datastructures::Word("a"), datastructures::Word("a"), datastructures::Word("a")};

    std::cout << counter.DistinctWords() << " " << counter.TotalWords() << " " << counter["a"] << std::endl;



    return 0;
}