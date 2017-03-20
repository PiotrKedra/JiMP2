//
// Created by piotr on 16.03.2017.
//

#include "MinimalTimeDifference.h"
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>


using std::string;
/*atoi */

namespace minimaltimedifference {
    unsigned int ToMinutes(string time_HH_MM) {
        std::regex pattern1{R"((\d{1,2}):(\d{2}))"};
        std::smatch matches;
        string time1;
        string time2;
        unsigned int value = 0;
        if (regex_match(time_HH_MM, matches, pattern1)) {
            time1 = matches[1];
            time2 = matches[2];

            value += int(time2[1] - '0') + 10 * (int(time2[0] - '0'));
            if (time1.size() == 1) value += 60 * (int(time1[0] - '0'));
            else value += 600 * int(time1[0] - '0') + 60 * int(time1[1] - '0');
            return value;
        }
        return value;
    }

    unsigned int MinimalTimeDifference(std::vector<string> times) {
        std::vector<int> minutes;
        for (auto m: times) {
            minutes.push_back(ToMinutes(m));
        }

        int subtraction = 720;
        for(int i: minutes){
            for(int j: minutes){
                if(j!=i and ((i <= 720 and j <= 720) or (i >= 720 and j >= 720) and subtraction > abs(i-j))) {
                    subtraction = abs(i-j);
                }
                else if(j!=i &&( i <= 720 && j >= 720 && subtraction > i + (1440-j))) subtraction = i + (1480-j);
                else if (j!=i && (subtraction > j + (1440-i))) subtraction = j + (1440-i);
            }
        }

        return  subtraction;
    }
}