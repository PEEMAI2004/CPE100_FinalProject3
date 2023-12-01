#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "struct.h"


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
    printf("MN\tVC\tManuf.\tMName\tStorage\tColor\tSell Price\n");
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

    // Print table header
    printf("Serial Number\tModel Number\tVendor Code\tPurchase Price\tPurchase Date\tPurchase Time\tSell Price\tSell Date\tSell Time\n");

    // Print all phones
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        printf("%s\t%s\t%s\t%d\t%d-%d-%d\t%d:%d\t%d\t%d-%d-%d\t%d:%d\n", phone.serialnumber, phone.modelnumber, phone.vendercode, phone.purchaseprice, phone.purchaseDT.year, phone.purchaseDT.month, phone.purchaseDT.day, phone.purchaseDT.hour, phone.purchaseDT.minute, phone.sellprice, phone.sellDT.year, phone.sellDT.month, phone.sellDT.day, phone.sellDT.hour, phone.sellDT.minute);
    }

    // Close file
    fclose(fp);
}
