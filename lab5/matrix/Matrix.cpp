//
// Created by piotr on 31.03.2017.
//

#include "Matrix.h"
#include <experimental/optional>
#include <regex>


namespace nets{
    Matrix::Matrix(std::string param):
        matrix(param){
        rows = 1;
        columns = 1;
        bool falg = true;
        for(int i=0;i<param.size();++i){
            if(param[i] == ';'){
                ++rows;
                falg = false;
            }
            if(param[i]== ' ' and falg){
                ++columns;
            }
        }
        tab = new std::complex<double> *[rows];
        for(int i=0;i<rows;++i){
            tab[i] = new std::complex<double> [columns];
        }
        int i_col=0;
        int i_row=0;
        std::regex valid {R"([0-9]{1,})"};
        std::string tmp;
        std::complex<double> elem;
        std::string::size_type sz;
        for(int i=1;i<param.size();++i){
            tmp="";
            if(param[i] != (' ' or  ';' or ']')) {
                while (param[i] != ' ') {
                    tmp += param[i];
                    ++i;
                }
                if(std::regex_match(tmp, valid)) {
                    tab[i_row][i_col] = std::stod (tmp,&sz);
                    ++i_col;
                }
            }
        }
    }
    Matrix::~Matrix() {}

    std::string Matrix::print_str() {
        return matrix;
    }

    Matrix Matrix::add(Matrix m){

    }


}

/*
std::experimental::optional<std::string> MaybeString(bool create) {
    if (create) {
        return std::experimental::make_optional("CREATED");*/
