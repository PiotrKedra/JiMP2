//
// Created by piotr on 15.03.2017.
//

#include "XorCypherBreaker.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<string> &dictionary){
    for(int i=0;i<cryptogram.size();++i){
        cryptogram[i]+=key_length;
    }

    string password;
    for(int i=0;i<cryptogram.size();++i){
        password[i] = cryptogram[i];
    }

    if (find(dictionary.begin(),dictionary.end(),password) != dictionary.end()) return password;




}