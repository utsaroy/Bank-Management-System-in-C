#include <stdio.h>
#include<string.h>
#include "myheader.h"

void setColor(int color) {
    printf("\033[1;%dm", color);
}
void resetColor() {
    printf("\033[0m");
}

void showErrorMessage() {
    setColor(RED);
    printf("Something went wrong\n");
    resetColor();
}

void clearScreen() {
    //printf("\033[2J");
    //printf("\033[0;0f");
    printf("\033c");
    printf("\t ");
    setColor(MAGENTA);
    drawLine(30);
    printf("\t|    Bank Management System    |\n\t|");
    for (int i = 0; i < 30; i++) printf("_");
    printf("|\n\n\n");
    resetColor();

}

void drawLine(int n) {
    for (int i = 0; i < n; i++) {
        printf("_");
    }
    printf("\n");
}

int chooseOption(){
    setColor(BLUE);
    drawLine(30);
    printf("\nChoose Option\n");
    drawLine(30);
    setColor(GREEN);
    puts("1. New Account");
    puts("2. Deposit Money");
    puts("3. Withdraw Money");
    puts("4. View All Accounts");
    puts("5. Search Account");
    puts("6. Edit Account");
    puts("7. Quit");
    setColor(CYAN);
    drawLine(30);
    printf("Enter opt no: ");
    int n;
    fflush(stdin);
    scanf("%d", &n);
    resetColor();
    clearScreen();
    return n;
}
void initialize(){
    clearScreen();
    Bank bank;
    FILE *fp = fopen("bank.txt", "r");
    if (fp != NULL && fgetc(fp) != EOF) {
        rewind(fp);
        again:
        setColor(GREEN);
        printf("Enter password: ");
        resetColor();
        char password[100];
        fscanf(fp, "%d %d %s\n", &bank.total_users, &bank.total_balance, bank.password);
        scanf("%s", password);
        if (strcmp(password, bank.password) != 0) {
            clearScreen();
            setColor(RED);
            printf("Wrong password\n");
            goto again;
            fclose(fp);
        }
        fclose(fp);
        clearScreen();
    } else {
        fp = fopen("bank.txt", "w");
        if (fp == NULL) {
            setColor(RED);
            printf("Something went wrong\n");
            resetColor();
            return;
        }
        puts("Set a Password first");
        setColor(BLUE);
        printf("Enter Password(No spaces): ");
        setColor(GREEN);
        scanf("%s", bank.password);
        resetColor();
        if (strlen(bank.password) < 2) {
            setColor(RED);
            puts("Please set a valid password\n");
            resetColor();
            initialize();
        }
        bank.total_users = 0;
        bank.total_balance = 0;
        fprintf(fp, "%d %d %s\n", bank.total_users, bank.total_balance, bank.password);
        fclose(fp);
        clearScreen();
    }
}

void updateBankInfo(int total_users, int total_balance, char password[100]){
    FILE* fp = fopen("bank.txt", "w");
    if (fp == NULL) {
        puts("Something went wrong");
    }
    fprintf(fp, "%d %d %s", total_users, total_balance, password);
    fclose(fp);
}