# File Handling

## Overview
This lab focuses on understanding and implementing file handling operations in C. The assignment consists of two problems that demonstrate reading files, parsing data, and validating user input.

---

## Problem 1: Character-by-Character File Reader

### Description
`lab4Problem1.c` reads a file character by character and displays its contents in chunks of 10 characters per line. Non-printable characters (like newlines, tabs, etc.) are replaced with a period (`.`).

### Features
- Reads file character by character using `fgetc()`
- Uses `isprint()` to check if characters are printable
- Replaces non-printable characters with '.'
- Stores characters in a buffer of size 11 (10 chars + null terminator)
- Prints the buffer when full or at end of file
- Accepts filename as command-line argument

### Compilation
```bash
gcc lab4Problem1.c -o lab4Problem1
```

### Usage
```bash
./lab4Problem1 <filename>
```

### Example
```bash
./lab4Problem1 sample.txt
```

**Output:**
```
This is an
 example t
ext..This 
is another
 line.
```

Note: The newline characters in the original file are replaced with periods.

---

## Problem 2: User Authentication System

### Description
`lab4Problem2.c` implements a simple authentication system that validates user credentials against a data file (`userdata.txt`) and displays associated account balance information.

### Features
- Prompts user for username and password
- Reads and parses `userdata.txt` line by line
- Uses `sscanf()` to extract username, password, and numerical data
- Compares credentials using `strcmp()`
- Displays account balance on successful authentication
- Shows error message on failed authentication

### File Format
The `userdata.txt` file should contain one user per line in the format:
```
username password amount
```

Example:
```
user1 password1 75000.00
user2 password2 45950.75
user3 password3 65230.75
```

### Compilation
```bash
gcc lab4Problem2.c -o lab4Problem2
```

### Usage
```bash
./lab4Problem2
```

The program will prompt for username and password:
```
Username: user2
Password: password2
The amount is: 45950.75
```

### Example - Failed Authentication
```
Username: user5
Password: wrongpassword
username/password mismatch!!!
```

---

## File Descriptions

### Source Files
- **lab4Problem1.c** - Character-by-character file reader
- **lab4Problem2.c** - User authentication system

### Data Files
- **sample.txt** - Sample input file for Problem 1
- **userdata.txt** - User credentials database for Problem 2

---

## Implementation Details

### Problem 1 Technical Details
- **Buffer Size**: 11 characters (10 data + 1 null terminator)
- **Character Check**: Uses `isprint()` from `<ctype.h>`
- **File Operations**: `fopen()`, `fgetc()`, `fclose()`
- **Command-line Arguments**: `argc` and `argv[]`

### Problem 2 Technical Details
- **String Limits**: Username and password max length of 20 characters
- **Numerical Range**: Amount values between 1 and 10^7
- **Parsing**: Uses `sscanf()` to parse formatted text
- **String Comparison**: Uses `strcmp()` for exact matching

---

## Constraints

### Problem 1
- Must handle files of any size
- Must properly handle end-of-file
- Must close file before program termination
- Filename must be provided as command-line argument

### Problem 2
- 1 ≤ len(username) ≤ 20
- 1 ≤ len(password) ≤ 20
- 1 ≤ numerical data ≤ 10^7
- Must close file before program termination

---

## Common Issues and Solutions

### Problem 1
**Issue**: Program doesn't compile
- **Solution**: Ensure you include `<ctype.h>` for `isprint()`

**Issue**: File not found error
- **Solution**: Provide the full path to the file or ensure the file is in the current directory

**Issue**: Newlines showing as regular characters
- **Solution**: The program is working correctly - newlines are non-printable and should appear as '.'

### Problem 2
**Issue**: File not found error
- **Solution**: Ensure `userdata.txt` is in the same directory as the executable

**Issue**: Authentication always fails
- **Solution**: Check that userdata.txt format is correct (username password amount with spaces)

**Issue**: Amount not displaying correctly
- **Solution**: Verify the format specifier is `%.2f` for two decimal places

---

## Testing

### Test Problem 1
Create a test file with various characters:
```bash
echo -e "This is an example text.\nThis is another line." > sample.txt
./lab4Problem1 sample.txt
```

### Test Problem 2
Create a userdata.txt file:
```bash
cat > userdata.txt << EOF
user1 password1 75000.00
user2 password2 45950.75
user3 password3 65230.75
EOF
./lab4Problem2
```

Then test with:
- Valid credentials (should display amount)
- Invalid username (should show mismatch message)
- Invalid password (should show mismatch message)

---

## Grading Rubric

### Problem 1 (50 points)
- ✓ Correctly handles printable/non-printable characters
- ✓ Reads until End of File (EOF)
- ✓ Prints when array is full
- ✓ Closes file before program termination
- ✓ Prints newline as '.' character
- ✓ Gets filename as command-line argument
- ✓ Prints file content in requested format
- ✓ Source code named correctly (lab4Problem1.c)

### Problem 2 (50 points)
- ✓ Closes file before program termination
- ✓ Correctly validates password match
- ✓ Prints associated numerical data after credential match
- ✓ Prints correct numerical data
- ✓ Reads valid input of maximum length
- ✓ Source code named correctly (lab4Problem2.c)

---

## Resources

- [File Handling in C - Tutorial](https://www.tutorialspoint.com/basics-of-file-handling-in-c)
- [isprint() Function](https://www.tutorialspoint.com/c_standard_library/c_function_isprint.htm)
- [sscanf() Function](https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm)

---
