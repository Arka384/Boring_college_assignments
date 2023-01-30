#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int accountNumber;
    char name[30];
    int balance;
}account;

void input(account *, int *);
void displayAllAccounts(account *, int );
void displayLowBalanceAccounts(account *, int );
void command(account *, int , int);
void deposit(account *, int );
void withdraw(account *, int );

int main()
{
    account bank[10];
    int n = 0,i,j,choice,temp;

    printf("\nEnter the number of account records: ");
    scanf("%d", &n);
    input(bank, &n);
    // displayAllAccounts(bank, n);
    // displayLowBalanceAccounts(bank, n);
    // command(bank, n, 0, 1234);
    // command(bank, n, 1, 1234);
    // displayAllAccounts(bank, n);

    while (1)
    {
        printf("\n1 -> display accounts with less than 1000 balance");
        printf("\n2 -> display all accounts");
        printf("\n3 -> withdraw");
        printf("\n4 -> Deposit");
        printf("\n5 -> Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayLowBalanceAccounts(bank, n);
            break;
        case 2:
            displayAllAccounts(bank, n);
            break;
        case 3:
            command(bank, n, 0);
            break;
        case 4:
            command(bank, n, 1);
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
    
    return 0;
}

void input(account *bank, int *size) {
    int i, n=0;
    // FILE *inputFile = fopen("input.txt", "r");
    // fscanf(inputFile, "%d", &n);
    // printf("n = %d", n);
    // *size = n;
    //printf("\nEnter account details");
    n = *size;
    for(i=0;i<n;i++) {
        printf("\nEnter data for accout %d", i+1);
        printf("\nEnter account number: ");
        scanf("%d", &bank[i].accountNumber);
        // fscanf(inputFile, "%d", &bank[i].accountNumber);
        printf("\nEnter holder's name: ");
        fflush(stdin);
        //fscanf(inputFile, "%s", &bank[i].name);
        gets(bank[i].name);
        printf("\nEnter balance: ");
        // fscanf(inputFile, "%d", &bank[i].balance);
        scanf("%d", &bank[i].balance);
    }
    // fclose(inputFile);
}

void command(account *bank, int size, int code) {
    int i=0, accNum = 0, flag = 0, amount;
    printf("\nEnter account number: ");
    scanf("%d", &accNum);
    printf("\nEnter amount: ");
    scanf("%d", &amount);

    for(i=0;i<size;i++) {
        if(bank[i].accountNumber == accNum) {
            flag = 1;
            if(code == 0)
                withdraw(&bank[i], amount);
            else
                deposit(&bank[i], amount);
        }
    }
    if(flag == 0)
        printf("\nInvalid account number given");
}

void deposit(account *acc, int amount) {
    acc->balance  = acc->balance + amount;
}

void withdraw(account *acc, int amount) {
    if(acc->balance < amount)
        printf("\nNot enough balance in account");
    else
        acc->balance  = acc->balance - amount;
}

void displayLowBalanceAccounts(account *bank, int size) {
    int i;
    printf("\nAll account with balance less than 1000 are: ");
    printf("\n==============================");
    for(i=0;i<size;i++) {
        if(bank[i].balance < 1000) {
            printf("\nAccount number: %d", bank[i].accountNumber);
            printf("\nHolder's name: ");
            fputs(bank[i].name, stdout);
            printf("\nBalance: %d", bank[i].balance);
        }
    }
    printf("\n");
}


void displayAllAccounts(account *bank, int size) {
    int i;
    printf("\nAll account details are: ");
    printf("\n==============================");
    for(i=0;i<size;i++) {
        printf("\nAccount number: %d", bank[i].accountNumber);
        printf("\nHolder's name: ");
        fputs(bank[i].name, stdout);
        printf("\nBalance: %d", bank[i].balance);
    }
    printf("\n");
}
