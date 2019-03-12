#include <string>
#include <iostream>

using std::cout;
using std::string;

#include "labstructs.h"

std::string printTime(Time time) {
    return time.h + ":" + time.m;
}

int minutesSinceMidnight(Time time) {
	return (time.h * 60) + time.m;
}

int minutesUntil(Time earlier, Time later) {
	int time_e = minutesSinceMidnight(earlier);
	int time_l = minutesSinceMidnight(later);
	return (time_l - time_e);
}

Time addMinutes(Time time0, int min) {
	Time time1;
	int mod_min = time0.m + min;
	time1.m = mod_min % 60;
	time1.h = time0.h + (mod_min / 60);
	return time1;
}

std::string printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + mv.duration + " min)";
}

std::string TimeSlotString(TimeSlot ts) {
	string movie_info = printMovie(ts.movie);
	" [starts at " + printTime(ts.startTime); + 
	printTime(addMinutes(ts.startTime, ts.movie.duration));
	return ts.movie.title + " " + g + " (" + mv.duration + " min) [starts at ";
}