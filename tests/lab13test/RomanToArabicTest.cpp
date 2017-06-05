//
// Created by mwypych on 01.06.17.
//
#include <string>
#include <gtest/gtest.h>
#include "arabicroman.h"

class RomanArabic : public ::testing::Test{
public:
};

TEST(RomanArabic,I_To_1){
    Number tested {"I"};
    EXPECT_EQ(1,tested.GetArabic());
}
TEST(RomanArabic,IV_4){
    Number tested {"IV"};
    EXPECT_EQ(4,tested.GetArabic());
}
TEST(RomanArabic,V_5){
    Number tested {"V"};
    EXPECT_EQ(5,tested.GetArabic());
}
TEST(RomanArabic,X_10){
    Number tested {"X"};
    EXPECT_EQ(10,tested.GetArabic());
}
TEST(RomanArabic,XXI_21){
    Number tested {"XXI"};
    EXPECT_EQ(21,tested.GetArabic());
}
TEST(RomanArabic,L_50){
    Number tested {"L"};
    EXPECT_EQ(50,tested.GetArabic());
}
TEST(RomanArabic,C_100){
    Number tested {"C"};
    EXPECT_EQ(100,tested.GetArabic());
}
TEST(RomanArabic,CCXLIV_244){
    Number tested {"CCXLIV"};
    EXPECT_EQ(244,tested.GetArabic());
}




