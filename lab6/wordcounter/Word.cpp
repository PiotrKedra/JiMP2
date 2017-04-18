//
// Created by piotr on 17.04.2017.
//

#include "Word.h"


namespace datastructures{
    Word::Word(std::string word) {
        word_=word;
    }
    std::string Word::GetWord() const {
        return word_;
    }
    bool operator<(const Word& left,const Word& right){
        return left.GetWord()[0] < right.GetWord()[0];
    }
    bool operator==(const Word& left,const Word& right){
        return left.GetWord()[0]==right.GetWord()[0];
    }
}
