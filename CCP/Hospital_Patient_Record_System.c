#include <stdio.h>
#include <string.h>

int choice;
int id[50];
char name[50][50];
char disease[50][50];
int age[50];
int total_patient = 3;

// Add Patient
void add_patient() {
    if(total_patient >= 50) {
        printf("\n          Patient list is full! Try again later!\n\n");
        return;
    }

    printf("\n               === Adding Patient ===\n\n");
    id[total_patient] = total_patient + 1;

    printf("Enter name: ");
    scanf(" %[^\n]s", name[total_patient]);

    printf("Enter disease: ");
    scanf(" %[^\n]s", disease[total_patient]);

    printf("Enter age: ");
    scanf("%d", &age[total_patient]);

    total_patient++;
    printf("\n          Patient added successfully!\n\n");
    printf("---------------------------------------------------\n\n");
}

// View All Patients
void view_patient() {
    if(total_patient == 0) {
        printf("\n          No patients available!\n\n");
        return;
    }

    printf("\n              === All Patients ===\n\n");
    for(int i = 0; i < total_patient; i++) {
        printf("Patient ID: %d\n", id[i]);
        printf("Name      : %s\n", name[i]);
        printf("Disease   : %s\n", disease[i]);
        printf("Age       : %d\n", age[i]);
        printf("---------------------------------------------------\n");
    }
    printf("\n");
}

// Search Patient by ID
void search_patient_by_id() {
    int searchID;
    printf("\nEnter patient ID: ");
    scanf("%d", &searchID);

    printf("\n             === Searching Patient  ===\n\n");
    for(int i = 0; i < total_patient; i++) {
        if(id[i] == searchID) {
            printf("Record found!\n\n");
            printf("Patient ID: %d\n", id[i]);
            printf("Name      : %s\n", name[i]);
            printf("Disease   : %s\n", disease[i]);
            printf("Age       : %d\n", age[i]);
            printf("---------------------------------------------------\n\n");
            return;
        }
    }
    printf("No record found!\n\n");
}

// Search Patient by Disease
void search_patient_by_disease() {
    char searchDisease[50];
    int found = 0;

    printf("\nEnter disease name: ");
    scanf(" %[^\n]s", searchDisease);

    printf("\n           === Patients with %s ===\n\n", searchDisease);
    for(int i = 0; i < total_patient; i++) {
        if(strcmp(disease[i], searchDisease) == 0) {
            printf("Patient ID: %d\n", id[i]);
            printf("Name : %s\n", name[i]);
            printf("Age : %d\n", age[i]);
            printf("---------------------------------------------------\n");
            found = 1;
        }
    }

    if(!found) {
        printf("No patients found with this disease.\n");
    }
    printf("\n");
}

// Update Patient
void update_patient() {
    int updateID;
    printf("\nEnter patient ID to update: ");
    scanf("%d", &updateID);

    printf("\n               === Updating Patient ===\n\n");
    for(int i = 0; i < total_patient; i++) {
        if(id[i] == updateID) {
            printf("Enter new name: ");
            scanf(" %[^\n]s", name[i]);

            printf("Enter new disease: ");
            scanf(" %[^\n]s", disease[i]);

            printf("Enter new age: ");
            scanf("%d", &age[i]);

            printf("\n Record updated successfully!\n\n");
            printf("---------------------------------------------------\n\n");
            return;
        }
    }
    printf("No patient found with ID %d\n\n", updateID);
}

// Main Function
int main(void) {
    // Initial patients
    id[0] = 1; strcpy(name[0], "Muhammad Omer"); 
             strcpy(disease[0], "Dengue"); age[0] = 25;
    id[1] = 2; strcpy(name[1], "Fatima Siddiqui"); 
             strcpy(disease[1], "Flu"); age[1] = 8;
    id[2] = 3; strcpy(name[2], "Zymal Khan"); 
             strcpy(disease[2], "Sickle Cell Anemia"); age[2] = 18;

    while(1) {
        printf("\n                  ================================\n");
        printf("                      Patient Record System\n");
        printf("                  ================================\n\n");

        printf("1. Add Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient by ID\n");
        printf("4. Search Patient by Disease\n");
        printf("5. Update Patient\n");
        printf("6. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_patient(); 
												break;
            case 2: view_patient(); 
												break;
            case 3: search_patient_by_id(); 
												break;
            case 4: search_patient_by_disease();
												break;
            case 5: update_patient(); 
												break;
            case 6: 
                printf("\n Exiting... Goodbye!\n\n");
                return 0;
            default:
                printf("\nInvalid choice! Enter again.\n\n");
        }
    }

    return 0;
}
