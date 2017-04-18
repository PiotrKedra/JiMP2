//
// Created by piotr on 15.04.2017.
//

#include <iostream>
#include "WordCounter.h"

namespace datastructures{
    WordCounter::WordCounter(){
        distinct_words=0;
        total_words=0;
    }
    WordCounter::WordCounter(std::initializer_list<Word> words){
        distinct_words=0;
        total_words=0;
        for(auto w: words){
            if(mapo_.find(w)!=mapo_.end()){
                for(auto e: mapo_){
                    if(e.first.GetWord()==w) {
                        mapo_[e.first].operator++();
                    }
                }
            }
            else{
                Counts tmp_counts;
                Word tmp_word{w};
                mapo_[tmp_word]=tmp_counts;
                distinct_words++;
            }
            total_words++;

        }
    }
    int WordCounter::DistinctWords(){
        return distinct_words;
    }
    int WordCounter::TotalWords(){
        return total_words;
    }
    std::set<Word> WordCounter::Words(){
        std::set<Word> expected;
        for(auto e:mapo_){
            expected.emplace(e.first);
        }
        return expected;
    }
    int WordCounter::operator[](std::string value){
        for(auto e:mapo_){
            if(e.first.GetWord()==value){
                return e.second.GetCounts();
            }
        }
        return 0;
    }
}
