#include <array>
#include <memory>
#include <TinyUrl.h>
#include <iostream>

int main(){
    std::array<char,6> yo;
    yo.fill('a');
    yo[5]='z';
    for(char v: yo) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
    tinyurl::NextHash(&yo);
    for(char v: yo){
        std::cout << v << ", ";
    }
    return 0;
}
