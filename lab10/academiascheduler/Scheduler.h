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
        int CourseId() const{
            return course_id;
        }
        int TimeSlot() const{
            return time_slot;
        }
        int TeacherId() const{
            return teacher_id;
        }
        int  RoomId() const{
            return room_id;
        }
        int Year() const{
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
        const SchedulingItem operator[](const int i) const{
            return time_[i];
        }
    private:
        std::vector<SchedulingItem> time_;
    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int,
                std::vector<int>> &teacher_courses_assignment,
                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };

    class GreedyScheduler: public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int,
                std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) override;
    };
    class NoViableSolutionFound: public std::runtime_error{
        NoViableSolutionFound(const std::string message): std::runtime_error(message){}
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
