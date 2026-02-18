#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>

//DATA STRUCTURE:
typedef struct {
    char website[50];
    char username[50];
    char password[50];
} VaultEntry;

// Function Prototypes
void displayHeader();
void addEntry();
void viewEntries();
void searchEntry();

int main() {
    int choice;

    while(1) {
        displayHeader();
        printf("1. Add New Credential\n");
        printf("2. View All Saved (Binary Read)\n");
        printf("3. Search for a Website\n");
        printf("4. Exit\n");
        printf("\nEnter Choice: ");

        if (scanf("%d", &choice) != 1) {
            // Error handling for non-integer input
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printf("\nExiting C-Krypt. Goodbye!\n");
                exit(0);
            default:
                printf("\n[!] Invalid Choice.\n");
        }
        printf("\n--Process Finished. Press Enter to return to menu--");
        getchar();
        getchar(); // Pause the screen
    }
    return 0;
}

void displayHeader() {
    system("cls"); // Clears the terminal for a clean UI
    printf("=========================================\n");
    printf("          C-KRYPT: BINARY VAULT          \n");
    printf("       Secure Data Persistence in C      \n");
    printf("=========================================\n");
}

void addEntry() {
    VaultEntry entry;
    FILE *fp = fopen("vault.dat", "ab");

    if (fp==NULL) {
        printf("[!] Error: Could not open file.\n");
        return;
    }

    printf("\n--- Adding New Entry ---\n");
    printf("Website: ");
    scanf("%s", entry.website);
    printf("Username: ");
    scanf("%s", entry.username);
    printf("Password: ");
    scanf("%s", entry.password);

    // fwrite writes the entire struct block to the file at once
    fwrite(&entry, sizeof(VaultEntry), 1, fp);
    fclose(fp);
    printf("\n[SUCCESS] Entry locked in vault.dat\n");
}

void viewEntries() {
    VaultEntry entry;
    FILE *fp = fopen("vault.dat", "rb"); // 'rb' for Read Binary

    if (fp==NULL) {
        printf("\n[!] Vault is empty. Add a record first.\n");
        return;
    }

    printf("\n%-20s %-20s %-20s\n", "Website", "Username", "Password");
    printf("------------------------------------------------------------\n");

    // fread reads until the end of the file
    while(fread(&entry, sizeof(VaultEntry), 1, fp)) {
        printf("%-20s %-20s %-20s\n", entry.website, entry.username, entry.password);
    }
    fclose(fp);
}

void searchEntry() {
    VaultEntry entry;
    char target[50];
    int found = 0;
    FILE *fp = fopen("vault.dat", "rb");

    if (!fp) {
        printf("\n[!] Vault is empty.\n");
        return;
    }

    printf("\nEnter Website to Search: ");
    scanf("%s", target);

    // Step 1: Convert user input to lowercase
    for(int i = 0; target[i]; i++) {
        target[i] = tolower(target[i]);
    }

    while(fread(&entry, sizeof(VaultEntry), 1, fp)) {
        // Step 2: Create a temporary lowercase version of the stored website
        char storedLower[50];
        strcpy(storedLower, entry.website);
        for(int i = 0; storedLower[i]; i++) {
            storedLower[i] = tolower(storedLower[i]);
        }

        // Step 3: Compare both lowercase strings
        if(strcmp(storedLower, target) == 0) {
            printf("\n--- Match Found ---\n");
            printf("Site: %s\nUser: %s\nPass: %s\n", entry.website, entry.username, entry.password);
            found = 1;
            break;
        }
    }

    if(!found) printf("\n[!] No match found for '%s'.\n", target);
    fclose(fp);
}
>>>>>>> 439878d (Fix: Case-insensitive search implemented using tolower)
