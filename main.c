#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Functions/menu.h"
#include "Functions/usersystem.h"
#include "Functions/stock.h"

int main()
{   
    // Check if userdata.bin exist
    initializeUserdata();

    // Login
    bool isadmin = login();

    // Notify low stock
    ShowUnsoldVCthatLessthanOnStart();

    // Menu
    menu(isadmin);
    
}