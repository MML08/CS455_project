#include <stdio.h>
#include <string.h>
#include "dao.h"  // Make sure this defines Role, STUDENT, TEACHER, STAFF, and struct Person

/* Data entry */
void dataEntry(Role role) {
    FILE *filePointer = fopen("schoolRoster.txt", "a"); 
    if (filePointer == NULL) {
        printf("File failed to open.\n");
        return;
    }

    struct Person entry;
    char buffer[100];

    printf("Please enter the first name: ");
    fgets(entry.name.first_name, sizeof(entry.name.first_name), stdin);
    strtok(entry.name.first_name, "\n");

    printf("Please enter the middle name: ");
    fgets(entry.name.middle_name, sizeof(entry.name.middle_name), stdin);
    strtok(entry.name.middle_name, "\n");

    printf("Please enter the last name: ");
    fgets(entry.name.last_name, sizeof(entry.name.last_name), stdin);
    strtok(entry.name.last_name, "\n");

    printf("Please enter their month of birth (1-12): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &entry.date_of_birth.month);

    printf("Please enter their day of birth (1-31): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &entry.date_of_birth.day);

    printf("Please enter their year of birth: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &entry.date_of_birth.year);

    printf("Gender (e.g., Male, Female, Other): ");
    fgets(entry.gender, sizeof(entry.gender), stdin);
    strtok(entry.gender, "\n");

    printf("Phone number (digits only): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &entry.phone_number);

    printf("Email: ");
    fgets(entry.email, sizeof(entry.email), stdin);
    strtok(entry.email, "\n");

    printf("Street address: ");
    fgets(entry.address.street, sizeof(entry.address.street), stdin);
    strtok(entry.address.street, "\n");

    printf("Apartment number (If applicable): ");
    fgets(entry.address.apartment, sizeof(entry.address.apartment), stdin);
    strtok(entry.address.apartment, "\n");

    printf("City: ");
    fgets(entry.address.city, sizeof(entry.address.city), stdin);
    strtok(entry.address.city, "\n");

    printf("State (two letter code): ");
    fgets(entry.address.state, sizeof(entry.address.state), stdin);
    strtok(entry.address.state, "\n");

    printf("Zip Code: ");
    fgets(entry.address.zip, sizeof(entry.address.zip), stdin);
    strtok(entry.address.zip, "\n");

    entry.role = role;

    // Save to file
    fprintf(filePointer, "Name: %s %s %s\n", entry.name.first_name, entry.name.middle_name, entry.name.last_name);
    fprintf(filePointer, "DOB: %02d/%02d/%04d\n", entry.date_of_birth.month, entry.date_of_birth.day, entry.date_of_birth.year);
    fprintf(filePointer, "Gender: %s\n", entry.gender);
    fprintf(filePointer, "Phone: %d\n", entry.phone_number);
    fprintf(filePointer, "Email: %s\n", entry.email);
    fprintf(filePointer, "Address: %s Apt %s, %s, %s %s\n\n",
            entry.address.street,
            entry.address.apartment,
            entry.address.city,
            entry.address.state,
            entry.address.zip);

    fclose(filePointer);
}

/* Display options */
void displayOptions() {
    printf("1) Would you like to enter display mode?\n");
    printf("2) Would you like to enter search mode?\n");
    printf("3) Would you like to add, edit, or delete a student?\n");
    printf("4) Would you like to add, edit, or delete a teacher?\n");
    printf("5) Would you like to add, edit, or delete a staff member?\n");

    char buffer[10];
    int selectedOption;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &selectedOption);

    switch (selectedOption) {
        case 1:
            printf("Entering display mode.\n");
            break;
        case 2:
            printf("Entering search mode.\n");
            break;
        case 3:
            printf("Entering student editor.\n");
            dataEntry(STUDENT);
            break;
        case 4:
            printf("Entering teacher editor.\n");
            dataEntry(TEACHER);
            break;
        case 5:
            printf("Entering staff editor.\n");
            dataEntry(STAFF);
            break;
        default:
            printf("The option entered was invalid, please try again.\n");
            break;
    }
}

/* Main */
int main() {
    FILE *filePointer = fopen("schoolRoster.txt", "a");
    if (filePointer == NULL) {
        printf("File failed to open.\n");
        return 1;
    }

    fclose(filePointer);

    printf("Welcome to the school roster! Please log in.\n");
    // Placeholder for login logic

    char buffer[10];
    char options;

    printf("Would you like to see the options? (y/n): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%c", &options);

    if (options == 'y' || options == 'Y') {
        displayOptions();
    }

    return 0;
}
