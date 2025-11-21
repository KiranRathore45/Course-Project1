#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int id;
    char type[10];   // "Income" or "Expense"
    char category[30];
    float amount;
    float balanceAfter;
};

// Function to add a record
void addRecord(int id, const char *type, const char *category, float amount, float balance) {
    struct Record r;
    FILE *fp = fopen("budget.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    r.id = id;
    strcpy(r.type, type);
    strcpy(r.category, category);
    r.amount = amount;
    r.balanceAfter = balance;

    fwrite(&r, sizeof(r), 1, fp);
    fclose(fp);
}

// Display all records
void displayRecords() {
    struct Record r;
    FILE *fp = fopen("budget.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Budget Records ---\n");
    while (fread(&r, sizeof(r), 1, fp)) {
        printf("ID: %d | Type: %s | Category: %s | Amount: %.2f | Balance After: %.2f\n",
               r.id, r.type, r.category, r.amount, r.balanceAfter);
    }
    fclose(fp);
}

// Show summary (total income, expenses, balance)
void showSummary() {
    struct Record r;
    FILE *fp = fopen("budget.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    float totalIncome = 0, totalExpense = 0, finalBalance = 0;
    while (fread(&r, sizeof(r), 1, fp)) {
        if (strcmp(r.type, "Income") == 0)
            totalIncome += r.amount;
        else
            totalExpense += r.amount;
        finalBalance = r.balanceAfter;
    }
    fclose(fp);

    printf("\n--- Budget Summary ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Final Balance: %.2f\n", finalBalance);
}

int main() {
    int choice, id = 1;
    float balance = 0.0, amount;
    char category[30];

    do {
        printf("\n--- Budget Planning & Tracking System ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Records\n");
        printf("4. Show Summary\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income amount: ");
                scanf("%f", &amount);
                printf("Enter category (e.g., Salary, Bonus): ");
                scanf("%s", category);
                balance += amount;
                addRecord(id++, "Income", category, amount, balance);
                printf("Income added! Current Balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                printf("Enter category (e.g., Rent, Food): ");
                scanf("%s", category);
                if (amount > balance) {
                    printf("Insufficient balance!\n");
                } else {
                    balance -= amount;
                    addRecord(id++, "Expense", category, amount, balance);
                    printf("Expense added! Current Balance: %.2f\n", balance);
                }
                break;

            case 3:
                displayRecords();
                break;

            case 4:
                showSummary();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}