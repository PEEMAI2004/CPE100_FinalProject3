#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "struct.h"


// Function to remove a model from the database using vendor code
void removeModelUsingVendorCode()
{
    // Declare variables
    char vendercode[32];
    struct phoneModel model;
    FILE *fp, *temp;

    // Get vendor code from user
    printf("Enter Vendor Code: ");
    scanf("%s", vendercode);

    // Open file in read binary mode
    fp = fopen(modelsfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Open temporary file in write binary mode
    temp = fopen("temp.dat", "wb");

    // Check if file is opened successfully
    if (temp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Read each model from file
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        // Check if vendor code matches
        if (strcmp(model.vendercode, vendercode) != 0)
        {
            // Write model to temporary file
            fwrite(&model, sizeof(struct phoneModel), 1, temp);
        }
    }

    // Close files
    fclose(fp);
    fclose(temp);

    // Delete original file
    remove(modelsfilename);

    // Rename temporary file to original file name
    rename("temp.dat", modelsfilename);
}

// Function to remove a model from the database using model number
// Remove all phones with the same model number
void removeModelUsingModelNumber()
{
    // Declare variables
    char modelnumber[10];
    struct phoneModel model;
    FILE *fp, *temp;

    // Get model number from user
    printf("Enter Model Number: ");
    scanf("%s", modelnumber);

    // Open file in read binary mode
    fp = fopen(modelsfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Open temporary file in write binary mode
    temp = fopen("temp.dat", "wb");

    // Check if file is opened successfully
    if (temp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Read each model from file
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        // Check if model number matches
        if (strcmp(model.modelnumber, modelnumber) != 0)
        {
            // Write model to temporary file
            fwrite(&model, sizeof(struct phoneModel), 1, temp);
        }
    }

    // Close files
    fclose(fp);
    fclose(temp);

    // Delete original file
    remove(modelsfilename);

    // Rename temporary file to original file name
    rename("temp.dat", modelsfilename);
}

// Function to remove a phone from the database using serial number
void removePhone()
{
    // Declare variables
    char serialnumber[10];
    struct phone phone;
    FILE *fp, *temp;

    // Get serial number from user
    printf("Enter Serial Number: ");
    scanf("%s", serialnumber);

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Open temporary file in write binary mode
    temp = fopen("temp.dat", "wb");

    // Check if file is opened successfully
    if (temp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Read each phone from file
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        // Check if serial number matches
        if (strcmp(phone.serialnumber, serialnumber) != 0)
        {
            // Write phone to temporary file
            fwrite(&phone, sizeof(struct phone), 1, temp);
        }
    }

    // Close files
    fclose(fp);
    fclose(temp);

    // Delete original file
    remove(phonesfilename);

    // Rename temporary file to original file name
    rename("temp.dat", phonesfilename);
}

// Function to edit sell price of model using vendor code
void editModelSellPriceUsingVendorCode()
{
    // Declare variables
    char vendercode[10];
    int sellprice;
    struct phoneModel model;
    FILE *fp, *temp;

    // Get vendor code from user
    printf("Enter Vendor Code: ");
    scanf("%s", vendercode);

    // Open file in read binary mode
    fp = fopen(modelsfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Open temporary file in write binary mode
    temp = fopen("temp.dat", "wb");

    // Check if file is opened successfully
    if (temp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Read each model from file
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        // Check if vendor code matches
        if (strcmp(model.vendercode, vendercode) == 0)
        {
            // Get new sell price from user
            printf("Enter new sell price: ");
            scanf("%d", &sellprice);

            // Update sell price
            model.sellprice = sellprice;
        }

        // Write model to temporary file
        fwrite(&model, sizeof(struct phoneModel), 1, temp);
    }

    // Close files
    fclose(fp);
    fclose(temp);

    // Delete original file
    remove(modelsfilename);

    // Rename temporary file to original file name
    rename("temp.dat", modelsfilename);
}
