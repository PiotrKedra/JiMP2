//
// Created by piotr on 01.05.2017.
//

#include "MovieSubtitles.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

namespace moviesubs{
    std::string MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out){
        if(fps<0){
            throw NegativeFrameRateThrowsIlegalArgument(std::to_string(fps));
        }
        if(delay<0){
            throw NegativeFrameAfterShift(std::to_string(delay));
        }
        if(!(in and out)){
            throw MovieSubtitlesException("Wrong files in or out");
        }
        if(delay==0){
            return in->str();
        }
        int DelayPerFrame = int((float(delay)/1000)*fps);
        std::string output = "";
        std::string input = in->str();
        int first_frame, second_frame;
        std::string first_frame_str = "";
        std::string second_frame_str = "";
        bool after_brackets=true;
        int line=0;
        bool EndBeforeStart = false;
        std::string EndBeforeStartStr = "";
        std::string exception = "";
        std::regex pattern {R"(\{[0-9]+\}\{[0-9]+\}(...))"};
        for(int i=0;i<input.size();++i){
            if(input[i]=='{' and after_brackets){
                ++i;
                while (input[i]!='}'){
                    first_frame_str+=input[i];
                    ++i;
                }
                i+=2;
                while (input[i]!='}'){
                    second_frame_str+=input[i];
                    ++i;
                }
                if(std::stoi(first_frame_str)>=std::stoi(second_frame_str)){
                    EndBeforeStart=true; // it's first step of throw SubtitleEndBeforeStart exception, if(EndBeforeStart)...
                }
                first_frame = std::stoi(first_frame_str) + DelayPerFrame;
                second_frame = std::stoi(second_frame_str) + DelayPerFrame;
                output += '{' + std::to_string(first_frame) + '}' + '{' + std::to_string(second_frame) + '}';
                exception='{' + first_frame_str + '}' + '{' + second_frame_str + '}';
                first_frame_str = "";
                second_frame_str = "";
                after_brackets=false;
            } else{
                output += input[i];
                if(input[i]!='\n'){
                    exception+=input[i];
                }
            }
            if(input[i]=='\n'){
                ++line;
                if(EndBeforeStart){
                    std::string message = "At line " + std::to_string(line) + ": " + exception;
                    throw SubtitleEndBeforeStart(message, line);
                }
                after_brackets= true;
                std::smatch matches;
                /*if(!std::regex_match(exception, matches, pattern)){
                    std::string message = "At line " + std::to_string(line) + ": " + exception;
                    throw InvalidSubtitleLineFormat(message);
                }*/
                exception = "";
            }
            if(i==input.size()-1 and input[i]!='\n'){
                output += '\n';
            }
        }
        out->str(output);
        return output;
    }

}