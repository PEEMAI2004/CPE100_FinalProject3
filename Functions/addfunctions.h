#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "dateandtimefunction.h"
#include "findfunctions.h"
#include "validcheck.h"

// Function to add new model via CLI to the database
void addNewModel()
{
    // Declare variables
    struct phoneModel model;
    FILE *fp;

    // Get model details from user
    printf("Enter Model Number: ");
    scanf("%s", model.modelnumber);
    printf("Enter Vendor Code: ");
    scanf("%s", model.vendercode);
    // Check if VC exist, if exist ask user to enter another VC because VC is unique
    while (isModelNumberExist(model.vendercode))
    {
        printf("Vendor Code already exists, please enter another Vendor Code: ");
        scanf("%s", model.vendercode);
    }
    printf("Enter Manufacture: ");
    scanf("%s", model.manufacture);
    printf("Enter Model Name: ");
    scanf("%s", model.modelname);
    printf("Enter Storage: ");
    scanf("%d", &model.storage);
    printf("Enter Color Option: ");
    scanf("%s", model.coloroption);
    printf("Enter Sell Price: ");
    scanf("%d", &model.sellprice);

    // Open file in append binary mode
    fp = fopen(modelsfilename, "ab");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Write model to file
    fwrite(&model, sizeof(struct phoneModel), 1, fp);

    // Close file
    fclose(fp);
}

// Function to add new model using .csv file to the database
// user have to enter the path of the .csv file
// structure of .csv file is Model-Number,Vendor-Code,Manufacturer,Model-Name,Storage,Color,Sell-Price
void addNewModelCSV() {
    // Declare variables
    char filepath[100];
    FILE *fp;

    // Get file path from user
    printf("Enter the path of the .csv file: ");
    scanf("%s", filepath);

    // Open file in read mode
    fp = fopen(filepath, "r");

    // Check if file is opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Read and process each line in the .csv file
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Declare variables
        struct phoneModel model;

        // Tokenize the line using comma as the delimiter
        char *token = strtok(line, ",");
        int i = 0;

        // Extract data from each token
        while (token != NULL) {
            switch (i) {
                case 0:
                    strcpy(model.modelnumber, token);
                    break;
                case 1:
                    strcpy(model.vendercode, token);
                    break;
                case 2:
                    strcpy(model.manufacture, token);
                    break;
                case 3:
                    strcpy(model.modelname, token);
                    break;
                case 4:
                    model.storage = atoi(token);
                    break;
                case 5:
                    strcpy(model.coloroption, token);
                    break;
                case 6:
                    model.sellprice = atoi(token);
                    break;
            }
            token = strtok(NULL, ",");
            i++;
        }

        // Open file in append binary mode
        FILE *modelFile = fopen(modelsfilename, "ab");

        // Check if file is opened successfully
        if (modelFile == NULL) {
            printf("Error opening file\n");
            return;
        }

        // Write model to file
        fwrite(&model, sizeof(struct phoneModel), 1, modelFile);

        // Close file
        fclose(modelFile);
    }

    // Close .csv file
    fclose(fp);
}

// Function to add new phone via CLI to the database
// Only Serial-Number,Vendor-Code,Purchase-Price
// Add Model-Number automatically using FindModelusingVC() function
// Add Date and Time automatically using getCurrentDateTime() function
void addNewPhone()
{
    // Declare variables
    struct phone phone;
    FILE *fp;

    // Get phone details from user
    printf("Enter Serial Number: ");
    scanf("%s", phone.serialnumber);
    
    printf("Enter Vendor Code: ");
    scanf("%s", phone.vendercode);
    
    printf("Enter Purchase Price: ");
    scanf("%d", &phone.purchaseprice);

    // Find model number using FindModelusingVC function
    strcpy(phone.modelnumber, FindModelusingVC(phone.vendercode));

    // Get current date and time
    struct Dateandtime dt = getCurrentDateTime();

    // Copy date and time to phone struct
    phone.purchaseDT.year = dt.year;
    phone.purchaseDT.month = dt.month;
    phone.purchaseDT.day = dt.day;
    phone.purchaseDT.hour = dt.hour;
    phone.purchaseDT.minute = dt.minute;

    // Open file in append binary mode
    fp = fopen(phonesfilename, "ab");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Write null to data that is not entered by user
    phone.sellprice = 0;
    phone.sellDT.year = 0;
    phone.sellDT.month = 0;
    phone.sellDT.day = 0;
    phone.sellDT.hour = 0;
    phone.sellDT.minute = 0;
    phone.sold = 0;


    // Write phone to file
    fwrite(&phone, sizeof(struct phone), 1, fp);

    // Close file
    fclose(fp);
}

// Function to add new phone using .csv file to the database
// user have to enter the path of the .csv file
// structure of .csv file is Serial-Number,Model-Number,Vendor-Code,Purchase-Price
// Add Date and Time automatically using getCurrentDateTime() function
void addNewPhoneCSV()
{
    // Declare variables
    struct phone phone;
    FILE *fp;

    // Ask for the path of the .csv file
    char csvFilePath[100];
    printf("Enter the path of the .csv file: ");
    scanf("%s", csvFilePath);

    // Open .csv file
    fp = fopen(csvFilePath, "r");

    // Check if file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Read each line from .csv file
    char line[100];
    while (fgets(line, sizeof(line), fp))
    {
        // Tokenize the line using comma as delimiter
        char* token = strtok(line, ",");
        int i = 1;

        // Parse each token and assign it to the corresponding field in phone struct
        while (token != NULL)
        {
            switch (i)
            {
                case 1:
                    strcpy(phone.serialnumber, token);
                    break;
                case 2:
                    strcpy(phone.modelnumber, token);
                    break;
                case 3:
                    strcpy(phone.vendercode, token);
                    break;
                case 4:
                    phone.purchaseprice = atoi(token);
                    break;
            }
            token = strtok(NULL, ",");
            i++;
        }

        // Get current date and time
        struct Dateandtime dt = getCurrentDateTime();

        // Copy date and time to phone struct
        phone.purchaseDT.year = dt.year;
        phone.purchaseDT.month = dt.month;
        phone.purchaseDT.day = dt.day;
        phone.purchaseDT.hour = dt.hour;
        phone.purchaseDT.minute = dt.minute;

        // Write null to data that is not entered in .csv file
        phone.sellprice = 0;
        phone.sellDT.year = 0;
        phone.sellDT.month = 0;
        phone.sellDT.day = 0;
        phone.sellDT.hour = 0;
        phone.sellDT.minute = 0;

        // Open file in append binary mode
        FILE *phoneFile = fopen(phonesfilename, "ab");

        // Check if file is opened successfully
        if (phoneFile == NULL) {
            printf("Error opening file\n");
            return;
        }

        // Write phone to file
        fwrite(&phone, sizeof(struct phone), 1, phoneFile);

        // Close file
        fclose(phoneFile);
    }

    // Close .csv file
    fclose(fp);
}
