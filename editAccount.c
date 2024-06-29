#include "myheader.h"
#include <stdio.h>
#include<string.h>

void editAccount(){
    FILE *fp, *ftemp;
    fp = fopen("data.txt", "r");
    ftemp = fopen("temp.txt", "w");
    if (fp == NULL || ftemp == NULL) {
        puts("Something went wrong");
        return;
    }
    User user;
    setColor(BLUE);
    puts("Edit Account");
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
                printf("Edit %s's account\n", user.name);
                fflush(stdin);
                printf("Enter new name: ");
                gets(user.name);
                printf("Enter new age: ");
                scanf("%d", &user.age);
                setColor(BLUE);
                puts("Account Type:");
                setColor(GREEN);
                puts("1. Savings\n2. Current");
                resetColor();
                int x;
                scanf("%d", &x);
                if (x == 1) strcpy(user.ac_type, "savings");
                else if (x == 2) strcpy(user.ac_type, "current");
                else {
                    showErrorMessage();
                    remove("temp.txt");
                    return;
                }
            }
            fprintf(ftemp, "%d:\n%s\n%d %s %d\n", user.ac_no, user.name, user.age, user.ac_type, user.balance);
    }
    fclose(fp);
    fclose(ftemp);
    if (!user_found) {
        puts("No user found");
        remove("temp.txt");
        return;
    } else {
        remove("data.txt");
        rename("temp.txt", "data.txt");
        puts("Account edited successfully");
    }
}