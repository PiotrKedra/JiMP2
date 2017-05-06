//
// Created by piotr on 01.05.2017.
//

#include <memory>
#include <regex>
#include <iostream>
#include "MovieSubtitles.h"

using namespace moviesubs;

int main(){
    auto subs = std::make_unique<SubRipSubtitles>();
    std::stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(300, 24, &in, &out);

    std::cout << FromMilisecondsToString(ToMiliseconds("00:05:56,722")+300);
    return 0;
}
