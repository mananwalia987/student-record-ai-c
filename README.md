# Student Record and Result Management System (AI-Assisted)

**Course Name:** Programming in C (PRC1001)  
**Program:** B.Tech Computer Science and Engineering (CSE)  
**Semester:** Semester I  
**University:** University of Petroleum and Energy Studies (UPES)  

**Submitted By:**  
- **Name:** Manan Walia  
- **SAP ID:** 590036141  

---

## 1. Project Overview

This is a console-based, menu-driven Student Record and Result Management System developed in C language for the PRC1001 course assignment. 

The project allows managing academic records of students, calculating SGPA and CGPA, sorting records, and providing academic recommendations using an AI-assisted decision-making function (if-else logic).

---

## 2. Project Structure

```
student-record-ai-c/
├── 590036141.c           # Main C program source code
├── README.md             # Project documentation and instructions
├── AI_USAGE_LOG.md       # Record of AI prompts, ideas, and verification
└── tests/
    ├── sample_input.txt  # Input sequence used for testing
    └── sample_output.txt # Output generated from the test run
```

---

## 3. Features Implemented

### Part A: Core C Programming Features
1. **Add Student Details (`addStudent`)**: Adds new student record with SAP ID, Roll No, Name, Phone, Email, Year, Semester, and SGPA for all eight semesters. Prevents duplicate SAP ID.
2. **Search Student Record (`searchStudent`)**: Searches and displays record by entering SAP ID.
3. **Calculate and Display CGPA (`displayCGPA`)**: Computes CGPA by taking average of completed semesters.
4. **Average CGPA by Year (`averageCGPAByYear`)**: Displays the average CGPA of students in Year 1, Year 2, Year 3, and Year 4.
5. **Display All Students (`displayAll`)**: Displays all stored student records in structured format.
6. **Delete Student Record (`deleteStudent`)**: Deletes a student record using SAP ID after confirmation.
7. **Sort by SAP ID (`sortBySAPID`)**: Sorts and displays student records in ascending order of SAP ID using Selection Sort.
8. **Sort by Name (`sortByName`)**: Sorts and displays student records in alphabetical order of Name using Bubble Sort.

### Part B: AI-Assisted Academic Advisor
- A simple decision-making function using `if-else` in C.
- Compares the student's CGPA against 4 performance bands:
  - **CGPA >= 9.0**: Excellent Performance
  - **CGPA >= 7.5**: Good Performance
  - **CGPA >= 6.0**: Needs Improvement
  - **CGPA < 6.0**: Requires Immediate Attention
- Generates tailored academic advice for individual students or all students.

---

## 4. How to Compile and Run

### On Windows (Command Prompt / PowerShell / MinGW):
```bash
gcc 590036141.c -o 590036141.exe
590036141.exe
```

### On Linux / macOS (Terminal):
```bash
gcc 590036141.c -o 590036141
./590036141
```

---

## 5. Quick Testing

To quickly test the application without manual typing:
1. Start the program.
2. Select **Option 10** to load 5 pre-configured sample student records across different years and CGPA bands.
3. Use options 3, 4, 5, 7, 8, and 9 to verify calculations, sorting, and advisor recommendations.
4. Select **Option 0** to exit.

---

## 6. Sorting Algorithms Used

- **Selection Sort (`sortBySAPID`)**: Used for numerical sorting of SAP IDs. It finds the minimum element and places it at the beginning.
- **Bubble Sort (`sortByName`)**: Used for alphabetical sorting of student names using `strcmp()`. It compares adjacent names and swaps them if they are out of order.

Both sorting functions work on a local copy of the array so that the original records remain intact.

---

## 7. AI Assistance Summary

AI (ChatGPT) was used as a learning assistant to:
1. Suggest categories and advice statements for the Academic Advisor.
2. Understand how to properly clear the `scanf` newline buffer in C using `getchar()`.
3. Generate realistic sample student test data.
4. Review the logic of Selection Sort and Bubble Sort.

All suggestions were reviewed, understood, and implemented in standard C by me. Detailed logs are available in `AI_USAGE_LOG.md`.
