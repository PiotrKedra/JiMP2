//
// Created by piotr on 15.05.2017.
//
#include "Scheduler.h"
#include <vector>
#include <set>
#include <map>
#include <memory>

using ::std::unique_ptr;
using ::std::make_unique;
using ::std::vector;
using ::std::set;
using ::std::pair;
using ::std::map;
using ::academia::Schedule;

int main(){
    unique_ptr<academia::Scheduler> scheduler = make_unique<academia::GreedyScheduler>();

    vector<int> rooms{1000};
    map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 20}),
                                   make_pair(200, vector<int>{30}),
                                   make_pair(300, vector<int> {40})};
    map<int, set<int>> years{make_pair(1, set<int>{10, 20}), make_pair(2, set<int>{30, 40})};

    Schedule schedule;
    schedule = scheduler->PrepareNewSchedule(rooms, teachers, years, 5);

    return 0;
};