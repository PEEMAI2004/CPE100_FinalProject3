#include <stdio.h>
#include <stdlib.h>

#include "files.h"
#include "addfunctions.h"
#include "findfunctions.h"
#include "editfunctions.h"
#include "sellphone.h"
#include "usersystem.h"
#include "stock.h"
#include "printfunctions.h"
#include "backupfunction.h"

// Function to ask user to enter any key to continue
void askToContinue() {
    printf("Press Enter or Return to continue...");
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
        printf("4. Edit sell price using VC\n");
        printf("0. Exit to main menu\n");

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user input
        switch (choice) {
            case 1:
                removePhone();
                askToContinue();
                break;
            case 2:
                removeModelUsingVendorCode();
                askToContinue();
                break;
            case 3:
                removeModelUsingModelNumber();
                askToContinue();
                break;
            case 4:
                editModelSellPriceUsingVendorCode();
                askToContinue();
                break;
            case 0:
                flag = 0;
                break;
            default:
                printf("Invalid choice\n");
                askToContinue();
                break;
        }

        // pause and wait for user to press any key
        printf("Press any key to continue...");
        getchar();
        getchar();
    }
}

// Stock Menu function
void stockMenu() {
    int flag = 1;
    while (flag) {
        // provide a menu for the user
        printf("\n\n");
        printf("11. Count number of unsold phones using VC\n");
        printf("12. Count number of sold phones using VC\n");
        printf("13. Count number of all phones using VC\n");
        printf("21. Count number of all unsold phones\n");
        printf("22. Count number of all sold phones\n");
        printf("23. Count number of all phones\n");
        printf("31. Show total purchase of all phones\n");
        printf("32. Show total sell of all phones\n");
        printf("33. Show total profit of all phones\n");
        printf("41. Show total purchase of all phones using VC\n");
        printf("42. Show total sell of all phones using VC\n");
        printf("43. Show total profit of all phones using VC\n");
        printf("51. Predict Sell\n");
        printf("52. Predict Profit\n");
        printf("61. Predict Sell Using Vendor Code\n");
        printf("62. Predict Profit Using Vendor Code\n");
        printf("0. Exit to main menu\n");

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user input
        switch (choice) {
            case 11:
                countUnsoldPhonesUsingVCCLI();
                askToContinue();
                break;
            case 12:
                countSoldPhonesUsingVCCLI();
                askToContinue();
                break;
            case 13:
                countPhonesUsingVCCLI();
                askToContinue();
                break;
            case 21:
                countAllUnsoldPhonesCLI();
                askToContinue();
                break;
            case 22:
                countAllSoldPhonesCLI();
                askToContinue();
                break;
            case 23:
                countAllPhonesCLI();
                askToContinue();
                break;
            case 31:
                getTotalPurchasePriceCLI();
                askToContinue();
                break;
            case 32:
                getTotalSellPriceCLI();
                askToContinue();
                break;
            case 33:
                getTotalProfitCLI();
                askToContinue();
                break;
            case 41:
                getTotalPurchasePriceUsingVCCLI();
                askToContinue();
                break;
            case 42:
                getTotalSellPriceUsingVCCLI();
                askToContinue();
                break;
            case 43:
                getTotalProfitUsingVCCLI();
                askToContinue();
                break;
            case 51:
                predictSellCLI();
                askToContinue();
                break;
            case 52:
                predictProfitCLI();
                askToContinue();
                break;
            case 61:
                predictSellUsingVCCLI();
                askToContinue();
                break;
            case 62:
                predictProfitUsingVCCLI();
                askToContinue();
                break;
            case 0:
                flag = 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

// Find Menu function
void findMenu() {
    int flag = 1;
    while (flag) {
        // provide a menu for the user
        printf("\n\n");
        printf("1. Find a phone using Serial Number\n");
        printf("2. Find a phone using Vendor Code\n");
        printf("3. Find a phone using Model Number\n");
        printf("0. Exit to main menu\n");

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user input
        switch (choice) {
            case 1:
                FindPhoneusingSNInput();
                break;
            case 2:
                FindModelDatausingVCInput();
                break;
            case 3:
                FindModelDatausingMNInput();
                break;
            case 0:
                flag = 0;
                break;
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

// Admin Menu function
void adminMenu() {
    int flag = 1;
    while (flag) {
        // provide a menu for the user
        printf("\n\n");
        printf("1. Add a user\n");
        printf("2. Remove a user\n");
        printf("3. Change password\n");
        printf("4. List username\n");
        printf("5. List admin\n");
        printf("6. Grain Admin Permission\n");
        printf("7. Remove Admin Permission\n");
        printf("0. Exit to main menu\n");

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user input
        switch (choice) {
            case 1:
                createAccountCLI();
                break;
            case 2:
                deleteAccountCLI();
                break;
            case 3:
                changePasswordCLI();
                break;
            case 4:
                listAccount();
                break;
            case 5:
                listAdmin();
                break;
            case 6:
                grantAdminCLI();
                break;
            case 7:
                revokeAdminCLI();
                break;
            case 0:
                flag = 0;
                break;
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

// Print Menu function
void printMenu() {
    int flag = 1;
    while (flag) {
        // provide a menu for the user
        printf("\n\n");
        printf("1. Print all models\n");
        printf("2. Print all phones\n");
        printf("0. Exit to main menu\n");
        
        char choice;
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // process user input
        switch (choice) {
            case '1':
                printAllModels();
                break;
            case '2':
                printAllPhones();
                break;
            case '0':
                flag = 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

// Backup Menu function
void backupMenu() {
    checkBackupFolder();
    int flag = 1;
    while (flag) {
        // provide a menu for the user
        printf("\n\n");
        printf("1. Export users\n");
        printf("2. Export phones\n");
        printf("3. Export models\n");
        printf("4. Export all\n");
        printf("5. Clear Backups Path\n");
        printf("0. Exit to main menu\n");

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user input
        switch (choice) {
            case 1:
                createUsersBackup();
                break;
            case 2:
                createPhonesBackup();
                break;
            case 3:
                createModelsBackup();
                break;
            case 4:
                createUsersBackup();
                createPhonesBackup();
                createModelsBackup();
                break;
            case 5:
                clearBackupFolder();
                break;
            case 0:
                flag = 0;
                break;
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
void menu(bool isAdmin) {
    while (1) {
        // provide a menu for the user
        printf("\n\n");
        printf("1. Add Menu\n");
        printf("2. Edit Menu\n");
        printf("3. Find Menu\n");
        printf("4. Print Menu\n");
        printf("5. Stock Menu\n");
        printf("6. Blackup Menu\n");
        printf("7. About\n");
        printf("8. Sell Phone using SN\n");
        // Show admin menu if user is admin
        if (isAdmin) {
            printf("9. Admin Menu\n");
        }
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
                findMenu();
                break;
            case 4:
                printMenu();
                break;
            case 5:
                stockMenu();
                break;
            case 6:
                backupMenu();
                break;
            case 7:
                about();
                break;
            case 8:
                sellPhoneCLI();
                break;
            case 9:
                // Show admin menu if user is admin
                if (isAdmin) {
                    adminMenu();
                }
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
                askToContinue();
                break;
        }

        // pause and wait for user to press any key
        printf("Press any key to continue...");
        getchar();
        getchar();
    }
}