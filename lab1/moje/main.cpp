//
// Created by piotr on 19.06.2017.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;
class Droga{
public:
    int m1,m2;
    double droga;
    Droga(int m3,int m4, double droga_):m1{m3},m2{m4},droga(droga_){}
};
class Miasto{
public:
    double x_,y_;
    int id_;
    string name_;
    Miasto(double x, double y, string name, int id){
        x_=x;
        y_=y;
        name_=name;
        id_=id;
    }
};
class Mapa{
public:
    vector<Miasto> miasta;
    vector<Droga> drogi;
    int ilosc_miast=0;

    int dodajMiasto(const char*nazwa, double x, double y){
        Miasto m{x,y,nazwa,ilosc_miast};
        miasta.push_back(m);
        ++ilosc_miast;
        return ilosc_miast-1;
    }
    bool dodajDroge(int m1, int m2, double dl){
        int czy_sa_miasta=0;
        for(auto e: miasta){
            if(e.id_==m1 or e.id_==m2) ++czy_sa_miasta;
        }
        if(czy_sa_miasta<2) return false;
        Droga d(m1,m2,dl);
        drogi.push_back(d);
        return true;
    }
    void sasiedzi(int m,list<int>&sa){
        for(auto e: drogi){
            if(m==e.m1) sa.push_back(e.m2);
            else if(m==e.m2) sa.push_back(e.m1);
        }
    }
    double odleglosc(int m1,int m2){
        for(auto e: drogi){
            if((e.m1==m1 and e.m2==m2)or(e.m1==m2 and e.m2==m1)){
                return e.droga;
            }
        }
        return 0;
    }

};

int main() {

}