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

        int course_id_check=0;
        int wantedLectures=0;
        for(auto &c : courses_of_year)
        {
            for(auto &d : c.second)
            {
                course_id_check=d;
                for(auto &f : teacher_courses_assignment)
                {
                    for(auto &g : f.second)
                    {
                        if(g==course_id_check) wantedLectures++;
                    }
                }
                if(wantedLectures>n_time_slots) throw NoViableSolutionFound("No solution found");
                wantedLectures=0;
            }
        }
        Schedule schedule;
        std::vector<int> rooms_act = rooms;
        int teacher_id=0;
        int course_id=0;
        int year_id=0;
        int room_id=0;
        int n=1;
        bool room_full=false;
        for(auto const &teacher : teacher_courses_assignment)
        {
            teacher_id=teacher.first;
            for(auto const &item : teacher.second)
            {
                course_id=item;
                for(auto const &year : courses_of_year)
                {
                    if(year.second.find(course_id)!=year.second.end())
                    {
                        year_id=year.first;
                        break;
                    }
                }
                for(auto &room : rooms_act)
                {
                    if(n<=n_time_slots)
                    {
                        room_id=room;
                        break;
                    } else if(rooms_act.size()>1){
                        room_full=true;
                        n=1;
                    }
                    else throw NoViableSolutionFound("No solution found");
                }
                if(room_full) rooms_act.erase(rooms_act.begin());
                room_full=false;
                if(n>n_time_slots or rooms_act.size()==0) throw NoViableSolutionFound("No solution found");
                SchedulingItem tmp(course_id,teacher_id,room_id,n,year_id);
                n++;
                year_id=0;
                room_id=0;
                schedule.InsertScheduleItem(tmp);
            }
        }
        return schedule;
    }
}
