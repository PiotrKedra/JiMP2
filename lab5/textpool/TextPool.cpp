//
// Created by piotr on 05.04.2017.
//

#include "TextPool.h"
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool{
    TextPool::TextPool(std::initializer_list<std::string> list){
        for(auto e: list){
            words.insert(e);
        }
    }
    TextPool::TextPool(TextPool &&text){
        std::swap(words,text.words);
    }
    TextPool & TextPool::operator=(TextPool &&text) {
        if(this == &text) return *this;
        std::swap(words,text.words);
        return *this;
    }
    std::experimental::string_view TextPool::Intern(const std::string &str){
        auto tmp = words.insert(str);
        std::experimental::string_view out = *tmp.first;
        return out;
    }
    size_t TextPool::StoredStringCount() const{
        size_t size = words.size();
        return size;
    }
}