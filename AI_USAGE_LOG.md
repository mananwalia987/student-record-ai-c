# AI Usage Log

**Course:** Programming in C (PRC1001)  
**Program:** B.Tech CSE — Semester I  
**University:** UPES Dehradun  
**Student:** Manan Walia (SAP ID: 590036141)  

## Prompts & How I Used Them

| Date | AI Tool | Prompt / Question Asked | How I Used / Verified It |
| :--- | :--- | :--- | :--- |
| 19 Sept 2026 | ChatGPT | "fgets is getting skipped after scanf in C, how do I fix it?" | Found out `scanf` leaves the newline (`\n`) in the input buffer, so `fgets` reads an empty line right after. I wrote a `clearBuffer()` function using `getchar()` instead of `fflush(stdin)` and tested it with names and emails. |
| 27 Oct 2026 | ChatGPT | "How to sort an array of structs in C by ID and by name?" | Used the idea of comparing struct fields and swapping the whole `struct Student`. I wrote Selection Sort for SAP ID and Bubble Sort with `strcmp()` for names, using a temporary `temp[]` array so the main array stays unchanged. |
| 10 Nov 2026 | ChatGPT | "Suggest 4 simple CGPA-based academic advice categories for a C mini project." | Got four categories (Excellent, Good, Needs Improvement, Requires Immediate Attention). I implemented them in `printAdvice()` using `if-else` and rewrote the advice lines to fit UPES subjects and faculty mentor meetings. |
| 13 Nov 2026 | ChatGPT | "Give 5 sample student records with different semester SGPAs to test CGPA calculation." | Checked each student's CGPA by hand on paper first to make sure semesters with `0` SGPA aren't counted in the average, then added the 5 records into `loadSampleData()`. |

## Notes on What I Changed Myself

- **Input handling:** ChatGPT mentioned `fflush(stdin)` as a quick fix, but I read that it doesn't work reliably on GCC/Linux, so I stuck with the `while ((c = getchar()) != '\n' && c != EOF);` loop in `clearBuffer()`.
- **Non-destructive sorting:** Instead of sorting `s[]` directly, I copied `s[]` into `temp[]` inside `sortBySAPID()` and `sortByName()` so displaying sorted results doesn't mess up the order of added records.
- **Advisor thresholds:** Adjusted the advice text in `printAdvice()` and made sure the 5 sample students cover all 4 CGPA bands so I could test every branch.

All code in `590036141.c` was written, compiled, and tested by me.
