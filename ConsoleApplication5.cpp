#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include<queue>
#include <algorithm>
using namespace std;

class Book {
public:
    string Book_title, Author;
    string ISBN; 

    Book() : Book_title(""), Author(""), ISBN("") {}

    Book(string t, string A, string isbn) {
        Book_title = t;
        Author = A;
        ISBN = isbn;
    }

    void display() {
        cout << "Book title: " << Book_title << "\n"
            << "Author: " << Author << "\n"
            << "ISBN: " << ISBN << endl;
    }
};

class fiction : public Book {
public:
    fiction(string t, string A, string isbn) {
        t = "";
        A = "";
        isbn = "";
    }

    void display() {
        Book::display();
    }
};

class nunfiction : public Book {
public:
    nunfiction(string t, string A, string isbn) {
    
        t = "";
        A = "";
        isbn = "";

    }

    void display() {
        Book::display();
    }
};

class node : protected Book {
private:
    struct Node {
        fiction* book;
        Node* next;
    };
    struct nunfictionnode {
        nunfiction* book;
        nunfictionnode* next;
        nunfictionnode* prev;

    };

    Node* head = NULL;
    Node* last = NULL;
    nunfictionnode* head1 = NULL;
    nunfictionnode* last1 = NULL;
public:
    void addbook(fiction* book) {
        Node* newnode = new Node;
        newnode->book = book;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        }
        else {
            last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newnode;
        }
    }

    void addbook(nunfiction* book) {
        nunfictionnode* Newnode = new nunfictionnode;
        Newnode->book = book;
        Newnode->next = NULL;
        Newnode->prev = NULL;
        

        if (head1 == NULL) {
            head1 = Newnode;
            last1 = Newnode;
        }
        else {
            last1->next = Newnode;
            Newnode->prev = last1;
            last1 = Newnode;
        }
    }

    void search(string searchid) {
        Node* osama = head;
        while (osama != NULL) {
            if (osama->book->Book_title == searchid || osama->book->ISBN == searchid) {
                cout << "Book found:\n";
                osama->book->display();
                return;
            }
            osama = osama->next; 
        }
        cout << "Sorry, no book matches.\n";
    }
    void search1(string searchId) {
        nunfictionnode* sanker = head1;
        while (sanker != NULL) {
            if (sanker->book->Book_title == searchId||sanker->book->Book_title==searchId) {
                cout << "Book founded\n";
                sanker->book->display();
                return;
            }
           sanker= sanker->next;
        }
        cout << "Sorry, no book matches.\n";
    }
    void remove(string bookname) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL&&temp->book->Book_title!=bookname) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
            if (prev == NULL) {
                head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
        }
    }
    void remove1(string bookname) {
        nunfictionnode* temp = head1;

        while (temp != NULL && temp->book->Book_title != bookname) {
            temp = temp->next;
        }

        if (temp != NULL) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            else {
                head1 = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            else {
                last1 = temp->prev;
            }

            delete temp;
        }
    }
    void displayBooks() {
        Node* current = head;
        nunfictionnode* currentNonFiction = head1;
        while (current != NULL) {
            current->book->display();
            current = current->next;
        }
        while (currentNonFiction != NULL) {
            currentNonFiction->book->display();
            currentNonFiction = currentNonFiction->next;
        }
    }
};
class RecentlyAddedStack {
private:
    struct Node {
        string bookTitle;
        Node* next;
    };

    Node* top;
    int currentSize;
    const int maxSize = 5;

public:
    RecentlyAddedStack() : top(nullptr), currentSize(0) {}

    void pushBook(const string& bookTitle) {
        if (currentSize == maxSize) {
            popBook();
        }
        Node* newNode = new Node{ bookTitle, top };
        top = newNode;
        currentSize++;
    }

    void popBook() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
            currentSize--;
        }
    }

    void displayRecentBooks() {
        if (top == nullptr) {
            cout << "No recently added books.\n";
            return;
        }

        cout << "Recently added books:\n";
        Node* current = top;
        while (current != nullptr) {
            cout << "- " << current->bookTitle << "\n";
            current = current->next;
        }
    }

    ~RecentlyAddedStack() {
        while (top != nullptr) {
            popBook();
        }
    }
};
class BorrowQueue {
private:
    queue<string> borrowQueue;
    queue<string> tempqueue;

    int maxSize = 10;

public:
    void enqueueBook( string bookTitle) {
        if (borrowQueue.size() == maxSize) {
            borrowQueue.pop();
        }
        borrowQueue.push(bookTitle);
    }

    void dequeueBook(string booktitle) {

        while(!borrowQueue.empty()) {
            if (borrowQueue.front() != booktitle) {
                tempqueue.push(borrowQueue.front());
                borrowQueue.pop();
            }
        }
        borrowQueue = tempqueue;
    }

    void displayBorrowedBooks() {
        if (borrowQueue.empty()) {
            cout << "No books in the borrowing history.\n" ;
            return;
        }
        cout << "Borrowing history:\n";
        queue<string> tempQueue = borrowQueue;
        while (!tempQueue.empty()) {
            cout << "- " << tempQueue.front() << "\n";
            tempQueue.pop();
        }
    }
};
class Library {
private:
    node fictionList;
    node nonFictionList;
    RecentlyAddedStack recentBooks;
    BorrowQueue borrowQueue;

public:
    void addBook(int bookKind, string title, string author, string isbn) {
        if (bookKind == 1) {
            fictionList.addbook(new fiction(title, author, isbn));
            recentBooks.pushBook(title);
            cout << "Fiction book added successfully!\n";
        }
        else if (bookKind == 2) {
            nonFictionList.addbook(new nunfiction(title, author, isbn));
            recentBooks.pushBook(title);
            cout << "Non-Fiction book added successfully!\n";
        }
        else {
            cout << "Invalid book type!\n";
        }
    }

    void removeBook(int bookKind, string key) {
        if (bookKind == 1) {
            fictionList.remove(key);
            cout << "Fiction book removed successfully!\n";
        }
        else if (bookKind == 2) {
            nonFictionList.remove1(key);
            cout << "Non-Fiction book removed successfully!\n";
        }
        else {
            cout << "Invalid book type!\n";
        }
    }

    void searchBook(int bookkind, string key) {
        if (bookkind == 1) {
            fictionList.search(key);
        }
        else if (bookkind == 2) {
            nonFictionList.search1(key);
        }
        else {
            cout << "Invalid book type!\n";
        }
    }

    void borrowBook(int bookkind, string title) {
        if (bookkind == 1) {
            fictionList.remove(title);
        }
        else if (bookkind == 2) {
            nonFictionList.remove1(title);
        }
        else {
            cout << "Invalid book type!\n";
            return;
        }
        borrowQueue.enqueueBook(title);
        cout << "Book borrowed successfully!\n";
    }
    void Ruternbook(int bookkind, string title,string author,string isbn) {
        if (bookkind == 1) {
            fictionList.addbook(new fiction(title, author, isbn));
        }
        else if (bookkind == 2) {
            nonFictionList.addbook(new nunfiction(title, author, isbn));
        }
        else {
            cout << "Invalid book type!\n";
            return;
        }
        borrowQueue.dequeueBook(title);
        cout << "Book returned successfully!\n";

    }

    void displayRecentBooks() {
        recentBooks.displayRecentBooks();
    }

    void displayBorrowedBooks() {
        borrowQueue.displayBorrowedBooks();
    }

    void displayAllBooks() {
        cout << "Fiction Books:\n";
        fictionList.displayBooks();
        cout << "\nNonFiction Books:\n";
        nonFictionList.displayBooks();
    }
};


int main() {
    Library library;
    int choice = 0;

    cout <<                         "Welcome to the Library Management System!\n";
    cout << "\nOptions:\n"
        << "1. Add Book\n"
        << "2. Remove Book\n"
        << "3. Search for a Book\n"
        << "4. Borrow Book\n"
        << "5. Display Recently Added Books\n"
        << "6. Display Borrowing History\n"
        << "7. Display All Books\n"
        << "8. Exit\n";

    while (choice != 8) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int bookKind;
            string title, author, isbn;
            cout << "Enter book type (1: Fiction, 2: Non-Fiction): ";
            cin >> bookKind;
            cin.ignore();
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            library.addBook(bookKind, title, author, isbn);
        }
        else if (choice == 2) {
            int bookKind;
            string identifier;
            cout << "Enter book type (1: Fiction, 2: Non-Fiction): ";
            cin >> bookKind;
            cin.ignore();
            cout << "Enter title or ISBN to remove: ";
            getline(cin, identifier);
            library.removeBook(bookKind, identifier);
        }
        else if (choice == 3) {
            int bookKind;
            string identifier;
            cout << "Enter book type (1: Fiction, 2: Non-Fiction): ";
            cin >> bookKind;
            cin.ignore();
            cout << "Enter title or ISBN to search: ";
            getline(cin, identifier);
            library.searchBook(bookKind, identifier);
        }
        else if (choice == 4) {
            int bookKind;
            string title;
            cout << "Enter book type (1: Fiction, 2: Non-Fiction): ";
            cin >> bookKind;
            cin.ignore();
            cout << "Enter title to borrow: ";
            getline(cin, title);
            library.borrowBook(bookKind, title);
        }
        else if (choice == 5) {
            library.displayRecentBooks();
        }
        else if (choice == 6) {
            library.displayBorrowedBooks();
        }
        else if (choice == 7) {
            library.displayAllBooks();
        }
        else if (choice == 8) {
            cout << "Goodbye! Thanks for visiting us!\n";
        }
        else if (choice == 9) {
            int bookKind;
            string title, author, isbn;
            cout << "Enter book type (1: Fiction, 2: Non-Fiction): ";
            cin >> bookKind;
            cin.ignore();
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            library.Ruternbook(bookKind, title, author, isbn);
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
