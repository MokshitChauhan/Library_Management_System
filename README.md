# 📚 Library Management System in C

A menu-driven Library Management System developed using the C programming language. This project allows users to manage library books, search records, issue and return books, and maintain book availability.

The application uses **structures, arrays, functions, loops, conditional statements, and file handling** to demonstrate fundamental C programming concepts.

## 🚀 Features

- **Add Books:** Add new books with unique IDs, titles, authors, and copy details.
- **Display Books:** View all books stored in the library.
- **Search Books:** Find books using their unique ID.
- **Issue Books:** Issue available copies and automatically update availability.
- **Return Books:** Return previously issued copies.
- **Delete Books:** Remove book records from the library.
- **Available Books:** Display books that currently have available copies.
- **Data Persistence:** Automatically save and load records using binary file handling.
- **Input Validation:** Handle invalid inputs and prevent duplicate book IDs.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Code Editor:** Visual Studio Code
- **Storage:** Binary file handling
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`

## 📂 Project Structure

```
LibraryManagementSystem/
│
├── library.c       # Main C source code
├── library.exe     # Compiled executable (optional)
├── library.dat     # Library database (generated automatically)
└── README.md       # Project documentation
```

## ⚙️ Installation and Execution

### 1. Clone the Repository

```bash
git clone https://github.com/MokshitChauhan/LibraryManagementSystem.git
```

### 2. Navigate to the Project Directory

```bash
cd LibraryManagementSystem
```

### 3. Compile the Program

Make sure GCC is installed.

```bash
gcc library.c -o library.exe
```

### 4. Run the Program

**Windows (PowerShell):**

```powershell
.\library.exe
```

**Linux / macOS:**

```bash
gcc library.c -o library
./library
```

## 🖥️ Application Menu

```text
========================================
       LIBRARY MANAGEMENT SYSTEM
========================================

--------------- MENU ----------------
1. Add New Book
2. Display All Books
3. Search Book
4. Issue Book
5. Return Book
6. Delete Book
7. Display Available Books
8. Save Data
9. Exit
-------------------------------------
Enter your choice:
```
<img width="2133" height="1266" alt="image" src="https://github.com/user-attachments/assets/5f7492b5-7602-49e2-83c1-0b66e5148809" />
<img width="1968" height="408" alt="image" src="https://github.com/user-attachments/assets/3afbcd3d-8783-4ef9-8893-189cfccc5746" />
<img width="1884" height="546" alt="image" src="https://github.com/user-attachments/assets/28a632d2-ddec-486b-9747-dd96931f44f6" />
<img width="1806" height="405" alt="image" src="https://github.com/user-attachments/assets/f3f19203-15c7-49f1-a268-ebadea2f273a" />
<img width="2280" height="366" alt="image" src="https://github.com/user-attachments/assets/eeb8c9b9-6e99-41cc-be98-bf9cd74eebea" />
<img width="1752" height="261" alt="image" src="https://github.com/user-attachments/assets/a8ca5364-37e6-49ff-86c6-be241163d3e5" />
<img width="2265" height="420" alt="image" src="https://github.com/user-attachments/assets/069e669f-2cbd-4359-ba46-0056b639ff86" />
<img width="1482" height="153" alt="image" src="https://github.com/user-attachments/assets/eeb1e4d4-e82f-4e62-a269-710b923bceb3" />
<img width="1665" height="180" alt="image" src="https://github.com/user-attachments/assets/086e3c1c-0c0e-4e2d-9192-e183abdf3f6e" />


## 💾 Data Storage

The application uses binary file handling to store library records in `library.dat`.

The following functions are used:

- `fopen()` – Opens the database file.
- `fread()` – Reads previously stored records.
- `fwrite()` – Writes records into the file.
- `fclose()` – Closes the file.

This allows book records to remain available even after the application is closed.

## 📖 C Programming Concepts Demonstrated

This project covers concepts from all three units of the C programming syllabus.

| Unit | Concepts |
|---|---|
| Unit I | Variables, data types, operators, conditional statements, loops |
| Unit II | Arrays, strings, searching, pointers |
| Unit III | Functions, structures, file handling, preprocessor directives |

### Important Concepts Used

- Structures (`struct Book`)
- One-dimensional arrays
- String manipulation
- User-defined functions
- `switch-case` statements
- `for` and `do-while` loops
- Searching using linear search
- Binary file operations
- Preprocessor directives (`#include`, `#define`)

## 🔮 Future Improvements

Possible enhancements for future versions include:

- Student and library member registration.
- Individual borrower records.
- Book issue dates and return deadlines.
- Automatic overdue fine calculation.
- Sorting books by title or ID.
- Dynamic memory allocation.
- Improved database backup and recovery.
- A graphical user interface.

## ⚠️ Current Limitations

- The system supports a maximum of 500 book records.
- It does not maintain individual borrower information.
- It does not store individual issue and return transaction histories.
- Data is stored locally in a binary file.
- It is designed as an educational project rather than a production library system.

## 👨‍💻 Author

Mokshit

C Programming Project | Library Management System

---

⭐ If you find this project useful, consider giving the repository a star!
