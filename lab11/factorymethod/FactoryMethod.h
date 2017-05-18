//
// Created by piotr on 18.05.2017.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>

namespace factoryMethod{
    class MyType{
    public:
        std::string SayHello(){
            return "hello";
        }
    };
    template<class T>
    T Create(){
        return T();
    }
    template <class T>
    T Sum(T a, T b){
        return a+b;
    }
    template <class T>
    auto Value(T t){
        return *t;
    }
    template <class T>
    auto Avrage(T t){
        
    }
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
