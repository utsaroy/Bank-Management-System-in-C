#include <stdio.h>
#include "myheader.h"

int main(){
    initialize();
    int opt;
    start:
    opt = chooseOption();
    if (opt == 1) createAccount();
    else if (opt == 2) depositMoney();
    else if (opt == 3) withdrawMoney();
    else if (opt == 4) viewAllAccounts();
    else if (opt == 5) searchAccount();
    else if (opt == 6) editAccount();
    else if (opt == 7) return 0;
    else {
        clearScreen();
        setColor(RED);
        printf("Invalid option\n");
        resetColor();
    }
    goto start;
}