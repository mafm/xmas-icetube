#ifndef TIME_H
#define TIME_H

#include <avr/pgmspace.h>

// month numbers
#define TIME_JAN 1
#define TIME_FEB 2
#define TIME_MAR 3
#define TIME_APR 4
#define TIME_MAY 5
#define TIME_JUN 6
#define TIME_JUL 7
#define TIME_AUG 8
#define TIME_SEP 9
#define TIME_OCT 10
#define TIME_NOV 11
#define TIME_DEC 12

// day-of-week numbers
#define TIME_SUN 0
#define TIME_MON 1
#define TIME_TUE 2
#define TIME_WED 3
#define TIME_THU 4
#define TIME_FRI 5
#define TIME_SAT 6

#define TIME_UNSET  0x01
#define TIME_DST    0x02
#define TIME_MMDDYY 0x04
#define TIME_12HOUR 0x08

typedef struct {
    uint8_t  status;   // status flags
    uint8_t  year;     // years past 2000
    uint8_t  month;    // month (1 is jan)
    uint8_t  day;      // day of month
    uint8_t  hour;     // hours past midnight
    uint8_t  minute;   // minutes past hour
    uint8_t  second;   // seconds past minute
} time_t;

extern volatile time_t time;

void time_init(void);

void time_save(void);
void time_settime(uint8_t hour, uint8_t minute, uint8_t second);
void time_setdate(uint8_t year, uint8_t month, uint8_t day);
void time_load(void);

void time_sleep(void);
inline void time_wake(void) {};

void time_tick(void);
inline void time_semitick(void) {};

uint8_t time_dayofweek(uint8_t year, uint8_t month, uint8_t day);
uint8_t time_daysinmonth(uint8_t year, uint8_t month);

#endif
