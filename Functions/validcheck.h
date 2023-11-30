#ifndef VALIDCHECK_H
#define VALIDCHECK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "struct.h"
#include "files.h"

// Function to check if the given SN is exist in the database or not return true if exist and false if not
bool isSerialNumberExist(char *sn)
{
    // Declare variables
    struct phone phone;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return false;
    }

    // Check if SN exist
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        if (strcmp(phone.serialnumber, sn) == 0)
        {
            // Close file
            fclose(fp);
            return true;
        }
    }

    // Close file
    fclose(fp);
    return false;
}

// Function to check if the given model number is exist in the database or not return true if exist and false if not
bool isModelNumberExist(char *modelnumber)
{
    // Declare variables
    struct phoneModel model;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(modelsfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return false;
    }

    // Check if model number exist
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        if (strcmp(model.modelnumber, modelnumber) == 0)
        {
            // Close file
            fclose(fp);
            return true;
        }
    }

    // Close file
    fclose(fp);
    return false;
}

// Function to check if the given vendor code is exist in the database or not return true if exist and false if not
bool isVendorCodeExist(char *vendorcode)
{
    // Declare variables
    struct phoneModel model;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(modelsfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return false;
    }

    // Check if vendor code exist
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        if (strcmp(model.vendercode, vendorcode) == 0)
        {
            // Close file
            fclose(fp);
            return true;
        }
    }

    // Close file
    fclose(fp);
    return false;
}

// Function to check if the phone is sold or not return true if sold and false if not
bool isPhoneSold(char *sn)
{
    // Declare variables
    struct phone phone;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return false;
    }

    // Check if SN exist
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        if (strcmp(phone.serialnumber, sn) == 0)
        {
            // Close file
            fclose(fp);
            return phone.sold;
        }
    }

    // Check if the phone is sold or not
    if (phone.sold == 1)
    {
        // Close file
        fclose(fp);
        return true;
    }
    // Check if the phone has sold date = 0 or nut
    else if (phone.sellDT.day == 0)
    {
        // Close file
        fclose(fp);
        return true;
    }

    // Close file
    fclose(fp);
    return false;
}
//
#endif // VALIDCHECK_H