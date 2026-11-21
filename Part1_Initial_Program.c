// Part 1: Initial Program Skeleton & Menu
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

void loadSampleStudents() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 8; j++) {
            s[i].sgpa[j] = 0;
        }
    }

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
        printf("9. AI Academic Advisor\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: printf("\nGoodbye!\n"); break;
            default: printf("\nFeature coming soon!\n");
        }
    } while (choice != 0);

    return 0;
}
