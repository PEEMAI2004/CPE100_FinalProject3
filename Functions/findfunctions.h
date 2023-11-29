#ifndef FINDFUNCTIONS_H
#define FINDFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "struct.h"
#include "dateandtimefunction.h"


// Function to print all Models in the database
void printAllModels()
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
        return;
    }

    // Print all models
    printf("Model Number\tVendor Code\tManufacturer\tModel Name\tStorage\tColor\tSell Price\n");
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        printf("%s\t%s\t%s\t%s\t%d\t%s\t%d\n", model.modelnumber, model.vendercode, model.manufacture, model.modelname, model.storage, model.coloroption, model.sellprice);
    }

    // Close file
    fclose(fp);
}

// Function to print all Phones in the database
void printAllPhones()
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
        return;
    }

    // Print all phones
    printf("Serial Number\tModel Number\tVendor Code\tPurchase Price\tPurchase Date\tPurchase Time\tSell Price\tSell Date\tSell Time\n");
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        printf("%s\t%s\t%s\t%d\t%d-%d-%d\t%d:%d\t%d\t%d-%d-%d\t%d:%d\n", phone.serialnumber, phone.modelnumber, phone.vendercode, phone.purchaseprice, phone.purchaseDT.year, phone.purchaseDT.month, phone.purchaseDT.day, phone.purchaseDT.hour, phone.purchaseDT.minute, phone.sellprice, phone.sellDT.year, phone.sellDT.month, phone.sellDT.day, phone.sellDT.hour, phone.sellDT.minute);
    }

    // Close file
    fclose(fp);
}

// Function to find a model by Model-Number
void FindPhoneusingSN(char *SN) {
    // Declare variables
    struct phone phone;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Find phone by Model-Number
    while (fread(&phone, sizeof(struct phone), 1, fp)) {
        if (strcmp(phone.serialnumber, SN) == 0) {
            printf("Serial Number\tModel Number\tVendor Code\tPurchase Price\tPurchase Date\tPurchase Time\tSell Price\tSell Date\tSell Time\n");
            printf("%s\t%s\t%s\t%d\t%d-%d-%d\t%d:%d\t%d\t%d-%d-%d\t%d:%d\n", phone.serialnumber, phone.modelnumber, phone.vendercode, phone.purchaseprice, phone.purchaseDT.year, phone.purchaseDT.month, phone.purchaseDT.day, phone.purchaseDT.hour, phone.purchaseDT.minute, phone.sellprice, phone.sellDT.year, phone.sellDT.month, phone.sellDT.day, phone.sellDT.hour, phone.sellDT.minute);
            break;
        }
    }

    // Close file
    fclose(fp);
}

// Function to input SN to find phone
void FindPhoneusingSNInput() {
    // Declare variables
    char SN[32];

    // Get SN from user
    printf("Enter Serial Number: ");
    scanf("%s", SN);

    // Find phone by SN
    FindPhoneusingSN(SN);
}

// Function to find a model by Vendor-Code
void FindPhoneusingVC(char *VC) {
    // Declare variables
    struct phone phone;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Find phone by Vendor-Code
    while (fread(&phone, sizeof(struct phone), 1, fp)) {
        if (strcmp(phone.vendercode, VC) == 0) {
            printf("Serial Number\tModel Number\tVendor Code\tPurchase Price\tPurchase Date\tPurchase Time\tSell Price\tSell Date\tSell Time\n");
            printf("%s\t%s\t%s\t%d\t%d-%d-%d\t%d:%d\t%d\t%d-%d-%d\t%d:%d\n", phone.serialnumber, phone.modelnumber, phone.vendercode, phone.purchaseprice, phone.purchaseDT.year, phone.purchaseDT.month, phone.purchaseDT.day, phone.purchaseDT.hour, phone.purchaseDT.minute, phone.sellprice, phone.sellDT.year, phone.sellDT.month, phone.sellDT.day, phone.sellDT.hour, phone.sellDT.minute);
            break;
        }
    }

    // Close file
    fclose(fp);
}

// Function to input VC to find phone
void FindPhoneusingVCInput() {
    // Declare variables
    char VC[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", VC);

    // Find phone by VC
    FindPhoneusingVC(VC);
}

// Function to find a Model-Number by Vendor-Code, return modelnumber
char *FindModelusingVC(char *VC) {
    // Declare variables
    struct phoneModel model;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(modelsfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    // Find model by Vendor-Code
    while (fread(&model, sizeof(struct phoneModel), 1, fp)) {
        if (strcmp(model.vendercode, VC) == 0) {
            fclose(fp);
            char *modelnumber = model.modelnumber;
            return modelnumber;
        }
    }

    // Close file
    fclose(fp);
    return NULL;
}

#endif // FINDFUNCTIONS_H