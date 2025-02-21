#include "Date.h"  // your Date class from a previous lab
// --TODO: Date.h 
//
#include "Time.h"  // your Time class from this lab. Dont have yet
#include "Vector.h" // your Template Vector class from this lab
// #include anything else you need

typedef struct {
    Date date;
    Time time;
    float speed;
} WindRecType;

typedef Vector<WindRecType> WindLogType;
