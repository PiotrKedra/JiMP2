//
// Created by piotr on 31.03.2017.
//

#include "Matrix.h"
#include <experimental/optional>
#include <regex>


namespace algebra{
    std::complex<double> **array2d(size_t rows,size_t columns){
        std::complex<double> **tab = new std::complex<double> *[rows];
        for(int i=0;i<rows;++i){
            tab[i] = new std::complex<double> [columns];
        }
        return tab;
    }
    Matrix::Matrix(std::complex<double> **param):
        tab(param){}

    Matrix::Matrix(std::string param):
        matrix(param){
        size.first = 1;
        size.second = 1;
        bool falg = true;
        for(int i=0;i<param.size();++i){
            if(param[i] == ';'){
                ++size.first;
                falg = false;
            }
            if(param[i]== ' ' and falg){
                ++size.second;
            }
        }
        tab = array2d(size.first,size.second);
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
                    if(i_col == size.second-1){
                        i_col=0;
                        ++i_row;
                    }
                    ++i_col;
                }
                else{

                }
            }
        }
    }
    Matrix::~Matrix() {}

    std::string Matrix::Print() {
        if(matrix==""){
            int i=0,j=0;
            while(tab[i]){
            }
        }
        return matrix;
    }

    std::pair<size_t ,size_t> Matrix::Size(){
        return size;
    };

    Matrix Matrix::add(Matrix m){

    }


}

/*
std::experimental::optional<std::string> MaybeString(bool create) {
    if (create) {
        return std::experimental::make_optional("CREATED");*/
