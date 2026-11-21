# Student Record and Result Management System

**Course:** Programming in C (PRC1001)  
**Program:** B.Tech CSE — Semester I  
**University:** UPES Dehradun  
**Name:** Manan Walia  
**SAP ID:** 590036141  

## About the Project

This is my C programming assignment for PRC1001. It is a console-based, menu-driven program that stores student academic records, calculates CGPA from semester SGPAs, sorts records, and gives basic academic advice based on CGPA using `if-else` logic.

## Files in This Repository

```text
student-record-ai-c/
├── 590036141.c           # Main C source file
├── README.md             # Project info and how to run
├── AI_USAGE_LOG.md       # Prompts I asked AI and how I verified them
└── tests/
    ├── sample_input.txt  # Sample menu inputs for testing
    └── sample_output.txt # Output captured from running the sample inputs
```

## What It Can Do

- **Add a student (`addStudent`)**: Takes SAP ID, Roll No, Name, Phone, Email, Year (1–4), Semester (1–8), and SGPAs for up to 8 semesters (0 if a semester isn't completed yet). Checks for duplicate SAP IDs.
- **Search by SAP ID (`searchStudent`)**: Looks up a student and prints their full record.
- **Calculate CGPA (`calcCGPA` / `displayCGPA`)**: Averages only the semesters with SGPA > 0.
- **Average CGPA by Year (`avgCGPAByYear`)**: Shows the average CGPA for Years 1 to 4.
- **Show all students (`displayAll`)**: Lists every student currently stored.
- **Delete a student (`deleteStudent`)**: Removes a record by SAP ID.
- **Sort by SAP ID (`sortBySAPID`)**: Sorts a temporary copy of the array in ascending order using Bubble Sort, so the original order isn't overwritten.
- **Sort by Name (`sortByName`)**: Sorts a temporary copy alphabetically using Bubble Sort and `strcmp()`.
- **AI-Assisted Academic Advisor (`academicAdvisor`)**: Checks a student's CGPA and prints advice across four categories:
  - `>= 9.0`: Excellent Performance
  - `>= 7.5`: Good Performance
  - `>= 6.0`: Needs Improvement
  - `< 6.0`: Requires Immediate Attention

## How to Compile and Run

On Windows (MinGW / GCC):
```bash
gcc 590036141.c -o 590036141.exe
590036141.exe
```

On Linux / macOS:
```bash
gcc 590036141.c -o 590036141
./590036141
```

## Quick Test

5 sample student records are loaded automatically when the program starts (`loadSampleStudents()`), covering different years and CGPA categories. You can also pipe `tests/sample_input.txt` into the executable to reproduce `tests/sample_output.txt`.

## AI Usage

I used ChatGPT as a helper to understand struct sorting, come up with the 4 CGPA advice categories, and generate 5 sample student records for testing. Details of what I asked and how I verified everything are in [AI_USAGE_LOG.md](AI_USAGE_LOG.md).
