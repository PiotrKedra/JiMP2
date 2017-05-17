//
// Created by piotr on 15.05.2017.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <cstddef>

namespace academia{
    class SchedulingItem{
    public:
        SchedulingItem(int courseId, int teacherId, int roomId, int timeSlot, int year):
                course_id(courseId),teacher_id(teacherId),room_id(roomId),
                time_slot(timeSlot),year_(year){}
        int GetTimeSlot(){
            return time_slot;
        }
        int GetTeacherId(){
            return teacher_id;
        }
        int  GetRoomId(){
            return room_id;
        }
        int GetYear(){
            return year_;
        }
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year_;
    };
    class Schedule{
    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        SchedulingItem operator[](int i){
            return time_[i];
        }
    private:
        std::vector<SchedulingItem> time_;
        /*std::vector<SchedulingItem> Monday;
        std::vector<SchedulingItem> Tuesday;
        std::vector<SchedulingItem> Wednesday;
        std::vector<SchedulingItem> Thursday;
        std::vector<SchedulingItem> Friday;*/
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
