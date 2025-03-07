#include <stdio.h>
#include <string.h>

// Define constants for username, password, and maximum login attempts
#define USERNAME "abc1"
#define PASSWORD "abc2"
#define MAX_ATTEMPTS 3 // maximum login attempts

// Function declarations to be called within the program to handle authentication and score entry
void authenticate();
void enterScores();

int main() {
    // Start the authentication process
    authenticate();
    return 0;
}

// Function to authenticate the user
void authenticate() {
    char username[20], password[20];
    int attempts = 0;

    // Allow the user to attempt login up to MAX_ATTEMPTS times
    while (attempts < MAX_ATTEMPTS) {
        // Prompt the user for username and password
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        // Check if the entered username and password match the predefined ones
        if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            printf("Login successful!\n");
            // If login is successful, allow the user to enter scores
            enterScores();
            return;
        } else {
            // If login fails, increment the attempt counter and show an error message
            printf("Invalid username or password. Try again.\n");
            attempts++;
        }
    }

    // If the maximum number of attempts is reached, log the user out
    printf("Too many failed attempts. You are logged out.\n");
}

// Function to enter scores and write them to a file
void enterScores() {
    // Open the file "marks.txt" for writing
    FILE *file = fopen("marks.txt", "w");
    if (file == NULL) {
        // If the file cannot be opened, show an error message and return
        printf("Error opening file.\n");
        return;
    }

    int score;
    char remark[30];
    int numStudents;
    int i;

    // Prompt the user to enter the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Loop through each student to enter their score
    for (int i = 0; i < numStudents; i++) {
        printf("Enter score for student %d: ", i + 1);
        scanf("%d", &score);

        // Determine the remark based on the score
        if (score >= 60) {
            strcpy(remark, "Exceeded expectation(EE)");
        } else if (score >= 50) {
            strcpy(remark, "Met expectation(ME)");
        } else if (score >= 40) {
            strcpy(remark, "Approaching expectation(AE)");
        } else {
            strcpy(remark, "Below expectation(BE)");
        }

        // Write the student's score and remark to the file
        fprintf(file, "Student %d: Score = %d, Remark = %s\n", i + 1, score, remark);
    }

    // Close the file after writing all scores and remarks
    fclose(file);
    printf("Scores and remarks have been written to marks.txt\n");
}