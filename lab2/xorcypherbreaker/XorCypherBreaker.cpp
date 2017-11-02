//
// Created by piotr on 15.03.2017.
//

#include "XorCypherBreaker.h"
<<<<<<< HEAD
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


=======
#include <algorithm>

using std::string;
using std::vector;

string XorCypherBreaker(const vector<char> &cryptogram, const vector<string> &dictionary){
    vector<char> key;
    
>>>>>>> remotes/origin/lab3


}