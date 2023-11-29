#include <stdio.h>
#include <stdlib.h>

#include "files.h"
#include "addfunctions.h"
#include "findfunctions.h"
#include "editfunctions.h"
#include "sellphone.h"
// Function to ask user to enter any key to continue
void askToContinue() {
    printf("Press any key to continue...");
    getchar();
    getchar();
}

// Add Menu function
void addMenu() {
    int flag = 1;
    while (flag) {
        // provide a menu for the user
        printf("\n\n");
        printf("1. Add a phone\n");
        printf("2. Add a model\n");
        printf("3. Add a phone using .csv file\n");
        printf("4. Add a model using .csv file\n");
        printf("0. Exit to main menu\n");

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // process user input
        switch (choice) {
            case 1:
                addNewPhone();
                askToContinue();
                break;
            case 2:
                addNewModel();
                askToContinue();
                break;
            case 3:
                addNewPhoneCSV();
                askToContinue();
                break;
            case 4:
                addNewModelCSV();
                askToContinue();
                break;
            case 0:
                flag = 0;
            default:
                printf("Invalid choice\n");
                askToContinue();
                break;
        }

        // // pause and wait for user to press any key
        // printf("Press any key to continue...");
        // getchar();
        // getchar();
    }
}

// Edit Menu function
void editMenu() {
    int flag = 1;
    while (flag) {
        // provide a menu for the user
        printf("\n\n");
        printf("1. Remove a phone\n");
        printf("2. Remove a model using Vendor code\n");
        printf("3. Remove models using Model Number\n");
        printf("0. Exit to main menu\n");

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user input
        switch (choice) {
            case 1:
                removePhone();
                break;
            case 2:
                removeModelUsingVendorCode();
                break;
            case 3:
                removeModelUsingModelNumber();
                break;
            case 0:
                flag = 0;
            default:
                printf("Invalid choice\n");
                break;
        }

        // pause and wait for user to press any key
        printf("Press any key to continue...");
        getchar();
        getchar();
    }
}

// Main Menu function
void menu() {
    while (1) {
        // provide a menu for the user
        printf("\n\n");
        printf("1. Add Menu\n");
        printf("2. Edit Menu\n");
        printf("3. Print all Phone\n");
        printf("4. Print all Model\n");
        printf("5. Find a phone\n");
        printf("6. Find a model\n");
        printf("7. Sell Phone using SN\n");
        printf("8. \n");
        printf("9. \n");
        printf("0. Exit\n");

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user input
        switch (choice) {
            case 1:
                addMenu();
                break;
            case 2:
                editMenu();
                break;
            case 3:
                printAllPhones();
                break;
            case 4:
                printAllModels();
                break;
            case 5:
                FindPhoneusingSNInput();
                break;
            case 6:
                FindPhoneusingVCInput();
                break;
            case 7:
                sellPhoneCLI();
                break;
            case 8:
                
                break;
            case 9:
                
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }

        // pause and wait for user to press any key
        printf("Press any key to continue...");
        getchar();
        getchar();
    }
}