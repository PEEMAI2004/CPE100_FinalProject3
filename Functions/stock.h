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

// Function to get total purchase price of all phones in the database from phonesfilename
int getTotalPurchasePrice()
{
    // Declare variables
    struct phone p;
    int total = 0;
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
        // Add purchase price to total
        total += p.purchaseprice;
    }

    // Close file
    fclose(fp);

    // Return total
    return total;
}

// Function to get total purchase price of all phones CLI
void getTotalPurchasePriceCLI()
{
    int total = getTotalPurchasePrice();
    printf("Total purchase price: %d\n", total);
}

// Function to get total sell price of all phones in the database from phonesfilename
int getTotalSellPrice()
{
    // Declare variables
    struct phone p;
    int total = 0;
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
        // Add sell price to total
        total += p.sellprice;
    }

    // Close file
    fclose(fp);

    // Return total
    return total;
}

// Function to get total sell price of all phones CLI
void getTotalSellPriceCLI()
{
    int total = getTotalSellPrice();
    printf("Total sell price: %d\n", total);
}

// Function to get total profit of all phones in the database from phonesfilename, use getTotalPurchasePrice() and getTotalSellPrice()
int getTotalProfit()
{
    return getTotalSellPrice() - getTotalPurchasePrice();
}

// Function to get total profit of all phones CLI
void getTotalProfitCLI()
{
    int total = getTotalProfit();
    printf("Total profit: %d\n", total);
}

// Function to get total purchase price of all phones share same VC in the database from phonesfilename
int getTotalPurchasePriceUsingVC(char *vc)
{
    // Declare variables
    struct phone p;
    int total = 0;
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
            // Add purchase price to total
            total += p.purchaseprice;
        }
    }

    // Close file
    fclose(fp);

    // Return total
    return total;
}

// Function to get total purchase price of all phones share same VC CLI
void getTotalPurchasePriceUsingVCCLI()
{
    // Declare variables
    char vc[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // check if VC is exist
    if (!isVendorCodeExist(vc))
    {
        printf("Vendor Code not exist\n");
        return;
    }

    // Print total purchase price using VC
    printf("Total purchase price using VC %s: %d\n", vc, getTotalPurchasePriceUsingVC(vc));
}

// Function to get total sell price of all phones share same VC in the database from phonesfilename
int getTotalSellPriceUsingVC(char *vc)
{
    // Declare variables
    struct phone p;
    int total = 0;
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
            // Add sell price to total
            total += p.sellprice;
        }
    }

    // Close file
    fclose(fp);

    // Return total
    return total;
}

// Function to get total sell price of all phones share same VC CLI
void getTotalSellPriceUsingVCCLI()
{
    // Declare variables
    char vc[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // check if VC is exist
    if (!isVendorCodeExist(vc))
    {
        printf("Vendor Code not exist\n");
        return;
    }

    // Print total sell price using VC
    printf("Total sell price using VC %s: %d\n", vc, getTotalSellPriceUsingVC(vc));
}

// Function to get total profit of all phones share same VC in the database from phonesfilename, use getTotalPurchasePriceUsingVC() and getTotalSellPriceUsingVC()
int getTotalProfitUsingVC(char *vc)
{
    return getTotalSellPriceUsingVC(vc) - getTotalPurchasePriceUsingVC(vc);
}

// Function to get total profit of all phones share same VC CLI
void getTotalProfitUsingVCCLI()
{
    // Declare variables
    char vc[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // check if VC is exist
    if (!isVendorCodeExist(vc))
    {
        printf("Vendor Code not exist\n");
        return;
    }

    // Print total profit using VC
    printf("Total profit using VC %s: %d\n", vc, getTotalProfitUsingVC(vc));
}

// Function to predict sell of all phones share same VC in the database from phonesfilename
// Predict sell = getTotalSellPriceUsingVC() + remaining unsold phones * sell price of the model
int predictSellUsingVC(char *vc)
{
    // Declare variables
    struct phoneModel model;
    struct phone p;
    int total = 0;
    int remaining = 0;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(modelsfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
    }

    // Loop through file
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        // Check if VC is equal to vc
        if (strcmp(model.vendercode, vc) == 0)
        {
            // Get remaining unsold phones
            remaining = countUnsoldPhonesUsingVC(vc);

            // Get sell price of the model
            int sellprice = model.sellprice;

            // Get total sell price using VC
            total = getTotalSellPriceUsingVC(vc);

            // Add remaining unsold phones * sell price of the model to total
            total += remaining * sellprice;
        }
    }

    // Close file
    fclose(fp);

    // Return total
    return total;
}

// Function to predict sell of all phones share same VC CLI
void predictSellUsingVCCLI()
{
    // Declare variables
    char vc[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // check if VC is exist
    if (!isVendorCodeExist(vc))
    {
        printf("Vendor Code not exist\n");
        return;
    }

    // Print predict sell using VC
    printf("Predict sell using VC %s: %d\n", vc, predictSellUsingVC(vc));
}

// Function to predict profit of all phones share same VC in the database from phonesfilename
// Predict profit = predictSellUsingVC() - getTotalPurchasePriceUsingVC()
int predictProfitUsingVC(char *vc)
{
    return predictSellUsingVC(vc) - getTotalPurchasePriceUsingVC(vc);
}

// Function to predict profit of all phones share same VC CLI
void predictProfitUsingVCCLI()
{
    // Declare variables
    char vc[32];

    // Get VC from user
    printf("Enter Vendor Code: ");
    scanf("%s", vc);

    // check if VC is exist
    if (!isVendorCodeExist(vc))
    {
        printf("Vendor Code not exist\n");
        return;
    }

    // Print predict profit using VC
    printf("Predict profit using VC %s: %d\n", vc, predictProfitUsingVC(vc));
}

// Function to predict sell of all phones in the database from phonesfilename
// Predict sell = getTotalSellPrice() + (remaining unsold phones * sell price of the model) of each VC
int predictSell()
{
    // Declare variables
    struct phoneModel model;
    struct phone p;
    int total = 0;
    int remaining = 0;
    FILE *fp;

    // Open file in read binary mode
    fp = fopen(modelsfilename, "rb");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
    }

    // Loop through file
    while (fread(&model, sizeof(struct phoneModel), 1, fp))
    {
        // Get remaining unsold phones
        remaining = countUnsoldPhonesUsingVC(model.vendercode);

        // Get sell price of the model
        int sellprice = model.sellprice;

        // Get total sell price using VC
        total = getTotalSellPriceUsingVC(model.vendercode);

        // Add remaining unsold phones * sell price of the model to total
        total += remaining * sellprice;
    }

    // Close file
    fclose(fp);

    // Return total
    return total;
}

// Function to predict sell of all phones CLI
void predictSellCLI()
{
    // Print predict sell
    printf("Predict sell: %d\n", predictSell());
}

// Function to predict profit of all phones in the database from phonesfilename
// Predict profit = predictSell() - getTotalPurchasePrice()
int predictProfit()
{
    return predictSell() - getTotalPurchasePrice();
}

// Function to predict profit of all phones CLI
void predictProfitCLI()
{
    // Print predict profit
    printf("Predict profit: %d\n", predictProfit());
}

#endif