//
// Created by piotr on 19.04.2017.
//

#include <iostream>
#include "ArrayFill.h"

namespace arrays{
    int UniformFill::Value(int index) const {
        return value_;
    }

    SquaredFill::SquaredFill(int a,int b){
        value_=a;
        b_=b;
    }
    int SquaredFill::Value(int index) const {
        return (value_*index*index)+b_;
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> generator,
                           std::unique_ptr<std::uniform_int_distribution<int>> distribution)
            :generator_(move(generator)),distribution_(move(distribution)){}
    int RandomFill::Value(int index) const{
        return (*distribution_)(*generator_);
    }

    IncrementalFill::IncrementalFill(int start, int step){
        start_=start;
        step_=step;
    }
    int IncrementalFill::Value(int index) const{
        return start_+(index*step_);
    }


    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }
    void PrintArray(const std::vector<int> &array){
        for(int i=0;i<array.size();++i){
            std::cout << array[i] << " ";
        }
    }
}
