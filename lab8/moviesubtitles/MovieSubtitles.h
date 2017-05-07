//
// Created by piotr on 01.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <stdexcept>
#include <sstream>

namespace moviesubs{
    int ToMiliseconds(std::string time);
    std::string FromMilisecondsToString(int time);

        class MovieSubtitles{
    public:
        virtual std::string ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out)=0;
    };
    class MicroDvdSubtitles : MovieSubtitles{
    public:
        std::string ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) override;

    };
    class SubRipSubtitles : MovieSubtitles{
    public:
        std::string ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) override;

    };

    /////// exception ///////

    class MovieSubtitlesException : public std::runtime_error{
    public:
        MovieSubtitlesException(std::string message) : std::runtime_error(message) {}
    };
    class NegativeFrameAfterShift : public MovieSubtitlesException{
    public:
        NegativeFrameAfterShift(std::string delay) : MovieSubtitlesException(delay){}
    };
    class NegativeFrameRateThrowsIlegalArgument : public std::invalid_argument{
    public:
        NegativeFrameRateThrowsIlegalArgument(std::string fps) : std::invalid_argument(fps){}
    };
    class SubtitleEndBeforeStart : public MovieSubtitlesException{
    public:
        SubtitleEndBeforeStart(std::string message, int line) : line_(line),MovieSubtitlesException(message){}
        int LineAt() const { return line_;}
    private:
        int line_;
    };
    class InvalidSubtitleLineFormat : public MovieSubtitlesException{
    public:
        InvalidSubtitleLineFormat(std::string message) : MovieSubtitlesException(message){}
    };
    class MissingTimeSpecification : public MovieSubtitlesException{
    public:
        MissingTimeSpecification(std::string message) : MovieSubtitlesException(message){}
    };
    class OutOfOrderFrames : public MovieSubtitlesException{
    public:
        OutOfOrderFrames(std::string message) : MovieSubtitlesException(message){}
    };

}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
