#include <stdio.h>
#include<string.h>


#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 0

typedef struct {
    char name[100];
    int age;
    char ac_type[10]; //savings, current
    int balance;
    int ac_no;
} User;

typedef struct {
    int total_users;
    int total_balance;
    char password[100];
} Bank;


void initialize();
void createAccount();
void viewAllAccounts();
void depositMoney();
void withdrawMoney();
void searchAccount();
int chooseOption();
void updateBankInfo();
void editAccount();

void setColor(int color);
void resetColor();
void clearScreen();
void drawLine(int n);
void showErrorMessage();


