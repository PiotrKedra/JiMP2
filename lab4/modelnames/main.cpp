//
// Created by piotr on 23.03.2017.
//

#include <Name.h>
#include <string>

int main(){
    name::Name hoho {"Marcelinka", "Banas","Lewak","Kluska"};
    hoho.FirstName();
    hoho.SecondName();
    hoho.ThirdName();
    hoho.Surname();

    hoho.ToFullInitials();
    hoho.ToFirstNamesInitials();
    hoho.ToNamesSurname();
    hoho.ToSurnameNames();

    name::Name ho {"Piotr", "Kedra", "Chlop",""};

    ho.ToFullInitials();
    ho.ToFirstNamesInitials();
    ho.ToNamesSurname();
    ho.ToSurnameNames();
    return 0;
};