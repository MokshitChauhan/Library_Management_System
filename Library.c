
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 500
#define DATA_FILE "library.dat"

typedef struct {
    int id;
    char title[100];
    char author[100];
    int totalCopies;
    int availableCopies;
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

/* Function declarations */
void loadBooks(void);
void saveBooks(void);
void addBook(void);
void displayBooks(void);
void searchBook(void);
void issueBook(void);
void returnBook(void);
void deleteBook(void);
void displayAvailableBooks(void);
int findBookIndex(int id);
void clearInputBuffer(void);
void readLine(char text[], int size);

/* Clear remaining characters from the input line */
void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* Discard input */
    }
}

/* Safely read a line of text */
void readLine(char text[], int size)
{
    if (fgets(text, size, stdin) != NULL) {
        size_t length = strlen(text);

        if (length > 0 && text[length - 1] == '\n') {
            text[length - 1] = '\0';
        } else {
            clearInputBuffer();
        }
    } else {
        text[0] = '\0';
    }
}

/* Find a book using its ID */
int findBookIndex(int id)
{
    int i;

    for (i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            return i;
        }
    }

    return -1;
}

/* Load previously saved books */
void loadBooks(void)
{
    FILE *fp = fopen(DATA_FILE, "rb");

    if (fp == NULL) {
        return;
    }

    size_t count = fread(&bookCount, sizeof(bookCount), 1, fp);

    if (count != 1 || bookCount < 0 || bookCount > MAX_BOOKS) {
        bookCount = 0;
        fclose(fp);
        printf("Warning: Invalid library data. Starting empty.\n");
        return;
    }

    if (bookCount > 0 &&
        fread(books, sizeof(Book), (size_t)bookCount, fp)
        != (size_t)bookCount) {
        bookCount = 0;
        printf("Warning: Could not read all library records.\n");
    }

    fclose(fp);
}

/* Save books to a binary file */
void saveBooks(void)
{
    FILE *fp = fopen(DATA_FILE, "wb");

    if (fp == NULL) {
        printf("Error: Could not save library data.\n");
        return;
    }

    if (fwrite(&bookCount, sizeof(bookCount), 1, fp) != 1 ||
        (bookCount > 0 &&
         fwrite(books, sizeof(Book), (size_t)bookCount, fp)
         != (size_t)bookCount)) {
        printf("Error: Could not write all library records.\n");
        fclose(fp);
        return;
    }

    if (fclose(fp) != 0) {
        printf("Error: Could not finish saving library data.\n");
        return;
    }

    printf("Library data saved successfully.\n");
}

/* Add a new book */
void addBook(void)
{
    Book newBook;

    if (bookCount >= MAX_BOOKS) {
        printf("Library storage is full!\n");
        return;
    }

    printf("\n--- Add New Book ---\n");

    printf("Enter Book ID: ");

    if (scanf("%d", &newBook.id) != 1) {
        printf("Invalid ID. Enter a whole number.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (newBook.id <= 0) {
        printf("Book ID must be positive.\n");
        return;
    }

    if (findBookIndex(newBook.id) != -1) {
        printf("A book with this ID already exists.\n");
        return;
    }

    printf("Enter Book Title: ");
    readLine(newBook.title, sizeof(newBook.title));

    if (newBook.title[0] == '\0') {
        printf("Title cannot be empty.\n");
        return;
    }

    printf("Enter Author Name: ");
    readLine(newBook.author, sizeof(newBook.author));

    if (newBook.author[0] == '\0') {
        printf("Author name cannot be empty.\n");
        return;
    }

    printf("Enter Total Copies: ");

    if (scanf("%d", &newBook.totalCopies) != 1) {
        printf("Invalid number of copies.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (newBook.totalCopies <= 0) {
        printf("Total copies must be greater than zero.\n");
        return;
    }

    newBook.availableCopies = newBook.totalCopies;

    books[bookCount] = newBook;
    bookCount++;

    saveBooks();

    printf("Book added successfully!\n");
}

/* Display all books */
void displayBooks(void)
{
    int i;

    printf("\n================ ALL BOOKS ================\n");

    if (bookCount == 0) {
        printf("No books found in the library.\n");
        return;
    }

    printf("%-8s %-25s %-20s %-10s %-10s\n",
           "ID", "TITLE", "AUTHOR", "TOTAL", "AVAILABLE");

    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < bookCount; i++) {
        printf("%-8d %-25.25s %-20.20s %-10d %-10d\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].totalCopies,
               books[i].availableCopies);
    }
}

/* Search for a book */
void searchBook(void)
{
    int id;
    int index;

    printf("\nEnter Book ID to search: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    index = findBookIndex(id);

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("\nBook Found!\n");
    printf("Book ID         : %d\n", books[index].id);
    printf("Title           : %s\n", books[index].title);
    printf("Author          : %s\n", books[index].author);
    printf("Total Copies    : %d\n", books[index].totalCopies);
    printf("Available Copies: %d\n", books[index].availableCopies);
}

/* Issue a book */
void issueBook(void)
{
    int id;
    int index;

    printf("\nEnter Book ID to issue: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    index = findBookIndex(id);

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (books[index].availableCopies <= 0) {
        printf("Sorry, no copies are currently available.\n");
        return;
    }

    books[index].availableCopies--;

    saveBooks();

    printf("Book issued successfully!\n");
    printf("Book Title: %s\n", books[index].title);
    printf("Remaining Copies: %d\n",
           books[index].availableCopies);
}

/* Return a book */
void returnBook(void)
{
    int id;
    int index;

    printf("\nEnter Book ID to return: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    index = findBookIndex(id);

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (books[index].availableCopies >= books[index].totalCopies) {
        printf("All copies are already in the library.\n");
        return;
    }

    books[index].availableCopies++;

    saveBooks();

    printf("Book returned successfully!\n");
    printf("Book Title: %s\n", books[index].title);
    printf("Available Copies: %d\n",
           books[index].availableCopies);
}

/* Delete a book */
void deleteBook(void)
{
    int id;
    int index;
    int i;
    char confirm;

    printf("\nEnter Book ID to delete: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    index = findBookIndex(id);

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (books[index].availableCopies != books[index].totalCopies) {
        printf("Cannot delete this book because copies are issued.\n");
        return;
    }

    printf("Book Title: %s\n", books[index].title);
    printf("Confirm deletion? (y/n): ");

    if (scanf(" %c", &confirm) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (confirm != 'y' && confirm != 'Y') {
        printf("Deletion cancelled.\n");
        return;
    }

    for (i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }

    bookCount--;

    saveBooks();

    printf("Book deleted successfully!\n");
}

/* Display books that have available copies */
void displayAvailableBooks(void)
{
    int i;
    int found = 0;

    printf("\n========== AVAILABLE BOOKS ==========\n");

    printf("%-8s %-25s %-20s %-10s\n",
           "ID", "TITLE", "AUTHOR", "AVAILABLE");

    for (i = 0; i < bookCount; i++) {
        if (books[i].availableCopies > 0) {
            printf("%-8d %-25.25s %-20.20s %-10d\n",
                   books[i].id,
                   books[i].title,
                   books[i].author,
                   books[i].availableCopies);

            found = 1;
        }
    }

    if (!found) {
        printf("No books are currently available.\n");
    }
}

/* Main program */
int main(void)
{
    int choice;

    loadBooks();

    printf("========================================\n");
    printf("       LIBRARY MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    do {
        printf("\n--------------- MENU ----------------\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Display Available Books\n");
        printf("8. Save Data\n");
        printf("9. Exit\n");
        printf("-------------------------------------\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number from 1 to 9.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                displayAvailableBooks();
                break;

            case 8:
                saveBooks();
                break;

            case 9:
                saveBooks();
                printf("Thank you for using the Library Management System!\n");
                break;

            default:
                printf("Invalid choice. Please select 1 to 9.\n");
        }

    } while (choice != 9);

    return 0;
}
