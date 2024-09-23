# Address Book in C++

## Overview

This project is a command-line address book application written in C++. The program allows users to manage contacts by adding, removing, searching, and displaying contact information. Each contact includes the following fields:

- First Name
- Other Names
- Email Address
- Phone Number
- Address (Street, Town, Country)

The program ensures that no two contacts share the same email or phone number. Additionally, the program saves and loads contact data from a file, allowing users to retain contact information between sessions.

## Features

### Core Functionality

1. **Add Contact**: 
   - Collects contact details, validates input, and ensures unique email and phone numbers.
   - If an email or phone number already exists, the user is prompted to enter a unique value.
   
2. **Remove Contact**: 
   - Allows removal of a contact by entering their email. If the email is not found, the user can retry or cancel the operation.
   
3. **Search Contacts**: 
   - Search for contacts by First Name, Other Names, Email Address, Phone Number, Town, or Country.
   
4. **Display All Contacts**: 
   - Displays all stored contacts in a neatly formatted table.
   
5. **File Persistence**: 
   - Contacts are saved to a file (`addressbook.txt`) when the program exits, and loaded from the same file when it starts up.
   
6. **Memory Leak Detection**: 
   - Memory leak detection is enabled in debug mode using `_CrtSetDbgFlag` and `_CrtDumpMemoryLeaks`.

### Input Validation

- **Email**: Must contain an `@` symbol and a valid domain.
- **Phone Number**: Must be numeric and between 7-15 digits, and it must be unique.
- **Required Fields**: All fields (First Name, Other Names, Street, Town, Country) are mandatory and must not be left empty.
- **Case-Insensitive Matching**: All inputs are normalized to lowercase for consistency during searches.

### Performance Optimizations

- **Fast Lookups**: Uses `std::unordered_map` for efficient retrieval of contacts by email, phone number, and other indexed fields (e.g., first name, town).
- **Multiple Indexes**: The program maintains indexes on several fields (first name, phone number, town, country) for fast searching.

## Challenges & Solutions

### 1. **Unique Email and Phone Numbers**

- **Problem**: It was necessary to enforce the uniqueness of email and phone numbers, while allowing contacts to have identical names.
- **Solution**: Both email and phone number fields are checked for uniqueness during the contact addition process using `EmailExists` and `PhoneExists` functions. These ensure that no two contacts have the same email or phone number.

### 2. **Input Validation & Infinite Loop Prevention**

- **Problem**: The program initially allowed multiple invalid inputs like `1 2 3` in a single line, leading to skipped fields and potentially empty inputs. Invalid inputs also caused infinite loops.
- **Solution**: Input handling was fixed by using `do-while` loops, ensuring valid, non-empty inputs for all required fields. This approach improves robustness and guarantees correct data validation.

### 3. **Case Insensitivity**

- **Problem**: Searches could fail due to case mismatches in the input.
- **Solution**: The program normalizes all inputs to lowercase using the `ToLower` utility function, ensuring uniformity across search queries and storage. This allows for case-insensitive searches.

### 4. **Memory Management**

- **Problem**: Memory leaks were a concern in long-running programs, especially when adding and removing contacts frequently.
- **Solution**: Memory leak detection was added by using `_CrtSetDbgFlag` and `_CrtDumpMemoryLeaks` during development. Testing was performed to ensure there are no memory leaks when contacts are added, removed, or modified.

### 5. **Handling Duplicate Entries**

- **Problem**: Duplicate email or phone numbers could corrupt data integrity.
- **Solution**: The program strictly checks for duplicate email and phone numbers before allowing a contact to be added. If either exists, the user is prompted to re-enter unique values.

### 6. **Exit Mechanism During Removal**

- **Problem**: If the user did not provide an email during removal, there was no way to exit the operation.
- **Solution**: The program now includes an "exit" option during the removal process, allowing users to cancel the operation by typing 'exit'.

### 7. **Efficient Search Mechanism**

- **Problem**: Searching large datasets can be slow and inefficient.
- **Solution**: The program uses multiple indexes on fields such as first name, phone number, and town to allow fast searching. This eliminates the need for a full list traversal during searches.

## Known Limitations & Future Enhancements

### If I Had 1-2 More Weeks

1. **Wildcard or Partial Matching Search**: 
   - Currently, the search only supports exact matches. Adding partial or wildcard matching (e.g., searching for "Jo*" to match "John" or "Jonas") would make the search more flexible.

2. **Pagination for Large Datasets**: 
   - If the address book contains a large number of entries, displaying all contacts in one view can be overwhelming. Adding pagination to display a fixed number of contacts per page (e.g., 10 at a time) would improve user experience.

3. **Enhanced Input Validation**: 
   - Implement more comprehensive validation for international phone numbers and address formats, ensuring proper handling of different locales and number formats.

4. **Improved File Format**: 
   - Transition from a simple comma-separated values (CSV) format to a more structured format like JSON or XML. This would allow easier data parsing and improve extensibility for future features such as nested addresses or contact groups.

5. **Search History**: 
   - Implement a feature that allows users to review or revisit their recent searches, adding convenience for users who frequently search the same terms.

6. **User Interface Enhancements (Non-Console)**: 
   - Explore a graphical interface (GUI) using a C++ framework like Qt to create a more user-friendly visual interface, making the application accessible to users less familiar with the command line.


