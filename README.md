Here’s a README formatted specifically for GitHub with proper Markdown syntax and formatting, ready for copy-pasting.

```markdown
# Address Book CLI

A command-line-based address book application built in C++ that allows users to manage contacts by adding, removing, searching, and displaying them. Each contact includes **First Name**, **Other Names**, **Email Address**, **Phone Number**, and **Address** (Street, Town, Country). The application ensures email and phone numbers are unique, and persists data between sessions by saving to a file.

## 🚀 Features

- **Add Contact**: Add a new contact, with all fields validated and email/phone numbers required to be unique.
- **Remove Contact**: Remove a contact using their email address. The removal process can be cancelled if needed.
- **Search Contact**: Search by:
  - First Name
  - Other Names
  - Email Address
  - Phone Number
  - Town
  - Country
- **Display All Contacts**: Lists all contacts in a table format.
- **File Persistence**: Saves contacts to `addressbook.txt` when the program exits, and loads them back on startup.
- **Memory Leak Detection**: Memory leak detection enabled via CRT for development.

## 📂 Project Structure

```
├── AddressBook.cpp     # Main C++ file containing all logic
├── addressbook.txt     # File where contacts are saved and loaded from
└── README.md           # This README file
```

## 🔧 Installation and Setup

### Prerequisites

- **C++11** or higher
- **g++** or any C++ compiler
- (Optional) **Visual Studio** for memory leak detection in debug mode

### Compilation

To compile the program, use the following command:

```bash
g++ -o addressbook AddressBook.cpp
```

### Running

After compiling, run the program:

```bash
./addressbook
```

### Debug Mode (Memory Leak Detection)

For debugging purposes, memory leak detection is enabled. This works in environments like Visual Studio and helps ensure efficient memory management.

## 📝 Input Validation

- **Email**: Must contain an `@` and a valid domain.
- **Phone Number**: Must be numeric and between 7-15 characters. It must also be unique.
- **Required Fields**: First name, other names, street, town, and country must all be non-empty.
- **Case Insensitivity**: All inputs are normalized to lowercase for consistent searching and matching.

## ⚡ Key Highlights

1. **Unique Email and Phone**: Both email and phone numbers are enforced as unique to ensure data integrity.
2. **Robust Input Validation**: Prevents invalid inputs, empty fields, and skips.
3. **Efficient Searching**: The use of multiple indexes (for first name, phone, etc.) enables faster lookups.
4. **Persistent Data**: Contacts are saved to `addressbook.txt` on exit and loaded back when the program starts.
5. **Memory Management**: Memory leaks are detected and debugged using `_CrtDumpMemoryLeaks()` in development.

## 🔍 Challenges & Solutions

### 1. **Duplicate Handling**
   - **Problem**: Preventing duplicate email and phone entries.
   - **Solution**: Added checks using `EmailExists` and `PhoneExists` to ensure both fields remain unique.

### 2. **Infinite Loops on Invalid Input**
   - **Problem**: The program was entering infinite loops if invalid input (like `1 2 3`) was provided.
   - **Solution**: Replaced input handling with robust validation and `do-while` loops.

### 3. **Case Insensitivity**
   - **Problem**: Searching was case-sensitive.
   - **Solution**: All inputs are converted to lowercase using `ToLower` for uniform case-insensitive comparisons.

### 4. **Ensuring Non-Empty Fields**
   - **Problem**: Users could accidentally leave fields blank.
   - **Solution**: Required fields like first name, other names, street, etc., are validated to ensure they are not left empty.

### 5. **Phone and Email Uniqueness**
   - **Problem**: Users could add contacts with the same phone number or email.
   - **Solution**: Email and phone number uniqueness is strictly enforced with relevant checks.

### 6. **Exit Mechanism in Removal**
   - **Problem**: Users couldn't cancel the removal process once started.
   - **Solution**: Added the option to type `'exit'` to cancel the operation during removal.

## 🚀 Future Enhancements

If more time was available, the following improvements would be considered:

1. **Wildcard Search**: Allow partial or wildcard-based searches.
2. **Pagination**: For better user experience when listing large numbers of contacts.
3. **International Phone Number Support**: Handle international formats and validation.
4. **Enhanced File Format**: Switch to a more structured data format (JSON, XML) for better data integrity and flexibility.
5. **Recent Searches**: Implement a history of recent search terms.

## 🛠️ Tools & Libraries Used

- **Standard C++ STL** (`<unordered_map>`, `<vector>`, `<algorithm>`) – Used for fast lookups, storage, and handling large datasets.
- **CRT Debugging** (`<crtdbg.h>`) – Enabled memory leak detection in development environments.

## ⚙️ How to Contribute

1. Fork the repository.
2. Create a new feature branch: `git checkout -b feature/your-feature`.
3. Commit your changes: `git commit -m 'Add some feature'`.
4. Push to the branch: `git push origin feature/your-feature`.
5. Submit a pull request.

## 📝 License

This project is licensed under the MIT License.
```

This README has been structured to follow GitHub Markdown conventions and includes sections that are formatted with headings, code blocks, and explanations. It's clean and straightforward, giving all the essential information without unnecessary verbosity.
