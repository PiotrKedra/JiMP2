//
// Created by piotr on 15.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "Counts.h"
#include "Word.h"
#include <algorithm>
#include <map>
#include <set>



namespace datastructures{
    class WordCounter{
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> words);

        int DistinctWords();
        int TotalWords();
        std::set<Word> Words();
        int operator[](std::string value);

    private:
        std::map<Word,Counts> mapo_;
        int distinct_words;
        int total_words;
    };
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
