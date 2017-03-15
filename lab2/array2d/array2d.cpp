//
// Created by piotr on 14.03.2017.
//

#include "array2d.h"
#include <iostream>
using namespace std;

int **Array2D(int n_rows, int n_columns){
    if(n_rows <= 0 || n_columns <= 0) return nullptr;

    int **tab = new int *[n_rows];
    for(int i=0;i<n_rows;++i) tab[i]= new int [n_columns];

    int tab1d=1;
    for(int i=0;i<n_rows;++i){
        for(int j=0;j<n_columns;++j) {
            tab[i][j]=tab1d;
            tab1d++;
        }
    }

    return tab;
}

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for(int i=0;i<n_rows;++i) delete array[i];
    delete array;
}
