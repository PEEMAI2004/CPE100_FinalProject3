#ifndef USERSYSTEM_H
#define USERSYSTEM_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "struct.h"
#include "files.h"

int checkExist(char* username);

// Function to encrypt a file, using saiting and hashing method
void encryptFile(const char* filename, const char* key) {
    // Open the input file
    FILE* inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return;
    }

    // Create the output file
    char outputFilename[100];
    sprintf(outputFilename, "%s.encrypted", filename);
    FILE* outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        printf("Error creating the output file.\n");
        fclose(inputFile);
        return;
    }

    // Get the size of the input file
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // Read the input file into a buffer
    unsigned char* buffer = (unsigned char*)malloc(fileSize);
    fread(buffer, 1, fileSize, inputFile);

    // Encrypt the buffer using the key
    for (int i = 0; i < fileSize; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, 1, fileSize, outputFile);

    // Clean up
    free(buffer);
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully.\n");
}

// Function to decrypt a file, using saiting and hashing method
void decryptFile(const char* filename, const char* key) {
    // Open the input file
    FILE* inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return;
    }

    // Create the output file
    char outputFilename[100];
    sprintf(outputFilename, "%s.decrypted", filename);
    FILE* outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        printf("Error creating the output file.\n");
        fclose(inputFile);
        return;
    }

    // Get the size of the input file
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // Read the input file into a buffer
    unsigned char* buffer = (unsigned char*)malloc(fileSize);
    fread(buffer, 1, fileSize, inputFile);

    // Decrypt the buffer using the key
    for (int i = 0; i < fileSize; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, 1, fileSize, outputFile);

    // Clean up
    free(buffer);
    fclose(inputFile);
    fclose(outputFile);

    printf("File decrypted successfully.\n");
}

// Function create account with username and password to file userdata.bin, default isnot admin, use struct user
void createAccount(char* username, char* password) {
    FILE* f = fopen("userdata.bin", "ab");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    strcpy(u.username, username);
    strcpy(u.password, password);
    u.isadmin = false;
    fwrite(&u, sizeof(struct user), 1, f);
    fclose(f);
}

// Function to create account from CLI with username and password, use function checkExist and createAccount
void createAccountCLI() {
    char username[100];
    char password1[100];
    char password2[100];
    bool created = false;
    while (!created) {
        printf("Username: ");
        scanf("%s", username);
        if (checkExist(username)) {
            printf("Username already exist. Please try again.\n");
        } else {
            // loop until password1 == password2
            while (true) {
                printf("Password: ");
                scanf("%s", password1);
                printf("Confirm password: ");
                scanf("%s", password2);
                if (strcmp(password1, password2) == 0) {
                    int passwordLength = strlen(password1);
                    if (passwordLength >= 8) {
                        if (passwordLength <= 64) {
                            createAccount(username, password1);
                            printf("Account created successfully.\n");
                            created = true;
                            break;
                        } else {
                            printf("Password length exceeds the maximum limit. Please try again.\n");
                        }
                    } else {
                        printf("Password length does not meet the minimum requirement. Please try again.\n");
                    }
                } else {
                    printf("Password does not match. Please try again.\n");
                }
            }
            created = true;
        }
    }
}

// Function to check if username and password is correct, use struct user
bool checkAccount(char* username, char* password) {
    FILE* f = fopen("userdata.bin", "rb");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    while (fread(&u, sizeof(struct user), 1, f)) {
        if (strcmp(u.username, username) == 0 && strcmp(u.password, password) == 0) {
            fclose(f);
            return true;
        }
    }
    fclose(f);
    return false;
}

// Function to check if username is admin, use struct user
bool checkAdmin(char* username) {
    FILE* f = fopen("userdata.bin", "rb");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    while (fread(&u, sizeof(struct user), 1, f)) {
        if (strcmp(u.username, username) == 0 && u.isadmin == true) {
            fclose(f);
            return true;
        }
    }
    fclose(f);
    return false;
}

// Function to change password, use struct user
void changePassword(char* username, char* password) {
    FILE* f = fopen("userdata.bin", "rb+");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    while (fread(&u, sizeof(struct user), 1, f)) {
        if (strcmp(u.username, username) == 0) {
            strcpy(u.password, password);
            fseek(f, -sizeof(struct user), SEEK_CUR);
            fwrite(&u, sizeof(struct user), 1, f);
            break;
        }
    }
    fclose(f);
}

// Function to change password from CLI with username and password, use function checkAccount and changePassword
// Enter username and current password, if username and password is correct, enter new password and confirm password
void changePasswordCLI() {
    char username[100];
    char password1[100];
    char password2[100];
    bool changed = false;
    while (!changed) {
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password1);
        if (checkAccount(username, password1)) {
            // loop until password1 == password2
            while (true) {
                printf("New password: ");
                scanf("%s", password1);
                printf("Confirm new password: ");
                scanf("%s", password2);
                if (strcmp(password1, password2) == 0) {
                    int passwordLength = strlen(password1);
                    if (passwordLength >= 8) {
                        if (passwordLength <= 64) {
                            changePassword(username, password1);
                            printf("Password changed successfully.\n");
                            changed = true;
                            break;
                        } else {
                            printf("Password length exceeds the maximum limit. Please try again.\n");
                        }
                    } else {
                        printf("Password length does not meet the minimum requirement. Please try again.\n");
                    }
                } else {
                    printf("Password does not match. Please try again.\n");
                }
            }
        } else {
            printf("Username or password is incorrect. Please try again.\n");
        }
    }
}

// Function to grain admin, use struct user
void grantAdmin(char* username) {
    FILE* f = fopen("userdata.bin", "rb+");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    while (fread(&u, sizeof(struct user), 1, f)) {
        if (strcmp(u.username, username) == 0) {
            u.isadmin = true;
            fseek(f, -sizeof(struct user), SEEK_CUR);
            fwrite(&u, sizeof(struct user), 1, f);
            break;
        }
    }
    fclose(f);
}

// Function to grant admin from CLI with username, check if current user is admin, use function checkAdmin and grantAdmin
void grantAdminCLI() {
    char username[100];
    bool granted = false;
    while (!granted) {
        printf("Username: ");
        scanf("%s", username);
        if (checkAdmin(username)) {
            printf("User is already admin.\n");
        } else {
            grantAdmin(username);
            printf("User granted admin successfully.\n");
            granted = true;
        }
    }
}

// Function to revoke admin, use struct user
void revokeAdmin(char* username) {
    FILE* f = fopen("userdata.bin", "rb+");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    while (fread(&u, sizeof(struct user), 1, f)) {
        if (strcmp(u.username, username) == 0) {
            u.isadmin = false;
            fseek(f, -sizeof(struct user), SEEK_CUR);
            fwrite(&u, sizeof(struct user), 1, f);
            break;
        }
    }
    fclose(f);
}

// Function to revoke admin from CLI with username, check if current user is admin, use function checkAdmin and revokeAdmin
void revokeAdminCLI() {
    char username[100];
    bool revoked = false;
    while (!revoked) {
        printf("Username: ");
        scanf("%s", username);
        if (checkAdmin(username)) {
            revokeAdmin(username);
            printf("User revoked admin successfully.\n");
            revoked = true;
        } else {
            printf("User is not admin.\n");
        }
    }
}

// Function to delete account, use struct user
void deleteAccount(char* username) {
    FILE* f = fopen("userdata.bin", "rb+");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    while (fread(&u, sizeof(struct user), 1, f)) {
        if (strcmp(u.username, username) == 0) {
            u.isadmin = false;
            fseek(f, -sizeof(struct user), SEEK_CUR);
            fwrite(&u, sizeof(struct user), 1, f);
            break;
        }
    }
    fclose(f);
}

// Function to delete account from CLI with username, check if current user is admin, use function checkAdmin and deleteAccount
void deleteAccountCLI() {
    char username[100];
    bool deleted = false;
    while (!deleted) {
        printf("Username: ");
        scanf("%s", username);
        if (checkAdmin(username)) {
            printf("Cannot delete admin account.\n");
        } else {
            deleteAccount(username);
            printf("Account deleted successfully.\n");
            deleted = true;
        }
    }
}

// Function to check if username is exist, use struct user
int checkExist(char* username) {
    FILE* f = fopen("userdata.bin", "rb");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    while (fread(&u, sizeof(struct user), 1, f)) {
        if (strcmp(u.username, username) == 0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

// Function to list all account, use struct user
void listAccount() {
    FILE* f = fopen("userdata.bin", "rb");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    printf("Username\tAdmin\n");
    while (fread(&u, sizeof(struct user), 1, f)) {
        printf("%s\t\t", u.username);
        if (u.isadmin) {
            printf("Admin\n");
        } else {
            printf("User\n");
        }
    }
    fclose(f);
}

// Function to list all admin account, use struct user
void listAdmin() {
    FILE* f = fopen("userdata.bin", "rb");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct user u;
    printf("Username\tAdmin\n");
    while (fread(&u, sizeof(struct user), 1, f)) {
        if (u.isadmin) {
            printf("%s\t\tAdmin\n", u.username);
        }
    }
    fclose(f);
}

// Function to login from CLI with username and password, use function checkAccount
bool login() {
    // define global variable isadmin
    extern bool isadmin;
    char username[100];
    char password[100];
    bool loggedIn = false;
    while (!loggedIn) {
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        if (checkAccount(username, password)) {
            printf("Login successfully.\n");
            loggedIn = true;
            // check if user is admin
            if (checkAdmin(username)) {
                printf("Welcome %s (Admin).\n", username);
                // define global variable isadmin
                return true;
            } else {
                printf("Welcome %s.\n", username);
                // define global variable isadmin
                return false;
            }
        } else {
            printf("Login failed. Please try again.\n");
        }
    }
}

// Function to check if userdata.bin is exist
bool checkUserdataExist() {
    FILE* f = fopen("userdata.bin", "rb");
    if (f == NULL) {
        return false;
    }
    fclose(f);
    return true;
}

// Function to create userdata.bin if not exist, with default admin account and user input password
void initializeUserdata() {
    if (!checkUserdataExist()) {
        // ask for password until password1 == password2
        char password1[100];
        char password2[100];
        while (true) {
            printf("Enter password for default admin account: ");
            scanf("%s", password1);
            printf("Confirm password: ");
            scanf("%s", password2);
            if (strcmp(password1, password2) == 0) {
                int passwordLength = strlen(password1);
                if (passwordLength >= 8) {
                    if (passwordLength <= 64) {
                        createAccount("admin", password1);
                        // grant admin
                        grantAdmin("admin");
                        printf("userdata.bin created successfully.\n");
                        break;
                    } else {
                        printf("Password length exceeds the maximum limit. Please try again.\n");
                    }
                } else {
                    printf("Password length does not meet the minimum requirement. Please try again.\n");
                }
            } else {
                printf("Password does not match. Please try again.\n");
            }
        }
        createAccount("admin", password1);
        printf("userdata.bin created successfully.\n");
        printf("admin account created with your password\n");
        printf("Exit the Progran\n");
        exit(0);
    }
}

#endif // !USERSYSTEM_H