#ifndef DATEANDTIMEFUNCTIONS_H
#define DATEANDTIMEFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"

struct Dateandtime getCurrentDateTime()
{
    struct Dateandtime dt;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    dt.year = tm.tm_year + 1900;
    dt.month = tm.tm_mon + 1;
    dt.day = tm.tm_mday;
    dt.hour = tm.tm_hour;
    dt.minute = tm.tm_min;

    return dt;
}

#endif // DATEANDTIMEFUNCTIONS_H