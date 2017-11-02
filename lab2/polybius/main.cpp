//
// Created by piotr on 09.03.2017.
//

#include <iostream>
#include <fstream>
#include "Polybius.h"

using namespace std;

int main(string input_file,string output_file,int what_to_do){
    char word[64];
    string input;
    string output;
    ifstream myfile;
    myfile.open(input_file,ios::in);

    if(!myfile) {
        cout << "Nie można otworzyć pliku wejściowego!" << endl;
        return 0;
    }
    while(myfile >> word){
        myfile >> input;
    }
    ofstream endfile;
    endfile.open(output_file, ios::out | ios::app);

    if(what_to_do==1){
        output=PolybiusCrypt(input);
        if(!endfile) cout <<  "Nie można otworzyć pliku!" << endl;
        else endfile << output;
    }
    else if(what_to_do==0){
        output=PolybiusDecrypt(input);
        if(!endfile) cout <<  "Nie można otworzyć pliku!" << endl;
        else endfile << output;
    }

    myfile.close();
    endfile.close();
    return 0;
}