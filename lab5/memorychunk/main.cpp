//
// Created by piotr on 29.03.2017.
//

#include <iostream>
#include <cstring>
#include "MemoryChunk.h"

using namespace memorychunk;
/*MemoryChunk make_copy(MemoryChunk xxx) {
    return xxx;
}*/


int main() {

    char* abc=new char[2048];
    std::cout << strlen(abc) << std::endl;

    return 0;
}