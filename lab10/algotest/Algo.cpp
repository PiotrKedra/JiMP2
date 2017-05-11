//
// Created by piotr on 11.05.2017.
//

#include "Algo.h"
#include <algorithm>


namespace algo{
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){

    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> keys;
        std::transform(m.begin(), m.end(), keys.begin(),
                       [](const auto &para)
                       { return para.first; });
        return keys;
    }

    std::vector<std::string> Values(const std::map<std::string, int> &m) {
        std::vector<std::string> values;
        std::transform(m.begin(), m.end(), values.begin(),
                       [](std::pair<std::string,int> para)
                       { return para.second; });
        return values;    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        std::map<std::string, int> expected;
        std::transform(m.begin(), m.end(), expected.begin(),
                       [divisor](std::pair<std::string,int> para)
                       { return std::pair<std::string,int>(para.first, para.second/divisor); });
        return expected;
    }

    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(),v->end());
    }

    std::vector<int> Sort(const std::vector<int> &v) {
        std::vector<int> reurned=v;
        std::sort(reurned.begin(),reurned.end());
        return reurned;
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(),
                  [](std::pair<int,int> a, std::pair<int,int> b) {return a.first < b.first;});
    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(),
                  [](std::pair<int,int> a, std::pair<int,int> b) {return a.second < b.second;});
    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
        std::sort(v->begin(), v->end(),
                  [](std::tuple<int,int,int> a, std::tuple<int,int,int> b)
                  {return std::get<2>(a) < std::get<2>(b);});
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> keys;
        std::transform(v.begin(), v.end(), keys.begin(),
                       [](double value)
                       { return std::to_string(value); });
        return keys;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        return std::string();
    }

    int Sum(const std::vector<int> &v) {
        return 0;
    }

    int Product(const std::vector<int> &v) {
        return 0;
    }

    bool Contains(const std::vector<int> &v, int element) {
        return false;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return false;
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return false;
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        return std::vector<std::string>();
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {

    }

    void InitializeWith(int initial_value, std::vector<int> *v) {

    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        return std::vector<int>();
    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return 0;
    }
}