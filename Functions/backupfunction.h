#ifndef BACKUPFUNCTION_H
#define BACKUPFUNCTION_H

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "struct.h"
#include "files.h"
#include "dateandtimefunction.h"

// Function to check if the backup folder exist
void checkBackupFolder()
{
    // Check if the backup folder exist
    if (access("Backups", F_OK) == -1)
    {
        // Create the backup folder
        mkdir("Backups", 0777);
    }
}

// Function to create a backup of the users file
void createUsersBackup()
{
    // Get the current date and time
    time_t now = time(0);
    struct tm *timeinfo = localtime(&now);
    char datetime[64];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d-%H-%M-%S", timeinfo);

    // Create the backup file name
    char backupfilename[100];
    snprintf(backupfilename, sizeof(backupfilename), "Backups/%s-users-backup.csv", datetime);
    // Create the backup file
    FILE *backupfile = fopen(backupfilename, "w");
    if (backupfile != NULL)
    {
        // Write the database content to the backup file
        FILE *usersfile = fopen(usersfilename, "rb");
        if (usersfile != NULL)
        {
            struct user user;
            while (fread(&user, sizeof(struct user), 1, usersfile))
            {
                fprintf(backupfile, "%s,%s,%d\n", user.username, user.password, user.isadmin);
            }
            fclose(usersfile);
        }
        else
        {
            printf("Failed to open users file.\n");
        }

        // Close the backup file
        fclose(backupfile);
    }
    else
    {
        printf("Failed to create backup file.\n");
    }
}

// Function to create a backup of the phones file
void createPhonesBackup()
{
    // Get the current date and time
    time_t now = time(0);
    struct tm *timeinfo = localtime(&now);
    char datetime[20];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d-%H-%M-%S", timeinfo);

    // Create the backup file name
    char backupfilename[100];
    snprintf(backupfilename, sizeof(backupfilename), "Backups/%s-phones-backup.csv", datetime);

    // Create the backup file
    FILE *backupfile = fopen(backupfilename, "w");
    if (backupfile != NULL)
    {
        // Write the database content to the backup file
        FILE *phonesfile = fopen(phonesfilename, "rb");
        if (phonesfile != NULL)
        {
            struct phone phone;
            while (fread(&phone, sizeof(struct phone), 1, phonesfile))
            {
                fprintf(backupfile, "%s,%s,%s,%d,%d-%d-%d,%d:%d,%d,%d-%d-%d,%d:%d\n", phone.serialnumber, phone.modelnumber, phone.vendercode, phone.purchaseprice, phone.purchaseDT.year, phone.purchaseDT.month, phone.purchaseDT.day, phone.purchaseDT.hour, phone.purchaseDT.minute, phone.sellprice, phone.sellDT.year, phone.sellDT.month, phone.sellDT.day, phone.sellDT.hour, phone.sellDT.minute);
            }
            fclose(phonesfile);
        }
        else
        {
            printf("Failed to open phones file.\n");
        }

        // Close the backup file

        fclose(backupfile);
    }
    else
    {
        printf("Failed to create backup file.\n");
    }
}

// Function to create a backup of the models file
void createModelsBackup()
{
    // Get the current date and time
    time_t now = time(0);
    struct tm *timeinfo = localtime(&now);
    char datetime[20];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d-%H-%M-%S", timeinfo);

    // Create the backup file name
    char backupfilename[100];
    snprintf(backupfilename, sizeof(backupfilename), "Backups/%s-models-backup.csv", datetime);
    // Create the backup file
    FILE *backupfile = fopen(backupfilename, "w");
    if (backupfile != NULL)
    {
        // Write the database content to the backup file
        FILE *modelsfile = fopen(modelsfilename, "rb");
        if (modelsfile != NULL)
        {
            struct phoneModel model;
            while (fread(&model, sizeof(struct phoneModel), 1, modelsfile))
            {
                fprintf(backupfile, "%s,%s,%s,%s,%d,%s,%d\n", model.modelnumber, model.vendercode, model.manufacture, model.modelname, model.storage, model.coloroption, model.sellprice);
            }
            fclose(modelsfile);
        }
        else
        {
            printf("Failed to open models file.\n");
        }

        // Close the backup file
        fclose(backupfile);
    }
    else
    {
        printf("Failed to create backup file.\n");
    }
}

// On start backup
void OnStartBackup()
{
    // Check if the backup folder exist
    checkBackupFolder();

    // Create backups
    createUsersBackup();
    createPhonesBackup();
    createModelsBackup();
}

// Clear the backup folder
void clearBackupFolder()
{
    // Check if the backup folder exist
    checkBackupFolder();

    // Clear the backup folder
    char command[100];
    snprintf(command, sizeof(command), "rm -rf Backups/*");
    system(command);
}

#endif // BACKUPFUNCTION_H