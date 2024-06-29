output: main.o createAccount.o depositMoney.o editAccount.o searchAccount.o viewAllAccounts.o withdrawMoney.o functions.o
	gcc -o output main.o createAccount.o depositMoney.o editAccount.o searchAccount.o viewAllAccounts.o withdrawMoney.o functions.o
main.o: main.c
	gcc -c main.c
createAccount.o: createAccount.c
	gcc -c createAccount.c
depositMoney.o: depositMoney.c
	gcc -c depositMoney.c
editAccount.o: editAccount.c
	gcc -c editAccount.c
searchAccount.o: searchAccount.c
	gcc -c searchAccount.c
viewAllAccounts.o: viewAllAccounts.c
	gcc -c viewAllAccounts.c
withdrawMoney.o: withdrawMoney.c
	gcc -c withdrawMoney.c
functions.o: functions.c
	gcc -c functions.c
clean:
	del *.o