# AI Usage Log

**Course:** Programming in C (PRC1001)  
**Program:** B.Tech CSE - Semester I  
**University:** University of Petroleum and Energy Studies (UPES)  
**Student Name:** Manan Walia  
**SAP ID:** 590036141  

---

## AI Interaction Summary Table

| Date | AI Tool | Prompt / Question Asked | How I Used / Verified the Response |
| :--- | :--- | :--- | :--- |
| **19 Sept 2026** | ChatGPT | "Why does my C program skip `fgets()` after using `scanf()` to take an integer input?" | ChatGPT explained that `scanf()` leaves a `\n` character in the standard input stream. It suggested clearing the buffer with `while ((c = getchar()) != '\n' && c != EOF);`. I tested this in a small test file, verified that it solved the skipping issue, and created the `clearBuffer()` function. |
| **27 Oct 2026** | ChatGPT | "Explain the difference between Selection Sort and Bubble Sort in C and provide simple pseudocode." | I used the explanation to understand the comparison and swap logic. I wrote both functions myself in C: Selection Sort to sort student records by SAP ID, and Bubble Sort using `strcmp()` to sort records alphabetically by Name. |
| **10 Nov 2026** | ChatGPT | "Suggest simple CGPA-based academic advice categories and recommendations for a university student record system in C." | ChatGPT suggested four categories (Excellent, Good, Needs Improvement, Requires Immediate Attention). I used these categories and wrote an `if-else` decision ladder in C, customizing the advice messages for UPES coursework and mentor meetings. |
| **13 Nov 2026** | ChatGPT | "Give me 5 sample student records for a B.Tech CSE program with different semester SGPAs to test CGPA calculation." | ChatGPT generated 5 sample records. I verified the CGPA calculations by hand on paper to ensure that the average only considers semesters where SGPA > 0, then added them to `loadSampleData()`. |

---

## Detailed Notes on Verification

1. **Buffer Handling (19 Sept 2026):**
   - *AI Suggestion:* Suggested using either `fflush(stdin)` or `getchar()`.
   - *My Verification & Changes:* Checked standard C documentation and learned that `fflush(stdin)` is undefined behavior on Linux/GCC. Therefore, I wrote a safe `clearBuffer()` function using `getchar()`.

2. **Sorting on Structs (27 Oct 2026):**
   - *AI Suggestion:* Suggested sorting an integer array.
   - *My Verification & Changes:* Adapted the concept to work on an array of `struct Student`. Made sure to copy the records into a temporary `temp[]` array before sorting so that the user's original record order is not modified in memory.

3. **Academic Advisor (10 Nov 2026):**
   - *AI Suggestion:* Suggested raw advice text and simple thresholds (e.g., 9.0, 7.5, 6.0).
   - *My Verification & Changes:* Reviewed the thresholds against university grading standards. Customized the advice text to suggest consulting faculty mentors, avoiding backlogs, and focusing on lower SGPA subjects. Implemented the logic inside `printAdvice()` using basic `if-else` conditions.

4. **Test Data Verification (13 Nov 2026):**
   - *AI Suggestion:* Suggested raw SGPA values.
   - *My Verification & Changes:* Verified that the calculated CGPA falls accurately into all four performance categories to test all branches of the advisor function.

---

## Declaration
AI tools were used strictly as a learning assistant to clarify programming concepts, generate test data, and brainstorm categories. All code in `590036141.c` has been understood, written, tested, and verified by me.
