#include "myheader.h"
#include <stdio.h>
#include<string.h>

void withdrawMoney(){
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
                printf("Withdraw from %s's account\n", user.name);
                printf("Account Balance: %d\n", user.balance);
                printf("Enter amouont: ");
                int withdrawAmount;
                scanf("%d", &withdrawAmount);
                if (withdrawAmount > user.balance) {
                    setColor(RED);
                    puts("Insufficient balance\n");
                    resetColor();
                    return;
                }
                user.balance -= withdrawAmount;
                bank.total_balance -= withdrawAmount;
                updateBankInfo(bank.total_users, bank.total_balance, bank.password);
                puts("Money withdrawn successfully");
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
        puts("No account found");
        resetColor();
        remove("temp.txt");
        return;
    } else {
        remove("data.txt");
        rename("temp.txt", "data.txt");
    }
}
