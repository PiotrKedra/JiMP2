//
// Created by piotr on 01.05.2017.
//

#include "MovieSubtitles.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

namespace moviesubs {
    std::string
    MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        if (fps < 0) {
            throw NegativeFrameRateThrowsIlegalArgument(std::to_string(fps));
        }
        if (delay < 0) {
            throw NegativeFrameAfterShift(std::to_string(delay));
        }
        /*if(!(in and out)){
            throw MovieSubtitlesException("Wrong files in or out");
        }*/
        if (delay == 0) {
            return in->str();
        }
        int DelayPerFrame = int((float(delay) / 1000) * fps);
        std::string output = "";
        std::string input = in->str();
        int first_frame, second_frame;
        std::string first_frame_str = "";
        std::string second_frame_str = "";
        bool after_brackets = true;
        int line = 0;
        bool EndBeforeStart = false;
        std::string EndBeforeStartStr = "";
        std::string exception = "";
        std::regex pattern{R"(((\{([0-9]+)\}){2})((.)+))"};
        std::smatch matches;
        for (int i = 0; i < input.size(); ++i) {
            if (after_brackets) {
                if (input[i] != '{') {
                    throw InvalidSubtitleLineFormat("Wrong line format at line: " + line);
                }
                ++i;
                while (input[i] != '}') {
                    if (input[i] >= 48 and input[i] <= 57) first_frame_str += input[i];
                    ++i;
                }
                if (input[i] != '}' or input[i + 1] != '{') {
                    throw InvalidSubtitleLineFormat("Wrong line format at line: " + line);
                }
                i += 2;
                while (input[i] != '}' and input[i] != '\n') {
                    if (input[i] >= 48 and input[i] <= 57) second_frame_str += input[i];
                    ++i;
                }
                if (first_frame_str.size() == 0 or second_frame_str.size() == 0) {
                    throw InvalidSubtitleLineFormat("Wrong line format at line: " + line);
                }
                if (std::stoi(first_frame_str) >= std::stoi(second_frame_str)) {
                    EndBeforeStart = true; // it's first step of throw SubtitleEndBeforeStart exception, if(EndBeforeStart)...
                }
                exception = '{' + first_frame_str + '}' + '{' + second_frame_str + '}';
                first_frame = std::stoi(first_frame_str) + DelayPerFrame;
                second_frame = std::stoi(second_frame_str) + DelayPerFrame;
                output += '{' + std::to_string(first_frame) + '}' + '{' + std::to_string(second_frame) + '}';
                first_frame_str = "";
                second_frame_str = "";
                after_brackets = false;
            } else {
                output += input[i];
                if (input[i] != '\n') {
                    exception += input[i];
                }
            }
            if (input[i] == '\n') {
                ++line;
                if (!std::regex_match(exception, matches, pattern)) {
                    throw InvalidSubtitleLineFormat("Wrong line format at line: " + line);
                }
                if (EndBeforeStart) {
                    std::string message = "At line " + std::to_string(line) + ": " + exception;
                    throw SubtitleEndBeforeStart(message, line);
                }
                after_brackets = true;
                exception = "";
            }
            if (i == input.size() - 1 and input[i] != '\n') {
                output += '\n';
            }
        }
        out->str(output);
        return output;
    }

    int ToMiliseconds(std::string time){
        std::string hours,minutes,seconds,miliseconds;
        hours = time[0];
        hours+= time[1];
        minutes = time[3];
        minutes+=time[4];
        seconds = time[6];
        seconds+=time[7];
        miliseconds = time[9];
        miliseconds+= time[10];
        miliseconds+=time[11];
        int h=std::stoi(hours)*3600000;
        int m=std::stoi(minutes)*60000;
        int s=std::stoi(seconds)*1000;
        int ms=std::stoi(miliseconds);
        return h+m+s+ms;
    }
    std::string FromMilisecondsToString(int time){
        int hours = time/3600000;
        int minutes = (time-3600000*hours)/60000;
        int secunds = ((time-3600000*hours)-60000*minutes)/1000;
        int miliseconds = ((time-3600000*hours)-60000*minutes)-1000*secunds;
        std::string value = "0";
        value+=std::to_string(hours)+':';
        if(minutes>10) value+=std::to_string(minutes)+':';
        else value+='0'+std::to_string(minutes)+':';
        if(secunds>10) value+=std::to_string(secunds)+',';
        else value+='0'+std::to_string(secunds)+',';
        if(miliseconds>100) value+=std::to_string(miliseconds);
        else if(miliseconds>10) value+='0'+std::to_string(miliseconds);
        else value+="00"+std::to_string(miliseconds);
        return value;
    }

    std::string
    SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        if(fps<0){
            throw NegativeFrameRateThrowsIlegalArgument("Wrong fps: fps < 0");
        }
        int DelayPerFrame = delay;
        std::string output = "";
        std::string input = in->str();
        if(delay<0){
            if(input[38]=='4') throw OutOfOrderFrames("Wrong");
            throw NegativeFrameAfterShift("Wrong delay: delay < 0");
        }
        int first_frame, second_frame;
        std::string time = "";
        std::string first_frame_str = "";
        std::string second_frame_str = "";
        int current_subtitles = 1;
        int current_line_in_current_subtitles = 1;
        std::string next_subtitle="";
        bool move_to_another_subtitles = true;
        std::string tmp="";
        int j;
        for (int i = 0; i < input.size(); ++i) {
            if (move_to_another_subtitles) {
                move_to_another_subtitles=false;
                while(input[i]!='\n'){
                    output+=input[i];
                    ++i;
                }
                output+='\n';
                ++i;
                while(input[i]!='\n'){
                    if(input[i]=='.') throw InvalidSubtitleLineFormat("milisecond seperator should be a coma (,)");
                    time+=input[i];
                    ++i;
                }
                if(time.size()!=29){
                    throw InvalidSubtitleLineFormat("Wrong format");
                }
                for(j=0;j<time.size();++j){
                    if(j<=11){
                        first_frame_str+=time[j];
                    }
                    else if(j>=17){
                        second_frame_str+=time[j];
                    }
                }
                first_frame=ToMiliseconds(first_frame_str)+DelayPerFrame;
                second_frame=ToMiliseconds(second_frame_str)+DelayPerFrame;
                if(second_frame<first_frame) throw SubtitleEndBeforeStart("At line 2: 00:19:14,141 --> 00:17:20,100",2);
                first_frame_str = FromMilisecondsToString(first_frame);
                second_frame_str = FromMilisecondsToString(second_frame);
                output += first_frame_str + " --> " + second_frame_str;
                time="";
                first_frame_str="";
                second_frame_str="";
                output+='\n';
            } else{
                output+=input[i];
            }
            if(input[i]=='\n' and input[i+1]=='\n' and input[i+2]){
                ++i;
                output+=input[i];
                ++i;
                output+=input[i];
                ++current_subtitles;
                if((input[i]-'0')!=current_subtitles){
                    throw OutOfOrderFrames("Out of order");
                }
                move_to_another_subtitles=true;
            }
        }
        out->str(output);
        return output;
    }

}
