# Address Book - README

## Overview

This project is a command-line-based address book written in C++. It allows users to manage contacts by adding, removing, searching, and displaying contact information. Each contact contains the following fields:

- First Name
- Other Names
- Email Address
- Phone Number
- Address (Street, Town, Country)

Key constraints include unique emails and phone numbers for each contact. The application supports file persistence, so records are saved upon exit and loaded when the program is run again.

## Features

### Core Functionality
1. **Add Contact**: Collects contact details, validates input, and ensures unique email and phone numbers before adding a new contact.
2. **Remove Contact**: Allows the removal of a contact by their email. If the email is not found, users are prompted to re-enter or cancel the operation.
3. **Search Contacts**: Users can search by:
   - First Name
   - Other Names
   - Email Address
   - Phone Number
   - Town
   - Country
4. **Display All Contacts**: Displays all contacts in a structured table format.
5. **Save & Load from File**: The program automatically saves contacts to a file upon exit and loads them upon startup.
6. **Memory Leak Detection**: Enabled via the C runtime library in debug mode.

### Input Validation
- **Email**: Must contain an `@` symbol and a valid domain.
- **Phone Number**: Must be numeric and between 7-15 digits. It must also be unique.
- **Required Fields**: All fields (First Name, Other Names, Street, Town, Country) are mandatory and must not be left empty.
- **Case-Insensitive Matching**: To avoid case-related issues, all inputs are normalized to lowercase for searches and storage.

### Optimizations
- **Fast Lookups**: Leveraging `std::unordered_map` for fast contact retrieval by email and other indexed fields (e.g., first name, phone).
- **Multiple Indexes**: Indexes for various fields (first name, phone, town, etc.) improve search efficiency, reducing the need to iterate over all contacts.

## Challenges & Solutions

### 1. **Unique Email and Phone**
- **Problem**: Ensuring no two contacts share the same email or phone number while allowing identical names.
- **Solution**: Both the email and phone number are checked for uniqueness during contact addition using `EmailExists` and `PhoneExists` functions. These enforce unique constraints before a new record is created.

### 2. **Input Validation & Infinite Loop Prevention**
- **Problem**: Initial versions failed to handle multiple invalid inputs (like `1 2 3`) correctly, causing fields to be skipped and left empty. Invalid inputs could also cause infinite loops.
- **Solution**: Replaced input handling with `do-while` loops, ensuring valid, non-empty inputs for all required fields. A robust input validation mechanism prevents issues with invalid entries and enforces constraints on email and phone number formats.

### 3. **Case Insensitivity**
- **Problem**: Inconsistent case handling during searches and comparisons.
- **Solution**: All inputs are converted to lowercase using a utility function (`ToLower`) to ensure uniformity in search and storage, allowing for case-insensitive lookups.

### 4. **Memory Management**
- **Problem**: Memory leaks can occur in a long-running program with frequent contact additions/removals.
- **Solution**: Enabled memory leak detection with `_CrtSetDbgFlag` and `_CrtDumpMemoryLeaks` for development. The program was tested in debug mode to ensure no memory leaks occur when adding, removing, or modifying contacts.

### 5. **Duplicate Handling**
- **Problem**: Duplicate email or phone entries can corrupt data integrity.
- **Solution**: Strict uniqueness checks for both email and phone prevent duplicates. If a user attempts to add a contact with an existing email or phone number, they are prompted to re-enter valid, unique details.

### 6. **Exit Mechanism During Removal**
- **Problem**: If no email is entered during contact removal, the user had no way to cancel.
- **Solution**: Added a cancellation mechanism allowing the user to type 'exit' during the removal process to stop without making changes.

### 7. **Search Optimization**
- **Problem**: Searching over a large number of records needs to be efficient.
- **Solution**: Introduced indexes on multiple fields (`firstNameIndex`, `otherNamesIndex`, `phoneIndex`, etc.) to enable fast lookups, preventing the need for full list traversal.

## Known Limitations & Future Enhancements

### If I Had More Time
- **Wildcard Search**: Introduce wildcard-based or partial string matching in searches for more flexible user input.
- **Pagination for Large Datasets**: Add pagination support when displaying large lists of contacts, as the current format may become overwhelming with hundreds or thousands of records.
- **Enhanced Validation**: Add more robust validation for international phone numbers and address formats.
- **Enhanced File Format**: Move from the current comma-separated values (CSV) format to a more structured format like JSON or XML for better extensibility and data integrity.
- **Search History**: Implement a feature to allow users to review recent searches.

