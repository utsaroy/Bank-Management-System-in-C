#include "myheader.h"
#include <stdio.h>
#include<string.h>

void depositMoney(){
    Bank bank;
    FILE *fp, *ftemp, *fb;
    fp = fopen("data.txt", "r");
    ftemp = fopen("temp.txt", "w");
    fb = fopen("bank.txt", "r");
    if (fp == NULL || ftemp == NULL || fb == NULL) {
        puts("Something went wrong");
        return;
    }
    fscanf(fb, "%d %d %s\n", &bank.total_users, &bank.total_balance, bank.password);
    User user;
    setColor(BLUE);
    puts("Deposit Money");
    drawLine(20);
    resetColor();
    printf("Enter account no: ");
    int ac_no;
    scanf("%d", &ac_no);
    int user_found = 0;
    while (!feof(fp)) {
            fscanf(fp, "%d:\n", &user.ac_no);
            fgets(user.name, 100, fp);
            user.name[strcspn(user.name, "\n")] = 0;
            fscanf(fp, "%d %s %d\n", &user.age, user.ac_type, &user.balance);
            if (ac_no == user.ac_no) {
                user_found = 1;
                printf("Deposit to %s's account\n", user.name);
                printf("Enter amouont: ");
                int depositAmount;
                scanf("%d", &depositAmount);
                user.balance += depositAmount;
                bank.total_balance += depositAmount;
                updateBankInfo(bank.total_users, bank.total_balance, bank.password);
                puts("Money deposited successfully\n");
                printf("%s's new balance is %d\n", user.name, user.balance);

                setColor(GREEN);
                printf("Press Enter to continue...");
                resetColor();
                fflush(stdin);
                getchar();
                clearScreen();
            }
            fprintf(ftemp, "%d:\n%s\n%d %s %d\n", user.ac_no, user.name, user.age, user.ac_type, user.balance);
    }
    fclose(fp);
    fclose(ftemp);
    if (!user_found) {
        setColor(RED);
        puts("No Account found\n");
        resetColor();
        remove("temp.txt");
        return;
    } else {
        remove("data.txt");
        rename("temp.txt", "data.txt");
    }
}