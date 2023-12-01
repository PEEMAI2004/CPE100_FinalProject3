#ifndef FINDFUNCTIONS_H
#define FINDFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "struct.h"
#include "dateandtimefunction.h"
#include "validcheck.h"

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
    printf("MN\tVC\tManuf.\tMName\t\tStorage\tColor\tSell Price\n");
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        printf("%s\t%s\t%s\t%s\t\t%d\t%s\t%d\n", model.modelnumber, model.vendercode, model.manufacture, model.modelname, model.storage, model.coloroption, model.sellprice);
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
void FindPhoneusingSN(char *SN)
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

    // Find phone by Model-Number
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        if (strcmp(phone.serialnumber, SN) == 0)
        {
            printf("Serial Number\tModel Number\tVendor Code\tPurchase Price\tPurchase Date\tPurchase Time\tSell Price\tSell Date\tSell Time\n");
            printf("%s\t%s\t%s\t%d\t%d-%d-%d\t%d:%d\t%d\t%d-%d-%d\t%d:%d\n", phone.serialnumber, phone.modelnumber, phone.vendercode, phone.purchaseprice, phone.purchaseDT.year, phone.purchaseDT.month, phone.purchaseDT.day, phone.purchaseDT.hour, phone.purchaseDT.minute, phone.sellprice, phone.sellDT.year, phone.sellDT.month, phone.sellDT.day, phone.sellDT.hour, phone.sellDT.minute);
            break;
        }
    }

    // Close file
    fclose(fp);
}

// Function to input SN to find phone
void FindPhoneusingSNInput()
{
    // Declare variables
    char SN[32];

    // Get SN from user
    printf("Enter Serial Number: ");
    scanf("%s", SN);

    // Find phone by SN
    FindPhoneusingSN(SN);
}

// Function to find a phone by Vendor-Code
void FindPhoneusingVC(char *VC)
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

    // Find phone by Vendor-Code
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        if (strcmp(phone.vendercode, VC) == 0)
        {
            printf("Serial Number\tModel Number\tVendor Code\tPurchase Price\tPurchase Date\tPurchase Time\tSell Price\tSell Date\tSell Time\n");
            printf("%s\t%s\t%s\t%d\t%d-%d-%d\t%d:%d\t%d\t%d-%d-%d\t%d:%d\n", phone.serialnumber, phone.modelnumber, phone.vendercode, phone.purchaseprice, phone.purchaseDT.year, phone.purchaseDT.month, phone.purchaseDT.day, phone.purchaseDT.hour, phone.purchaseDT.minute, phone.sellprice, phone.sellDT.year, phone.sellDT.month, phone.sellDT.day, phone.sellDT.hour, phone.sellDT.minute);
            break;
        }
    }

    // Close file
    fclose(fp);
}

// Function to input VC to find phone
void FindPhoneusingVCInput()
{
    // Declare variables
    char VC[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", VC);

    // Find phone by VC
    FindPhoneusingVC(VC);
}

// Function to find a Model-Number by Vendor-Code, return modelnumber
char *FindModelusingVC(char *VC)
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
        return NULL;
    }

    // Find model by Vendor-Code
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        if (strcmp(model.vendercode, VC) == 0)
        {
            fclose(fp);
            char *modelnumber = malloc(strlen(model.modelnumber) + 1);
            strcpy(modelnumber, model.modelnumber);
            return modelnumber;
        }
    }

    // Close file
    fclose(fp);
    // return NULL if VC is not found
    return NULL;
}

// Function to find model data using Model-Number and print all MN, VC, Manufacture, Model-Name, Storage, Color, Sell-Price
void FindModelDataUsingMN(char *MN)
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

    bool found = false;

    // Find model data by Model-Number
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        if (strcmp(model.modelnumber, MN) == 0)
        {
            if (!found) // Print header
            {
                printf("Model Number\tVendor Code\tManufacture\tModel Name\tStorage\tColor\tSell Price\n");
            }
            printf("%s\t%s\t%s\t%s\t%d\t%s\t%d\n", model.modelnumber, model.vendercode, model.manufacture, model.modelname, model.storage, model.coloroption, model.sellprice);
            found = true;
        }
    }

    // Close file
    fclose(fp);
}

// Function to find model data using Model-Number in CLI
void FindModelDatausingMNInput()
{
    // Declare variables
    char MN[32];

    // Get MN from user
    printf("Enter Model Number: ");
    scanf("%s", MN);

    // Find model by MN
    FindModelDataUsingMN(MN);
}

// Function to find model data using VC and print all MN, VC, Manufacture, Model-Name, Storage, Color, Sell-Price
void FindModelDataUsingVC(char *VC)
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

    // Find model data by Model-Number
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        if (strcmp(model.vendercode, VC) == 0)
        {
            printf("Model Number\tVendor Code\tManufacture\tModel Name\tStorage\tColor\tSell Price\n");
            printf("%s\t%s\t%s\t%s\t%d\t%s\t%d\n", model.modelnumber, model.vendercode, model.manufacture, model.modelname, model.storage, model.coloroption, model.sellprice);
            break;
        }
    }

    // Close file
    fclose(fp);
}

// Function to find model data using VC in CLI
void FindModelDatausingVCInput()
{
    // Declare variables
    char VC[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", VC);

    // Find model by VC
    FindModelDataUsingVC(VC);
}

// Function to find a Vendor-Code by Serial-Number, return vendorcode
char *FindVCusingSN(char *SN)
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
        return NULL;
    }

    // Find phone by Serial-Number
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        if (strcmp(phone.serialnumber, SN) == 0)
        {
            fclose(fp);
            char *vendorcode = phone.vendercode;
            printf("VC: %s\n", vendorcode);
            return vendorcode;
        }
    }

    // Close file
    fclose(fp);
    // return NULL if SN is not found
    printf("Error finding VC\n");
    return NULL;
}

// Function to find a Sell-Price by Vendor-Code, return sellprice
int FindSellPriceusingVC(char *VC)
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
        return -1;
    }

    // Find sellprice by Vendor-Code, ignore spaces
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        if (strcmp(model.vendercode, VC) == 0)
        {
            fclose(fp);
            int sellprice = model.sellprice;
            return sellprice;
        }
    }

    // Close file
    fclose(fp);
    // return -1 if VC is not found
    printf("Error finding Sell Price\n");
    return -1;
}

// Function to find Sell-Price by Serial-Number, return sellprice, use existing function FindVCusingSN
int FindSellPriceusingSN(char *SN)
{
    // Declare variables
    char *VC = FindVCusingSN(SN);

    // Check if VC is found
    if (VC == NULL)
    {
        printf("Error finding Vendor Code\n");
        return -1;
    }

    // Find sellprice by VC
    int sellprice = FindSellPriceusingVC(VC);
    return sellprice;
}

#endif // FINDFUNCTIONS_H