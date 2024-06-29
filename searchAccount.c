#include "myheader.h"
#include <stdio.h>
#include<string.h>

void searchAccount(){
    FILE *fp = fopen("data.txt", "r");
    if (fp != NULL && !feof(fp)) {
        User user;
        setColor(BLUE);
        puts("Search Account");
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
                puts("User found");
                user_found = 1;
                printf("Ac no: %d\nName: %s\nAge: %d\nAc Type: %s\nBalance: %d\n", user.ac_no, user.name, user.age, user.ac_type, user.balance);
            }
        }
        fclose(fp);
        if (!user_found) {
            puts("No user found");
            return;
        }
    } else {
        puts("No database found\nPlease create accounts first");
        return;
    }
}