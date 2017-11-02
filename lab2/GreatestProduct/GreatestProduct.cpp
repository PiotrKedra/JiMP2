//
// Created by piotr on 14.03.2017.
//

#include "GreatestProduct.h"
#include <vector>

using namespace std;

int GreatestProduct(const vector<int> &numbers, int k){
    if(k == 0) return 0;
    if(k > numbers.size()) return 0;
    vector<int> another_vector;

    int smallest;

    for(int i: numbers){
        if(another_vector.size() < k) another_vector.push_back(i);
        else{
            int k = 0;
            int index;
            for(int j: another_vector){
                if(!smallest){
                    smallest = j;
                    index = k;
                }
                else if(j < smallest){
                    smallest = j;
                    index = k;
                }
                k++;
            }
            if(i > another_vector[index]) another_vector[index] = i;
        }

    }

    int value = 1;
    for(int i: another_vector) value*=i;

    return value;
}