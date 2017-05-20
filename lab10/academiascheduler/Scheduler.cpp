//
// Created by piotr on 15.05.2017.
//

#include <algorithm>
#include <numeric>
#include <iostream>
#include "Scheduler.h"

namespace academia {
    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        time_.push_back(item);
        std::sort(time_.begin(), time_.end(),
                  [](SchedulingItem a, SchedulingItem b) {
                      return a.TimeSlot() < b.TimeSlot();
                  });
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule of_teacher;
        std::copy_if(this->time_.begin(), this->time_.end(), std::back_inserter(of_teacher.time_),
                     [teacher_id](SchedulingItem a) { return (a.TeacherId() == teacher_id); });
        return of_teacher;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule of_room;
        std::copy_if(this->time_.begin(), this->time_.end(), std::back_inserter(of_room.time_),
                     [room_id](SchedulingItem a) { return (a.RoomId() == room_id); });
        return of_room;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule of_year;
        std::copy_if(this->time_.begin(), this->time_.end(), std::back_inserter(of_year.time_),
                     [year](SchedulingItem a) { return (a.Year() == year); });
        return of_year;
    }


    Schedule Schedule::OfCourse(int course) const {
        Schedule out;
        std::copy_if(this->time_.begin(), this->time_.end(), std::back_inserter(out.time_),
                     [course](const SchedulingItem &compare) { return compare.CourseId() == course; });
        return out;
    }


        size_t Schedule::Size() const {
        return time_.size();
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> available;
        for (int i = 1; i < n_time_slots + 1; ++i) {
            if (!std::any_of(time_.begin(), time_.end(),
                             [i](const SchedulingItem in_iter) {
                                 return i == in_iter.TimeSlot();
                             })) {
                available.push_back(i);
            }
        }
        return available;
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int,
            std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
// wykomentowane by sprobwac zbuldowac testy, main sie builduje
//        //jesli iloczyn slotow i sal jest mniejszy nisz suma wszystkich zajec studentow to nie da sie ułozyc planu
//        if(rooms.size()*n_time_slots < std::accumulate(courses_of_year.begin(),courses_of_year.end(),0,
//                                                     [](std::pair<int,std::set<int>> it)
//                                                     { return it.second.size();}))
//            throw NoViableSolutionFound("NoViableSolutionFound") ; //not sure if trow is well writen
        Schedule new_schedule;
        for(auto teacher : teacher_courses_assignment) {
            std::vector<int> CourseIds = teacher.second;
            for(auto course : CourseIds) {
                new_schedule.InsertScheduleItem(SchedulingItem(course,teacher.first,0,0,0));
            }
        }
        for(auto &item : new_schedule.time_) {
            for (auto year : courses_of_year) {
                for (auto course : year.second) {
                    if (item.CourseId() == course) {
                        item.year_ = year.first;
                    }
                }
            }
        }
        int i=1;
        for(auto item1: new_schedule.time_){
            item1.room_id = 1000;
            item1.time_slot = i;
            ++i;
            std::cout << item1.CourseId() << ", " << item1.TeacherId() << ", " << item1.RoomId() <<", "<< item1.TimeSlot() <<", "<<item1.Year() << '\n';
        }
        return new_schedule;
    }
}
