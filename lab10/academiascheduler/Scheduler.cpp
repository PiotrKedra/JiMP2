//
// Created by piotr on 15.05.2017.
//

#include <algorithm>
#include "Scheduler.h"

namespace academia{
    void Schedule::InsertScheduleItem(const SchedulingItem &item){
        time_.push_back(item);
        std::sort(time_.begin(),time_.end(),
                  [](SchedulingItem a, SchedulingItem b) {
                      return a.GetTimeSlot() < b.GetTimeSlot();
                  });
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule of_teacher;
        std::copy_if(this->time_.begin(),this->time_.end(),of_teacher.time_.begin(),
                     [teacher_id](SchedulingItem a){ return (a.GetTeacherId()==teacher_id);});
        return of_teacher;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule of_room;
        std::copy_if(this->time_.begin(),this->time_.end(),of_room.time_.begin(),
                     [room_id](SchedulingItem a){ return (a.GetRoomId()==room_id);});
        return of_room;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule of_year;
        std::copy_if(this->time_.begin(),this->time_.end(),of_year.time_.begin(),
                     [year](SchedulingItem a){ return (a.GetYear()==year);});
        return of_year;
    }

    size_t Schedule::Size() const {
        return time_.size();
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> available;
        for(int i=1;i<=n_time_slots;++i){
            available.push_back(i);
        }
        int k=0;
        if(!this->time_[k].GetTimeSlot()){
            return available;
        }
        int j=this->time_[k].GetTimeSlot();
        for(int i=1;i<=n_time_slots;++i){
            if(i==j){
                std::remove(available.begin(),available.end(),i);
                ++k;
                if(!this->time_[k].GetTimeSlot()){
                    return available;
                }
                j=this->time_[k].GetTimeSlot();
            }
        }
        return available;
    }

}
