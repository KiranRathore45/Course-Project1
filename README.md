Technical Requirements :-

-The program must be written in C.

-It must use stdio.h, stdlib.h, and string.h.

-Data must be stored in a text file (budget_data.txt).

-The program must use a struct to store record data.

-It must use file operations (fopen, fprintf, fscanf) for saving and reading data.

-It must run in a terminal/command prompt using a standard C compiler.

Technical Requirements :-

1. Programming Language :-

1.1 The system must be implemented using C.
1.2 Standard libraries required:

-stdio.h

-stdlib.h

-string.h

2. Data Storage :-

2.1 The system shall use a plain text file named budget_data.txt for storing records.

2.2 File operations shall support append, read, and scan operations.

2.3 The file format must be:

3. Data Structures :-

3.1 A struct Record shall be used to store:

type (string)

category (string)

amount (float)

4. Input Handling:-

4.1 scanf() shall be used to capture user input.

4.2 The program must clear input buffer as needed to prevent input errors.

4.3 Input validation (e.g., correct numeric values) is recommended but optional.

5. System Behavior :-

5.1 Records must be written in append mode using fopen(FILE_NAME, "a").

5.2 Records must be read using fopen(FILE_NAME, "r").

5.3 The program's menu must run continuously using a loop until the user selects Exit.

5.4 Balance calculation must correctly separate income and expense using strcmp().

6. Platform Requirements :-

6.1 The program must compile and run on any standard C compiler such as:

GCC

Clang

MinGW
6.2 The system must run in a terminal or command-line environment.

Abstract :-

The Budget Planning & Tracking System is a console-based application developed in the C programming language to help users manage their personal finances. The system allows users to record income and expenses, categorize them, view transaction history, and compute the current financial balance. Data is persisted using a text file to ensure that all entries are stored permanently and can be retrieved when needed. This lightweight system emphasizes simplicity, usability, and efficient financial tracking for students, individuals, or anyone requiring a basic budgeting tool.

<img width="1549" height="649" alt="Screenshot (1)" src="https://github.com/user-attachments/assets/ae2d81d1-3183-4b32-a8ad-a96ad66fe18d" />
<img width="1544" height="577" alt="Screenshot (2)" src="https://github.com/user-attachments/assets/a18d4423-a0a0-4967-aca6-3d74f2aac101" />
<img width="1535" height="601" alt="Screenshot (3)" src="https://github.com/user-attachments/assets/eb50425f-9cad-42c7-96cb-40d08cffb63f" />
<img width="1541" height="595" alt="Screenshot (4)" src="https://github.com/user-attachments/assets/40ab3752-d076-4efd-a3ce-b1d09510097f" />
<img width="1556" height="594" alt="Screenshot (5)" src="https://github.com/user-attachments/assets/44236028-d4f3-43f2-82a8-db2fcb27a9b9" />




