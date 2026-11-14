// ============================================================================
// PART 4: AI Academic Advisor (Complete Full Code)
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

// Part B - Simple AI-Assisted Academic Advisor
void printAdvice(float cgpa) {
    printf("\nCGPA: %.2f\n", cgpa);

    if (cgpa >= 9.0) {
        printf("Performance Category : Excellent Performance\n");
        printf("Recommendation       : Excellent performance! Maintain your current study routine and look for internships/projects.\n");
    } else if (cgpa >= 7.5) {
        printf("Performance Category : Good Performance\n");
        printf("Recommendation       : Good performance! Work a bit harder in subjects where SGPA was lower to cross 9.0.\n");
    } else if (cgpa >= 6.0) {
        printf("Performance Category : Needs Improvement\n");
        printf("Recommendation       : Needs improvement. Make a regular study timetable and take help from teachers in tough subjects.\n");
    } else {
        printf("Performance Category : Requires Immediate Attention\n");
        printf("Recommendation       : Requires immediate attention. Meet your faculty mentor and start studying daily to clear backlogs.\n");
    }
    printf("----------------------------------------\n");
}

void academicAdvisor() {
    printf("\n=== AI-Assisted Academic Advisor ===\n");
    if (n == 0) {
        printf("No records available.\n");
        return;
    }

    printf("1. Check advice for one student\n");
    printf("2. Check advice for all students\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);
    clearBuffer();

    if (choice == 1) {
        long long id;
        printf("Enter SAP ID: ");
        scanf("%lld", &id);
        clearBuffer();

        int idx = searchIndex(id);
        if (idx == -1) {
            printf("Student not found!\n");
        } else {
            printf("\nStudent: %s (SAP ID: %lld)\n", s[idx].name, s[idx].sapID);
            float cgpa = calculateCGPA(s[idx]);
            printAdvice(cgpa);
        }
    } else if (choice == 2) {
        for (int i = 0; i < n; i++) {
            printf("\nStudent: %s (SAP ID: %lld)\n", s[i].name, s[i].sapID);
            float cgpa = calculateCGPA(s[i]);
            printAdvice(cgpa);
        }
    } else {
        printf("Invalid choice!\n");
    }
}

void loadSampleData() {
    s[0].sapID = 59001001; strcpy(s[0].rollNo, "R1001"); strcpy(s[0].name, "Aarav Sharma");
    strcpy(s[0].phone, "9876543210"); strcpy(s[0].email, "aarav@stu.upes.ac.in");
    s[0].year = 2; s[0].semester = 4;
    s[0].sgpa[0] = 9.2f; s[0].sgpa[1] = 9.5f; s[0].sgpa[2] = 9.1f; s[0].sgpa[3] = 9.4f;

    s[1].sapID = 59001002; strcpy(s[1].rollNo, "R1002"); strcpy(s[1].name, "Priya Verma");
    strcpy(s[1].phone, "9123456780"); strcpy(s[1].email, "priya@stu.upes.ac.in");
    s[1].year = 1; s[1].semester = 2;
    s[1].sgpa[0] = 7.8f; s[1].sgpa[1] = 8.0f;

    s[2].sapID = 59001003; strcpy(s[2].rollNo, "R1003"); strcpy(s[2].name, "Rahul Gupta");
    strcpy(s[2].phone, "9811223344"); strcpy(s[2].email, "rahul@stu.upes.ac.in");
    s[2].year = 3; s[2].semester = 5;
    s[2].sgpa[0] = 6.5f; s[2].sgpa[1] = 6.0f; s[2].sgpa[2] = 6.8f; s[2].sgpa[3] = 6.2f; s[2].sgpa[4] = 6.4f;

    s[3].sapID = 59001004; strcpy(s[3].rollNo, "R1004"); strcpy(s[3].name, "Meera Patel");
    strcpy(s[3].phone, "9001122334"); strcpy(s[3].email, "meera@stu.upes.ac.in");
    s[3].year = 1; s[3].semester = 1;
    s[3].sgpa[0] = 5.3f;

    s[4].sapID = 59001005; strcpy(s[4].rollNo, "R1005"); strcpy(s[4].name, "Karan Singh");
    strcpy(s[4].phone, "9988776655"); strcpy(s[4].email, "karan@stu.upes.ac.in");
    s[4].year = 4; s[4].semester = 7;
    s[4].sgpa[0] = 7.5f; s[4].sgpa[1] = 8.1f; s[4].sgpa[2] = 7.9f; s[4].sgpa[3] = 8.3f; s[4].sgpa[4] = 7.7f; s[4].sgpa[5] = 8.0f; s[4].sgpa[6] = 7.6f;

    n = 5;
    printf("\n5 sample records loaded successfully!\n");
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

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: displayCGPA(); break;
            case 4: averageCGPAByYear(); break;
            case 5: displayAll(); break;
            case 6: deleteStudent(); break;
            case 7: sortBySAPID(); break;
            case 8: sortByName(); break;
            case 9: academicAdvisor(); break;
            case 10: loadSampleData(); break;
            case 0: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice! Please choose 0 to 10.\n");
        }

        if (choice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
        }

    } while (choice != 0);

    return 0;
}
