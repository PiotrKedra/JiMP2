//
// Created by piotr on 19.04.2017.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <cstddef>
#include <random>
#include <memory>

namespace arrays{
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class SquaredFill : public ArrayFill{
    public:
        SquaredFill(int a=1,int b=1);
        virtual int Value(int index) const override;
    private:
        int value_;
        int b_;
    };

    class RandomFill : public ArrayFill{
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution<int>> distribution);
        virtual int Value(int index) const override;
    private:
        std::unique_ptr<std::default_random_engine> generator_;
        std::unique_ptr<std::uniform_int_distribution<int>> distribution_;
    };

    class IncrementalFill : public ArrayFill{
    public:
        IncrementalFill(int start, int step=1);
        virtual int Value(int index) const override;
    private:
        int start_;
        int step_;
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);
    void PrintArray(const std::vector<int> &array);
}

#endif //JIMP_EXERCISES_ARRAYFILL_H
