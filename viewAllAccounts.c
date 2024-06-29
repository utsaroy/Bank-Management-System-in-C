#include "myheader.h"
#include <stdio.h>
#include<string.h>

void viewAllAccounts(){
    FILE *fp = fopen("data.txt", "r");
    if (fp != NULL && getc(fp) != EOF) {
        rewind(fp);
        User user;
        setColor(BLUE);
        printf("Ac No\t%-20s\tAge\tAc Type\t\tBalance\n", "Name");
        drawLine(65);
        resetColor();
        while (!feof(fp)) {
            fscanf(fp, "%d:\n", &user.ac_no);
            fgets(user.name, 100, fp);
            user.name[strcspn(user.name, "\n")] = 0;
            fscanf(fp, "%d %s %d\n", &user.age, user.ac_type, &user.balance);
            printf("%d\t%-20s\t%d\t%s\t\t%d\n", user.ac_no, user.name, user.age, user.ac_type, user.balance);
        }
        fclose(fp);
        setColor(GREEN);
        printf("\nEnter any key to continue...");
        resetColor();
        fflush(stdin);
        getchar();
        clearScreen();
        return;
    } else {
        setColor(RED);
        puts("No account found\nPlease add accounts first");
        resetColor();
        return;
    }

}