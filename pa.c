#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "budget_data.txt"

typedef struct {
    char type[10];      // "Income" or "Expense"
    char category[30];
    float amount;
} Record;

void addRecord();
void viewRecords();
void calculateBalance();

int main() {
    int choice;

    while (1) {
        printf("\n===== BUDGET PLANNING & TRACKING SYSTEM =====\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View All Records\n");
        printf("4. Calculate Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear buffer

        switch (choice) {
            case 1:
            case 2:
                addRecord(choice);
                break;
            case 3:
                viewRecords();
                break;
            case 4:
                calculateBalance();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void addRecord(int typeChoice) {
    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    Record r;
    if (typeChoice == 1)
        strcpy(r.type, "Income");
    else
        strcpy(r.type, "Expense");

    printf("Enter category: ");
    scanf("%s", r.category);

    printf("Enter amount: ");
    scanf("%f", &r.amount);

    fprintf(fp, "%s %s %.2f\n", r.type, r.category, r.amount);
    fclose(fp);

    printf("%s added successfully!\n", r.type);
}

void viewRecords() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Record r;

    printf("\n======= ALL RECORDS =======\n");
    while (fscanf(fp, "%s %s %f", r.type, r.category, &r.amount) != EOF) {
        printf("%s | Category: %s | Amount: %.2f\n", r.type, r.category, r.amount);
    }
    fclose(fp);
}

void calculateBalance() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Record r;
    float income = 0, expense = 0;

    while (fscanf(fp, "%s %s %f", r.type, r.category, &r.amount) != EOF) {
        if (strcmp(r.type, "Income") == 0)
            income += r.amount;
        else
            expense += r.amount;
    }
    fclose(fp);

    printf("\n===== BALANCE SUMMARY =====\n");
    printf("Total Income:  %.2f\n", income);
    printf("Total Expense: %.2f\n", expense);
    printf("Remaining Balance: %.2f\n", income - expense);
}
