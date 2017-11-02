//
// Created by piotr on 15.03.2017.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <string>
#include <vector>
#include <w32api/wsman.h>

using namespace std;

string XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<string> &dictionary);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
