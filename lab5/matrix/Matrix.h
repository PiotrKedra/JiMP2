//
// Created by piotr on 31.03.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <experimental/optional>
#include <complex>

namespace nets{
    class Matrix{
    public:
        Matrix(std::string param);
        ~Matrix();

        std::string print_str();
        Matrix add(Matrix m);

    private:
        std::string matrix;
        std::complex<double> **tab;
        size_t rows = 0;
        size_t columns = 0;
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
