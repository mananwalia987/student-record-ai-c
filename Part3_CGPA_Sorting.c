// Part 3: CGPA Calculation & Sorting Functions
// Name: Manan Walia | SAP ID: 590036141
// Course: Programming in C (PRC1001) - B.Tech CSE Sem 1

#include <stdio.h>
#include <string.h>

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

float calcCGPA(struct Student st) {
    float sum = 0;
    int count = 0, i;
    for (i = 0; i < 8; i++) {
        if (st.sgpa[i] > 0) {
            sum = sum + st.sgpa[i];
            count++;
        }
    }
    if (count == 0) return 0;
    return sum / count;
}

void showStudent(struct Student st) {
    int i;
    printf("\n-----------------------------------\n");
    printf("SAP ID   : %lld\n", st.sapID);
    printf("Roll No  : %s\n", st.rollNo);
    printf("Name     : %s\n", st.name);
    printf("Phone    : %s\n", st.phone);
    printf("Email    : %s\n", st.email);
    printf("Year     : %d\n", st.year);
    printf("Semester : %d\n", st.semester);
    printf("SGPA     : ");
    for (i = 0; i < 8; i++) {
        if (st.sgpa[i] > 0) printf("S%d:%.2f ", i + 1, st.sgpa[i]);
        else printf("S%d:- ", i + 1);
    }
    printf("\nCGPA     : %.2f\n", calcCGPA(st));
    printf("-----------------------------------\n");
}

void addStudent() {
    int i;
    if (n >= MAX) { printf("\nList is full!\n"); return; }

    printf("\nEnter SAP ID: ");
    scanf("%lld", &s[n].sapID);
    for (i = 0; i < n; i++) {
        if (s[i].sapID == s[n].sapID) {
            printf("SAP ID already exists!\n");
            return;
        }
    }

    printf("Enter Roll No: "); scanf("%s", s[n].rollNo);
    printf("Enter Name: "); scanf(" %[^\n]", s[n].name);
    printf("Enter Phone No: "); scanf("%s", s[n].phone);
    printf("Enter Email ID: "); scanf("%s", s[n].email);
    printf("Enter Year (1-4): "); scanf("%d", &s[n].year);
    printf("Enter Semester (1-8): "); scanf("%d", &s[n].semester);

    printf("Enter SGPA for 8 semesters (enter 0 if not completed):\n");
    for (i = 0; i < 8; i++) {
        printf("Sem %d: ", i + 1);
        scanf("%f", &s[n].sgpa[i]);
    }
    n++;
    printf("\nStudent added successfully!\n");
}

void searchStudent() {
    long long id;
    int i, found = 0;
    printf("\nEnter SAP ID to search: ");
    scanf("%lld", &id);
    for (i = 0; i < n; i++) {
        if (s[i].sapID == id) { showStudent(s[i]); found = 1; break; }
    }
    if (found == 0) printf("Student not found!\n");
}

void displayCGPA() {
    long long id;
    int i, found = 0;
    printf("\nEnter SAP ID: ");
    scanf("%lld", &id);
    for (i = 0; i < n; i++) {
        if (s[i].sapID == id) {
            printf("\nName : %s\n", s[i].name);
            printf("CGPA : %.2f\n", calcCGPA(s[i]));
            found = 1;
            break;
        }
    }
    if (found == 0) printf("Student not found!\n");
}

void avgCGPAByYear() {
    int yr, i, count;
    float sum;
    printf("\n--- Average CGPA by Year ---\n");
    for (yr = 1; yr <= 4; yr++) {
        sum = 0; count = 0;
        for (i = 0; i < n; i++) {
            if (s[i].year == yr) { sum = sum + calcCGPA(s[i]); count++; }
        }
        if (count > 0) printf("Year %d : %.2f (%d students)\n", yr, sum / count, count);
        else printf("Year %d : No students\n", yr);
    }
}

void displayAll() {
    int i;
    if (n == 0) { printf("\nNo records found!\n"); return; }
    printf("\nTotal Students: %d\n", n);
    for (i = 0; i < n; i++) showStudent(s[i]);
}

void deleteStudent() {
    long long id;
    int i, j, found = 0;
    printf("\nEnter SAP ID to delete: ");
    scanf("%lld", &id);
    for (i = 0; i < n; i++) {
        if (s[i].sapID == id) {
            for (j = i; j < n - 1; j++) s[j] = s[j + 1];
            n--; found = 1; printf("Record deleted!\n"); break;
        }
    }
    if (found == 0) printf("Student not found!\n");
}

void sortBySAPID() {
    struct Student temp[MAX], t;
    int i, j;
    if (n == 0) { printf("\nNo records to sort!\n"); return; }
    for (i = 0; i < n; i++) temp[i] = s[i];
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (temp[j].sapID > temp[j + 1].sapID) {
                t = temp[j]; temp[j] = temp[j + 1]; temp[j + 1] = t;
            }
        }
    }
    printf("\n--- Sorted by SAP ID ---\n");
    for (i = 0; i < n; i++) showStudent(temp[i]);
}

void sortByName() {
    struct Student temp[MAX], t;
    int i, j;
    if (n == 0) { printf("\nNo records to sort!\n"); return; }
    for (i = 0; i < n; i++) temp[i] = s[i];
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(temp[j].name, temp[j + 1].name) > 0) {
                t = temp[j]; temp[j] = temp[j + 1]; temp[j + 1] = t;
            }
        }
    }
    printf("\n--- Sorted by Name ---\n");
    for (i = 0; i < n; i++) showStudent(temp[i]);
}

void loadSampleStudents() {
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 8; j++)
            s[i].sgpa[j] = 0;

    s[0].sapID = 59001001; strcpy(s[0].rollNo, "R101"); strcpy(s[0].name, "Aarav Sharma");
    strcpy(s[0].phone, "9876543210"); strcpy(s[0].email, "aarav@stu.upes.ac.in");
    s[0].year = 2; s[0].semester = 4;
    s[0].sgpa[0] = 9.2; s[0].sgpa[1] = 9.5; s[0].sgpa[2] = 9.1; s[0].sgpa[3] = 9.4;

    s[1].sapID = 59001002; strcpy(s[1].rollNo, "R102"); strcpy(s[1].name, "Priya Verma");
    strcpy(s[1].phone, "9123456780"); strcpy(s[1].email, "priya@stu.upes.ac.in");
    s[1].year = 1; s[1].semester = 2;
    s[1].sgpa[0] = 7.8; s[1].sgpa[1] = 8.0;

    s[2].sapID = 59001003; strcpy(s[2].rollNo, "R103"); strcpy(s[2].name, "Rahul Gupta");
    strcpy(s[2].phone, "9811223344"); strcpy(s[2].email, "rahul@stu.upes.ac.in");
    s[2].year = 3; s[2].semester = 5;
    s[2].sgpa[0] = 6.5; s[2].sgpa[1] = 6.0; s[2].sgpa[2] = 6.8; s[2].sgpa[3] = 6.2; s[2].sgpa[4] = 6.4;

    s[3].sapID = 59001004; strcpy(s[3].rollNo, "R104"); strcpy(s[3].name, "Meera Patel");
    strcpy(s[3].phone, "9001122334"); strcpy(s[3].email, "meera@stu.upes.ac.in");
    s[3].year = 1; s[3].semester = 1;
    s[3].sgpa[0] = 5.3;

    s[4].sapID = 59001005; strcpy(s[4].rollNo, "R105"); strcpy(s[4].name, "Karan Singh");
    strcpy(s[4].phone, "9988776655"); strcpy(s[4].email, "karan@stu.upes.ac.in");
    s[4].year = 4; s[4].semester = 7;
    s[4].sgpa[0] = 7.5; s[4].sgpa[1] = 8.1; s[4].sgpa[2] = 7.9; s[4].sgpa[3] = 8.3;
    s[4].sgpa[4] = 7.7; s[4].sgpa[5] = 8.0; s[4].sgpa[6] = 7.6;

    n = 5;
}

int main() {
    int choice;
    loadSampleStudents();

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display Student CGPA\n");
        printf("4. Average CGPA by Year\n");
        printf("5. Display All Students\n");
        printf("6. Delete Student\n");
        printf("7. Sort by SAP ID\n");
        printf("8. Sort by Name\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: displayCGPA(); break;
            case 4: avgCGPAByYear(); break;
            case 5: displayAll(); break;
            case 6: deleteStudent(); break;
            case 7: sortBySAPID(); break;
            case 8: sortByName(); break;
            case 0: printf("\nGoodbye!\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
