# Library Management System

## Overview

This is a simple console-based Library Management System implemented in C++. The program allows users to manage a collection of fiction and non-fiction books, enabling operations such as adding, removing, searching, borrowing, and returning books.

## Features

- **Add Books:** Supports adding fiction and non-fiction books to the library.
- **Remove Books:** Remove books by title or ISBN.
- **Search Books:** Search for books using title or ISBN.
- **Borrow Books:** Allows users to borrow books, maintaining a borrowing history.
- **Return Books:** Users can return borrowed books.
- **Recently Added Books:** Displays the last five books added to the library.
- **Display All Books:** Lists all books currently available in the library.

## Installation

1. Clone this repository:
   ```sh
   git clone <repository_url>
   ```
2. Navigate to the project directory:
   ```sh
   cd <repository_directory>
   ```
3. Compile the program using a C++ compiler:
   ```sh
   g++ -o library_management ConsoleApplication5.cpp
   ```
4. Run the program:
   ```sh
   ./library_management
   ```

## Usage

1. Run the program.
2. Choose an option from the menu:
   - `1`: Add a new book
   - `2`: Remove a book
   - `3`: Search for a book
   - `4`: Borrow a book
   - `5`: Display recently added books
   - `6`: Display borrowing history
   - `7`: Display all books
   - `8`: Exit the program
   - `9`: Return a borrowed book
3. Follow the prompts to complete the desired action.

## Dependencies

- Standard C++ libraries (`iostream`, `vector`, `queue`, `string`, `cmath`, `algorithm`)

## Future Improvements

- Implement a file-based database to persist book records.
- Improve UI with a graphical interface.
- Enhance search functionality with more filters.
- Add user authentication for borrowing and returning books.


