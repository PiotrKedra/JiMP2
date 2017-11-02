//
// Created by piotr on 09.03.2017.
//

#include "Polybius.h"
#include <map>
#include <bits/valarray_before.h>
#include <string>
#include <algorithm>

using namespace std;

string PolybiusCrypt(string message){
    string new_message;
    map <char,string> m={{'a',"11"},{'b',"12"},{'c',"13"},{'d',"14"},{'e',"15"},
                         {'f',"21"},{'g',"22"},{'h',"23"},{'i',"24"},{'k',"25"},
                         {'l',"31"},{'m',"32"},{'n',"33"},{'o',"34"},{'p',"35"},
                         {'q',"41"},{'r',"42"},{'s',"43"},{'t',"44"},{'u',"45"},
                         {'v',"51"},{'w',"52"},{'x',"53"},{'y',"54"},{'z',"55"}};

    transform(message.begin(),message.end(),message.begin(),::tolower); //zamienia na male
    for(int i=0;i<message.length();++i){
       // if(message[i]>=65 || message[i]<=90) message[i]=char(message[i]+32);
        if(message[i]=='j') message[i]='i';
    }
    for(int i=0;i<message.length();++i){
        for(const auto &n : m){
            if(message[i]==n.first){
                new_message[2*i]=n.second[0];
                new_message[2*i+1]=n.second[1];
                break;
            }
        }
    }
    return new_message;
}
string PolybiusDecrypt(string crypted){
    string new_crypted;
    map <char,string> m={{'a',"11"},{'b',"12"},{'c',"13"},{'d',"14"},{'e',"15"},
                         {'f',"21"},{'g',"22"},{'h',"23"},{'i',"24"},{'k',"25"},
                         {'l',"31"},{'m',"32"},{'n',"33"},{'o',"34"},{'p',"35"},
                         {'q',"41"},{'r',"42"},{'s',"43"},{'t',"44"},{'u',"45"},
                         {'v',"51"},{'w',"52"},{'x',"53"},{'y',"54"},{'z',"55"}};

    for(int i=0;i<(crypted.length()/2);i=+2){
        string tmp;
        tmp[0]=crypted[i];
        tmp[1]=crypted[i+1];
        for(const auto &n : m){
            if (tmp.compare(n.second)==0) {
                new_crypted[i] = n.first;
                break;
            }
            }
        }

    return new_crypted;
}