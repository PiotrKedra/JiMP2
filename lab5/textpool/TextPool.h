//
// Created by piotr on 05.04.2017.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool{
    class TextPool{
    public:
        TextPool() {};
        TextPool(std::initializer_list<std::string> list);
        TextPool(TextPool &&text);
        TextPool &operator=(TextPool &&text);
        ~TextPool() {};


        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::set<std::string> words;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
