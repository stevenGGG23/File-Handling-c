#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    //Constraints (Max length 20 + null terminator)
    char input_username[21];  
    char input_password[21];  
    char file_username[21];
    char file_password[21];
    double amount;
    char line[100];
    int found = 0;
    
    // Inputs
    printf("Username: ");
    scanf("%20s", input_username);
    
    printf("Password: ");
    scanf("%20s", input_password);
    
    // Open userdata.txt file
    FILE *file = fopen("userdata.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open userdata.txt\n");
        return 1;
    }
    
    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        // Parse line using sscanf to extract username, password, and amount
        if (sscanf(line, "%20s %20s %lf", file_username, file_password, &amount) == 3) {
            // Compare with input credentials
            if (strcmp(input_username, file_username) == 0 && 
                strcmp(input_password, file_password) == 0) {
                // Match found
                printf("The amount is: %.2f\n", amount);
                found = 1;
                break;
            }
        }
    }
    
    // If no match, print error message
    if (!found) {
        printf("username/password mismatch!!!\n");
    }
    
    // Close file
    fclose(file);
    
    return 0;
}