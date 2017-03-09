//
// Created by piotr on 09.03.2017.
//

#include "ReverseString.h"
#include <string>

std::string reverse(std::string str) {
    char tmp;
    size_t size = str.size();
    int x;

    if (size % 2 == 0) x = size / 2;
    else x = (size - 1) / 2;

    int j = (size - 1);
    for (int i = 0; i < x; i++) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j--;
    }

    return std::string(str);
}