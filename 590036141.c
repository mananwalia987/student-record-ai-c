// ============================================================================
// PART 3: CGPA Calculation and Sorting Functions
// Project: Student Record and Result Management System
// Name: Manan Walia | SAP ID: 590036141 | Course: PRC1001 (UPES)
// ============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct Student {
    long long sapID;
    char rollNo[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[8];
};

struct Student s[MAX];
int n = 0;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removeNewline(char str[]) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int searchIndex(long long sapID) {
    for (int i = 0; i < n; i++) {
        if (s[i].sapID == sapID) return i;
    }
    return -1;
}

// Function to calculate CGPA by averaging non-zero SGPAs
float calculateCGPA(struct Student st) {
    float sum = 0.0;
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (st.sgpa[i] > 0.0) {
            sum = sum + st.sgpa[i];
            count++;
        }
    }
    if (count > 0) return sum / count;
    return 0.0;
}

void printStudent(struct Student st) {
    printf("\n----------------------------------------\n");
    printf("SAP ID   : %lld\n", st.sapID);
    printf("Roll No  : %s\n", st.rollNo);
    printf("Name     : %s\n", st.name);
    printf("Phone    : %s\n", st.phone);
    printf("Email    : %s\n", st.email);
    printf("Year     : %d\n", st.year);
    printf("Semester : %d\n", st.semester);
    printf("SGPA     : ");
    for (int i = 0; i < 8; i++) {
        if (st.sgpa[i] > 0.0) printf("Sem%d: %.2f ", i + 1, st.sgpa[i]);
        else printf("Sem%d: - ", i + 1);
    }
    printf("\nCGPA     : %.2f\n", calculateCGPA(st));
    printf("----------------------------------------\n");
}

void addStudent() {
    if (n >= MAX) {
        printf("\nStudent list is full!\n");
        return;
    }
    struct Student temp;
    printf("\n=== Enter Student Details ===\n");
    printf("Enter SAP ID: ");
    scanf("%lld", &temp.sapID);
    clearBuffer();

    if (searchIndex(temp.sapID) != -1) {
        printf("Student with this SAP ID already exists!\n");
        return;
    }
    printf("Enter Roll No: ");
    fgets(temp.rollNo, sizeof(temp.rollNo), stdin);
    removeNewline(temp.rollNo);

    printf("Enter Name: ");
    fgets(temp.name, sizeof(temp.name), stdin);
    removeNewline(temp.name);

    printf("Enter Phone No: ");
    fgets(temp.phone, sizeof(temp.phone), stdin);
    removeNewline(temp.phone);

    printf("Enter Email ID: ");
    fgets(temp.email, sizeof(temp.email), stdin);
    removeNewline(temp.email);

    printf("Enter Year (1-4): ");
    scanf("%d", &temp.year);
    clearBuffer();

    printf("Enter Semester (1-8): ");
    scanf("%d", &temp.semester);
    clearBuffer();

    printf("Enter SGPA for completed semesters (enter 0 if not completed yet):\n");
    for (int i = 0; i < 8; i++) {
        printf("Semester %d SGPA: ", i + 1);
        scanf("%f", &temp.sgpa[i]);
        clearBuffer();
    }
    s[n] = temp;
    n++;
    printf("\nStudent record added successfully!\n");
}

void searchStudent() {
    long long id;
    printf("\nEnter SAP ID to search: ");
    scanf("%lld", &id);
    clearBuffer();

    int idx = searchIndex(id);
    if (idx == -1) printf("Student not found!\n");
    else {
        printf("\nRecord found:");
        printStudent(s[idx]);
    }
}

// 3. Display student CGPA
void displayCGPA() {
    long long id;
    printf("\nEnter SAP ID: ");
    scanf("%lld", &id);
    clearBuffer();

    int idx = searchIndex(id);
    if (idx == -1) printf("Student not found!\n");
    else {
        printf("\nStudent: %s\n", s[idx].name);
        printf("SAP ID : %lld\n", s[idx].sapID);
        printf("CGPA   : %.2f\n", calculateCGPA(s[idx]));
    }
}

// 4. Calculate average CGPA of students in each year
void averageCGPAByYear() {
    printf("\n=== Average CGPA by Year ===\n");
    for (int yr = 1; yr <= 4; yr++) {
        float sum = 0.0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i].year == yr) {
                sum = sum + calculateCGPA(s[i]);
                count++;
            }
        }
        if (count > 0) printf("Year %d: Average CGPA = %.2f (%d students)\n", yr, sum / count, count);
        else printf("Year %d: No records\n", yr);
    }
}

void displayAll() {
    printf("\n=== All Student Records ===\n");
    if (n == 0) {
        printf("No records found. Please add students first.\n");
        return;
    }
    printf("Total Students: %d\n", n);
    for (int i = 0; i < n; i++) printStudent(s[i]);
}

void deleteStudent() {
    long long id;
    printf("\nEnter SAP ID to delete: ");
    scanf("%lld", &id);
    clearBuffer();

    int idx = searchIndex(id);
    if (idx == -1) {
        printf("Student not found!\n");
        return;
    }
    printf("Are you sure you want to delete %s? (y/n): ", s[idx].name);
    char confirm;
    scanf("%c", &confirm);
    clearBuffer();

    if (confirm == 'y' || confirm == 'Y') {
        for (int i = idx; i < n - 1; i++) s[i] = s[i + 1];
        n--;
        printf("Record deleted successfully.\n");
    } else {
        printf("Deletion cancelled.\n");
    }
}

// 7. Sort by SAP ID using Selection Sort
void sortBySAPID() {
    printf("\n=== Students Sorted by SAP ID (Selection Sort) ===\n");
    if (n == 0) {
        printf("No records to sort.\n");
        return;
    }
    struct Student temp[MAX];
    for (int i = 0; i < n; i++) temp[i] = s[i];

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (temp[j].sapID < temp[min_idx].sapID) min_idx = j;
        }
        if (min_idx != i) {
            struct Student swap = temp[i];
            temp[i] = temp[min_idx];
            temp[min_idx] = swap;
        }
    }
    for (int i = 0; i < n; i++) printStudent(temp[i]);
}

// 8. Sort by Name using Bubble Sort
void sortByName() {
    printf("\n=== Students Sorted by Name (Bubble Sort) ===\n");
    if (n == 0) {
        printf("No records to sort.\n");
        return;
    }
    struct Student temp[MAX];
    for (int i = 0; i < n; i++) temp[i] = s[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(temp[j].name, temp[j + 1].name) > 0) {
                struct Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }
    for (int i = 0; i < n; i++) printStudent(temp[i]);
}

int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf(" STUDENT RECORD AND RESULT SYSTEM (C)   \n");
        printf(" UPES - PRC1001 Assignment (Part 3)     \n");
        printf("========================================\n");
        printf("1.  Add Student Details\n");
        printf("2.  Search Student Record\n");
        printf("3.  Display Student CGPA\n");
        printf("4.  Display Average CGPA by Year\n");
        printf("5.  Display All Students\n");
        printf("6.  Delete Student Record\n");
        printf("7.  Sort by SAP ID (Selection Sort)\n");
        printf("8.  Sort by Name (Bubble Sort)\n");
        printf("9.  AI Academic Advisor (Coming in Part 4)\n");
        printf("0.  Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: displayCGPA(); break;
            case 4: averageCGPAByYear(); break;
            case 5: displayAll(); break;
            case 6: deleteStudent(); break;
            case 7: sortBySAPID(); break;
            case 8: sortByName(); break;
            case 0: printf("\nExiting program...\n"); break;
            default: printf("\nFeature coming in Part 4.\n");
        }

        if (choice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
        }
    } while (choice != 0);

    return 0;
}
