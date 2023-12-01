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

// Function to count all unsold phones in the database from phonesfilename
int countAllUnsoldPhones()
{
    int unsold = countAllPhones() - countAllSoldPhones();
}

// Function to count all unsold phones in the database from phonesfilename CLI
void countAllUnsoldPhonesCLI()
{
    // Print number of phones
    printf("Total unsold phones: %d\n", countAllUnsoldPhones());
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

// Function to show vendor code that has lower unsold phones than user specified to function
// SUDO CODE
// Loop through all VC
// Count unsold phones using VC
// If unsold phones < user specified, print VC with number of unsold phones
void ShowUnsoldVCthatLessthan(int userUnsoldPhones)
{
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
        // Count unsold phones using VC
        int unsoldPhones = countUnsoldPhonesUsingVC(model.vendercode);

        // Check if unsold phones < user specified
        if (unsoldPhones < userUnsoldPhones)
        {
            // Print VC with number of unsold phones
            printf("VC: %s, Unsold phones: %d\n", model.vendercode, unsoldPhones);
        }
    }

    // Close file
    fclose(fp);
}

// Function to show vendor code that has lower unsold phones than user specified to function CLI
void ShowUnsodlVCthatLessthanCLI()
{
    // Declare variables
    int userUnsoldPhones;

    // Get user input
    printf("Enter number of unsold phones: ");
    scanf("%d", &userUnsoldPhones);

    // Show vendor code that has lower unsold phones than user specified to function
    ShowUnsoldVCthatLessthan(userUnsoldPhones);
}

// Function to show vendor code that has lower unsold phones than user specified to function on start use configfilename (.yaml)
void ShowUnsoldVCthatLessthanOnStart() {
    
    char choice;
    while (getchar() != '\n');
    printf("Do you want to view low stock Notify? (y/n): \n");
    scanf("%c", &choice);

    // Check if user want to show it
    if (choice == 'y' || choice == 'Y') {
        // Get user input for number of unsold phones and compute
        ShowUnsodlVCthatLessthanCLI();
    }
}

#endif