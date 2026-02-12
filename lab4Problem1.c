#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if filename is provided as command line argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    
    char buffer[11];  // 10 characters + 1 null terminator
    int index = 0;
    int ch;
    
    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Check if character is printable
        if (isprint(ch)) {
            buffer[index] = ch;
        } else {
            // Replace non-printable character with '.'
            buffer[index] = '.';
        }
        
        index++;
        
        // If array is full (10 characters), print and reset
        if (index == 10) {
            buffer[index] = '\0';  // Add null terminator
            printf("%s\n", buffer);
            index = 0;  // Reset index
        }
    }
    
    // Handle remaining characters at end of file
    if (index > 0) {
        buffer[index] = '\0';  // Add null terminator
        printf("%s\n", buffer);
    }
    
    // Close file
    fclose(file);
    
    return 0;
}