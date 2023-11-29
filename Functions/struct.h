#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to store Date and time
struct Dateandtime
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

// struct to store each model and option of phone
// Model-Number,Vendor-Code,Manufacturer,Model-Name,Storage,Color,Sell-Price
struct phoneModel
{
    char modelnumber[32];
    char vendercode[32];
    char manufacture[32];
    char modelname[32];
    int storage;
    char coloroption[32];
    int sellprice;
};

// struct to store each phone
// Serial-Number,Model-Number,Vendor-Code,Purchase-Price,Purchase-Date,Purchase-Time,Sell-Price,Sell-Date,Sell-Time
struct phone
{
    char serialnumber[32];
    char modelnumber[32];
    char vendercode[32];
    int purchaseprice;
    struct Dateandtime purchaseDT;
    int sellprice;
    struct Dateandtime sellDT;
};


#endif // STRUCT_H