// ============================================================================
// PART 1: Initial C Program
// Project: Student Record and Result Management System
// Name: Manan Walia | SAP ID: 590036141 | Course: PRC1001 (UPES)
// ============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Student structure definition
struct Student {
    long long sapID;
    char rollNo[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[8]; // SGPA for 8 semesters
};

// Global array of structures
struct Student s[MAX];
int n = 0; // Number of students currently added

// Helper function to clear input buffer after scanf
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf(" STUDENT RECORD AND RESULT SYSTEM (C)   \n");
        printf(" UPES - PRC1001 Assignment              \n");
        printf("========================================\n");
        printf("1.  Add Student Details\n");
        printf("2.  Search Student Record\n");
        printf("3.  Display Student CGPA\n");
        printf("4.  Display Average CGPA by Year\n");
        printf("5.  Display All Students\n");
        printf("6.  Delete Student Record\n");
        printf("7.  Sort by SAP ID (Selection Sort)\n");
        printf("8.  Sort by Name (Bubble Sort)\n");
        printf("9.  AI Academic Advisor\n");
        printf("10. Load 5 Sample Records\n");
        printf("0.  Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        if (choice != 0) {
            printf("\n[Part 1] Menu skeleton ready. Functions will be added in upcoming parts.\n");
            printf("\nPress Enter to continue...");
            getchar();
        }

    } while (choice != 0);

    printf("\nExiting program...\n");
    return 0;
}
