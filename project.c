#include <stdio.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_ENTRIES 365

int main() {
    char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH];
    int num_entries = 0;
    char command[10];

    printf("Welcome to your personal daily diary!\n");

    while (1) {
        printf("\nPlease enter a command (ADD, LIST or QUIT): ");
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            if (num_entries == MAX_ENTRIES) {
                printf("Sorry, your diary is full.\n");
            } else {
                char entry[MAX_ENTRY_LENGTH];
                printf("Please enter your diary entry:\n");
                getchar();  // consume newline character
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                strcpy(entries[num_entries], entry);
                num_entries++;
                printf("Entry added.\n");
            }
        } else if (strcmp(command, "LIST") == 0) {
            printf("Your diary entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%d. %s", i + 1, entries[i]);
            }
        } else if (strcmp(command, "QUIT") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}
