#pragma once

struct Time {
    int h;
    int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

struct Movie {
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

struct TimeSlot {
    Movie movie;     // what movie
    Time startTime;  // when it starts
};