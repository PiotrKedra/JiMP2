//
// Created by piotr on 19.04.2017.
//

#include <iostream>
#include "ArrayFill.h"

namespace arrays{
    int UniformFill::Value(int index) const {
        return value_;
    }

    SquaredFill::SquaredFill(){value_=1; b_=0;}
    SquaredFill::SquaredFill(int value) {value_=value; b_=0;}
    SquaredFill::SquaredFill(int value,int b){
        value_=value;
        b_=b;
    }
    int SquaredFill::Value(int index) const {
        return (value_*index*index)+b_;
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution<int>> distribution){
        std::default_random_engine new_generator;
        std::uniform_int_distribution<int> new_distribution(1,6);
        value_=new_distribution(new_generator);
    }
    int RandomFill::Value(int index) const{
        return value_;
    }

    IncrementalFill::IncrementalFill(int start){
        start_=start;
        step_=1;
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
