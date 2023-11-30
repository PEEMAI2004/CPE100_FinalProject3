#ifndef STROCK_H
#define STROCK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "struct.h"
#include "files.h"

// Function to count all phones in the database from phonesfilename
int countAllPhones()
{
    // Declare variables
    struct phone p;
    int count = 0;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    // Loop through file
    while (fread(&p, sizeof(struct phone), 1, fp))
    {
        // Increase count
        count++;
    }

    // Close file
    fclose(fp);

    // Return count
    return count;
}

// Function to count all phones in the database from phonesfilename CLI
void countAllPhonesCLI()
{
    // Print number of phones
    printf("Total phones: %d\n", countAllPhones());
}

// Function to count all unsold phones in the database from phonesfilename
int countAllUnsoldPhones()
{
    // Declare variables
    struct phone p;
    int count = 0;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    // Loop through file
    while (fread(&p, sizeof(struct phone), 1, fp))
    {
        // Check if sold is 0
        if (p.sold == 0)
        {
            // Increase count
            count++;
        }
    }

    // Close file
    fclose(fp);

    // Return count
    return count;
}

// Function to count all unsold phones in the database from phonesfilename CLI
void countAllUnsoldPhonesCLI()
{
    // Print number of phones
    printf("Total unsold phones: %d\n", countAllUnsoldPhones());
}

// Function to count all sold phones in the database from phonesfilename
int countAllSoldPhones()
{
    // Declare variables
    struct phone p;
    int count = 0;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    // Loop through file
    while (fread(&p, sizeof(struct phone), 1, fp))
    {
        // Check if sold is 1
        if (p.sold == 1)
        {
            // Increase count
            count++;
        }
    }

    // Close file
    fclose(fp);

    // Return count
    return count;
}

// Function to count all sold phones in the database from phonesfilename CLI
void countAllSoldPhonesCLI()
{
    // Print number of phones
    printf("Total sold phones: %d\n", countAllSoldPhones());
}

// Function to count phones using Vendor code in the database from phonesfilename
int countPhonesUsingVC(char *vc)
{
    // Declare variables
    struct phone p;
    int count = 0;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    // Loop through file
    while (fread(&p, sizeof(struct phone), 1, fp))
    {
        // Check if VC is equal to vc
        if (strcmp(p.vendercode, vc) == 0)
        {
            // Increase count
            count++;
        }
    }

    // Close file
    fclose(fp);

    // Return count
    return count;
}

// Function to count phones using Vendor code in the database from phonesfilename CLI
void countPhonesUsingVCCLI()
{
    // Declare variables
    char vc[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // Print number of phones using VC
    printf("Total phones using VC %s: %d\n", vc, countPhonesUsingVC(vc));
}

// Function to count unsold phones using Vendor code in the database from phonesfilename
int countUnsoldPhonesUsingVC(char *vc)
{
    // Declare variables
    struct phone p;
    int count = 0;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    // Loop through file
    while (fread(&p, sizeof(struct phone), 1, fp))
    {
        // Check if VC is equal to vc and sold is 0
        if (strcmp(p.vendercode, vc) == 0 && p.sold == 0)
        {
            // Increase count
            count++;
        }
    }

    // Close file
    fclose(fp);

    // Return count
    return count;
}

// Function to count unsold phones using Vendor code in the database from phonesfilename CLI
void countUnsoldPhonesUsingVCCLI()
{
    // Declare variables
    char vc[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // Print number of phones using VC
    printf("Unsold phones using VC %s: %d\n", vc, countUnsoldPhonesUsingVC(vc));
}

// Function to sold count phones using Vendor code in the database from phonesfilename
int countSoldPhonesUsingVC(char *vc)
{
    // Declare variables
    struct phone p;
    int count = 0;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(phonesfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    // Loop through file
    while (fread(&p, sizeof(struct phone), 1, fp))
    {
        // Check if VC is equal to vc and sold is 1
        if (strcmp(p.vendercode, vc) == 0 && p.sold == 1)
        {
            // Increase count
            count++;
        }
    }

    // Close file
    fclose(fp);

    // Return count
    return count;
}

// Function to count sold phones using Vendor code in the database from phonesfilename CLI
void countSoldPhonesUsingVCCLI()
{
    // Declare variables
    char vc[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // Print number of phones using VC
    printf("Sold phones using VC %s: %d\n", vc, countSoldPhonesUsingVC(vc));
}

// Function to print number of phones using Vendor code
// Mode: Tag "" all phones, Tag "unsold" unsold phones, Tag "sold" sold phones
// Header: Tag "header" print header, Tag "" don't print header, header is VC, MN, Manufacture, Model-Name, Storage, Color
// use existed function countPhonesUsingVC(), countUnsoldPhonesUsingVC(), countSoldPhonesUsingVC() to count phones
void printNumberOfPhonesUsingVC(char *vc, char *mode, char *header)
{
    // Declare variables
    int totalCount = countPhonesUsingVC(vc);
    int unsoldCount = countUnsoldPhonesUsingVC(vc);
    int soldCount = countSoldPhonesUsingVC(vc);

    // Print header if specified
    if (strcmp(header, "header") == 0)
    {
        printf("VC\tMN\tManufacture\tModel-Name\tStorage\tColor\n");
    }

    // Print count based on mode
    if (strcmp(mode, "") == 0)
    {
        printf("Total phones using VC %s: %d\n", vc, totalCount);
    }
    else if (strcmp(mode, "unsold") == 0)
    {
        printf("Unsold phones using VC %s: %d\n", vc, unsoldCount);
    }
    else if (strcmp(mode, "sold") == 0)
    {
        printf("Sold phones using VC %s: %d\n", vc, soldCount);
    }
}

// Function to print number of phones using Vendor code CLI
// Provide user option to choose mode, always print header
void printNumberOfPhonesUsingVCCLI()
{
    // Declare variables
    char vc[32];
    char mode[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // Get mode from user
    printf("Enter mode (1 for all phones, 2 for unsold phones, 3 for sold phones): ");
    int choice;
    scanf("%d", &choice);

    // Convert choice to mode
    if (choice == 1)
    {
        strcpy(mode, "");
    }
    else if (choice == 2)
    {
        strcpy(mode, "unsold");
    }
    else if (choice == 3)
    {
        strcpy(mode, "sold");
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    // Print number of phones using VC
    printNumberOfPhonesUsingVC(vc, mode, "header");
}

// Function to plug in all VC in database modelsfilename to printNumberOfPhonesUsingVC()
// Pass mode and header to printNumberOfPhonesUsingVC()
void printNumberOfPhonesUsingAllVC(char *mode, char *header)
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

    // Loop through file
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        // Print number of phones using VC
        printNumberOfPhonesUsingVC(model.vendercode, mode, header);
    }

    // Close file
    fclose(fp);
}

// Function to notifiy when strock is lower than user specified
// using countUnsoldPhonesUsingVC(), loop throught "modelsfilename" to Plug in all VC in models database
// Print header: VC, MN, Manufacture, Model-Name, Storage, Color, Remaining EA ,if there are any phones that have strock lower than "int user specified"
// Print List of VC, MN, Manufacture, Model-Name, Storage, Color, Number of unsold phones that have strock lower than user specified
void notifyStockLowerThan(int userSpecified)
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

    // Print header
    printf("VC\tMN\tManufacture\tModel-Name\tStorage\tColor\tRemaining EA\n");

    // Loop through file
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        // Declare variables
        int remainingEA = countUnsoldPhonesUsingVC(model.vendercode);

        // Check if remainingEA is lower than user specified
        if (remainingEA < userSpecified)
        {
            // Print VC, MN, Manufacture, Model-Name, Storage, Color, Remaining EA
            printf("%s\t%s\t%s\t%s\t%d\t%s\t%d\n", model.vendercode, model.modelnumber, model.manufacture, model.modelname, model.storage, model.coloroption, remainingEA);
        }
    }

    // Close file
    fclose(fp);
}

// Function to get user specified from config.yaml file key: notifyStrockLowerThan
int getUserSpecified()
{
    // Declare variables
    FILE *fp;
    char line[256];
    char *key;
    char *value;

    // Open file in read mode
    fp = fopen("config.yaml", "r");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    // Loop through file
    while (fgets(line, sizeof(line), fp))
    {
        // Get key and value from line
        key = strtok(line, ":");
        value = strtok(NULL, ":");

        // Check if key is notifyStrockLowerThan
        if (strcmp(key, "notifyStrockLowerThan") == 0)
        {
            // Close file
            fclose(fp);

            // Return value
            return atoi(value);
        }

        // if there is no key notifyStrockLowerThan, Create key notifyStrockLowerThan and set value to 10
        if (strcmp(key, "notifyStrockLowerThan") != 0)
        {
            // Close file
            fclose(fp);

            // Open file in append mode
            fp = fopen("config.yaml", "a");

            // Check if file is opened successfully
            if (fp == NULL)
            {
                printf("Error opening file\n");
                return -1;
            }

            // Write key and value to file
            fprintf(fp, "notifyStrockLowerThan: 10\n");

            // Close file
            fclose(fp);

            // Return 10
            return 10;
        }
    }

    // Close file
    fclose(fp);

    // Return -1 if not found
    return -1;
}

// Function to notifiy when strock is lower than user specified in config.yaml file
// using notifyStrockLowerThan()
void notifyStockLowerThanConfig()
{
    // Declare variables
    int userSpecified = 0;

    // Get user specified from config.yaml file
    userSpecified = getUserSpecified();

    // Print header
    printf("VC\tMN\tManufacture\tModel-Name\tStorage\tColor\tRemaining EA\n");

    // Print list of VC, MN, Manufacture, Model-Name, Storage, Color, Number of unsold phones that have strock lower than user specified
    notifyStockLowerThan(userSpecified);
}

// Function to edit notifyStrockLowerThan in config.yaml file
// print current value of notifyStrockLowerThan and ask user to enter new value with confirmation
void editNotifyNumberofUnsoldPhone() {
    
}

#endif