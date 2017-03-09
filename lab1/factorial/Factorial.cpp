//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
    int result=1;
    if(value>=13) return 0;
    if(value>0 || value<13){
        for(int i=value;i>1;i--){
            result*=i;
        }
    }
    if(value<0 || value>(-13)){
        for(int i=value;i<0;i++){
            result*=i;
        }
    }
    if(value == 0) return result;
  return result;
}
