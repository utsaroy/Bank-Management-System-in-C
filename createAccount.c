#include "myheader.h"
#include <stdio.h>
#include<string.h>

void createAccount(){
    Bank bank;
    FILE *fb = fopen("bank.txt", "r");
    FILE *fp = fopen("data.txt", "a");
    if (fb != NULL && fgetc(fb) != EOF) {
        rewind(fb);
        fscanf(fb, "%d %d %s", &bank.total_users, &bank.total_balance, bank.password);
    } else {
        showErrorMessage();
        return;
    }
    if (fp == NULL) {
        showErrorMessage();
        return;
    }
    User new_user;
    fflush(stdin);
    setColor(BLUE);
    puts("Enter Details");
    resetColor();
    printf("Name: ");
    gets(new_user.name);
    printf("Age: ");
    scanf("%d", &new_user.age);
    setColor(BLUE);
    printf("Account Type:\n");
    setColor(GREEN);
    puts("1. Savings\n2. Current");
    resetColor();
    printf("Enter opt no: ");
    int x;
    scanf("%d", &x);
    if (x == 1) strcpy(new_user.ac_type, "savings");
    else if (x == 2) strcpy(new_user.ac_type, "current");
    else {
        clearScreen();
        showErrorMessage();
        return;
    }
    printf("Deposit amount: ");
    scanf("%d", &new_user.balance);
    new_user.ac_no = bank.total_users++ + 1111;
    bank.total_balance += new_user.balance;
    fprintf(fp, "%d:\n%s\n%d %s %d\n", new_user.ac_no, new_user.name, new_user.age, new_user.ac_type, new_user.balance);
    printf("Account created for : ");
    setColor(GREEN);
    printf("%s\n", new_user.name);
    resetColor();
    printf("Balance: ");
    setColor(GREEN);
    printf("%d\n", new_user.balance);
    resetColor();
    printf("%s's account number is: ", new_user.name);
    setColor(GREEN);
    printf("%d\n", new_user.ac_no);
    resetColor();
    updateBankInfo(bank.total_users, bank.total_balance, bank.password);
    fclose(fp);
    fclose(fb);
    setColor(GREEN);
    printf("\n\nPress enter to continue...");
    resetColor();
    fflush(stdin);
    getchar();
    clearScreen();
    return;
}
