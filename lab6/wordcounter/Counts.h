//
// Created by piotr on 17.04.2017.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H


namespace datastructures{
    class Counts {
    public:
        Counts();
        Counts(int value);
        Counts& operator++();
        int GetCounts() const { return counts_; }
    private:
        int counts_;
    };

    bool operator==(const Counts& left, const int right);
    bool operator<(const Counts& left, const Counts& right);
    bool operator>(const Counts& left, const Counts& right);

}

#endif //JIMP_EXERCISES_COUNTS_H
