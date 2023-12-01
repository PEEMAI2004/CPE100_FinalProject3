#ifndef FUNCTIONS_SELLPHONE_H
#define FUNCTIONS_SELLPHONE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "struct.h"
#include "dateandtimefunction.h"
#include "validcheck.h"
#include "findfunctions.h"

// Function to sell a phone using SN
// By sell phone, it add Sell date and time, Sell price to the database
// This function take SN and sell price as input
void sellPhone(char *SN, int sellPrice)
{
    // Declare variables
    struct phone phone;
    FILE *fp;
    struct Dateandtime dt;

    // Check if SN is exist in the database
    if (!isSerialNumberExist(SN))
    {
        printf("Serial Number not exist\n");
        return;
    }

    // Check if the phone is sold before
    if (isPhoneSold(SN))
    {
        printf("Phone is already sold\n");
        return;
    }

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb+");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Get current date and time
    dt = getCurrentDateTime();

    // Update phone
    while (fread(&phone, sizeof(struct phone), 1, fp))
    {
        if (strcmp(phone.serialnumber, SN) == 0)
        {
            // Check if phone is sold
            if (phone.sold == 1)
            {
                printf("Phone is already sold\n");
                return;
            }

            // Update phone
            phone.sellprice = sellPrice;
            phone.sellDT = dt;
            phone.sold = 1;

            // Move file pointer to the beginning of the record
            fseek(fp, -sizeof(struct phone), SEEK_CUR);

            // Write the record to the file
            fwrite(&phone, sizeof(struct phone), 1, fp);

            // Close file
            fclose(fp);

            // Print success message
            printf("Phone is sold successfully\n");
            return;
        }
    }

    // Close file
    fclose(fp);
}

// Function to sell a phone using SN via CLI
void sellPhoneCLI()
{
    // Declare variables
    char SN[32];
    char VC[32];
    int sellPrice;

    // Get SN from user
    printf("Enter Serial Number: ");
    scanf("%s", SN);

    // Ask user to manually enter VC price
    printf("Enter Vendor Code: ");
    scanf("%s", VC);

    // Get sell price from database using function FindSellPriceusingVC
    sellPrice = FindSellPriceusingVC(VC);
    if (sellPrice == -1)
    {
        // Ask user to manually enter sell price
        printf("Preconfig Price not exist\nPlese enter sell price:\n");
        scanf("%d", &sellPrice);
        sellPhone(SN, sellPrice);
    }

    // Ask user to use predefined sell price or not
    printf("Do you want to use predefined sell price? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    // Check if user want to use predefined sell price
    if (choice == 'y')
    {
        // Sell phone
        sellPhone(SN, sellPrice);
        return;
    }
    else
    {
        // Get sell price from user
        printf("Enter Sell Price: ");
        scanf("%d", &sellPrice);
    }

    // Sell phone
    sellPhone(SN, sellPrice);
}

#endif // FUNCTIONS_SELLPHONE_H