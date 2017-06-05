//
// Created by piotr on 01.06.2017.
//

#ifndef JIMP_EXERCISES_ARABICROMAN_H
#define JIMP_EXERCISES_ARABICROMAN_H

#include <string>

class Number{
public:
    Number(std::string roman): roman_(roman){
        int result=0;
        for(auto ch: roman){
        }
        arabic_=result;
    }
    Number(int arabic): arabic_(arabic){}
    int GetArabic(){
        return arabic_;
    }
    std::string GetRoman(){
        return roman_;
    }
private:
    std::string roman_;
    int arabic_;
};

#endif //JIMP_EXERCISES_ARABICROMAN_H
