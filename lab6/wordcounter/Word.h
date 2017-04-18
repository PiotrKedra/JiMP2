//
// Created by piotr on 17.04.2017.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>


namespace datastructures{
    class Word{
    public:
        Word(std::string word);
        std::string GetWord() const;
        
    private:
        std::string word_;
    };
    bool operator<(const Word& left,const Word& right);
    bool operator==(const Word& left,const Word& right);
}

#endif //JIMP_EXERCISES_WORD_H
