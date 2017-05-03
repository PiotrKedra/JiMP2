//
// Created by piotr on 01.05.2017.
//

#include <memory>
#include <regex>
#include <iostream>
#include "MovieSubtitles.h"

using namespace moviesubs;

int main(){
    auto subs = std::make_unique<MicroDvdSubtitles>();
    std::stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(300, 25, &in, &out);

    std::regex pattern {R"(\{[0-9]+\}\{[0-9]+\}(...)+)"};
    std::string str = "{0}{250}TExt";
    std::smatch matches;
    if(std::regex_match(str, matches, pattern)){
        std::cout << str;
    }


    return 0;
}
