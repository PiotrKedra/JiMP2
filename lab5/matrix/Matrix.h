//
// Created by piotr on 31.03.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <experimental/optional>
#include <complex>

namespace algebra{
    class Matrix{
    public:
        Matrix(std::complex<double> **param);
        Matrix(std::string param);
        ~Matrix();

        std::string Print();
        std::pair<size_t ,size_t> Size();
        Matrix add(Matrix m);

    private:
        std::string matrix="";
        std::complex<double> **tab;
        std::pair<size_t,size_t> size;
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
