#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Functions/menu.h"
#include "Functions/usersystem.h"
#include "Functions/stock.h"
#include "Functions/backupfunction.h"

int main()
{     
    // Check if userdata.bin exist
    initializeUserdata();

    // Login
    bool isadmin = login();

    // Print welcome message
    printf("\nPhone Shop Stock Management System (V3.0)\n");

    // Notify low stock
    ShowUnsoldVCthatLessthanOnStart();

    // Menu
    menu(isadmin);
    
} 