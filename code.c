#include <stdio.h>
#include <stdlib.h>

#define MIN_GRADE 0
#define MAX_GRADE 100

float calculateAverage(int grades[], int numStudents) {
    float sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += grades[i];
    }
    return numStudents > 0 ? sum / numStudents : 0;
}

int findHighest(int grades[], int numStudents) {
    int highest = grades[0];
    for (int i = 1; i < numStudents; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
        }
    }
    return highest;
}

int findLowest(int grades[], int numStudents) {
    int lowest = grades[0];
    for (int i = 1; i < numStudents; i++) {
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    return lowest;
}

int main() {
    int *grades;
    int numStudents, choice;

    printf("\nStudent Grade Book\n");
    printf("------------------\n");

    while (1) {
        printf("Enter the number of students: ");
        if (scanf("%d", &numStudents) != 1 || numStudents <= 0) {
            printf("Invalid input. Please enter a valid positive number.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }

    grades = (int*) malloc(numStudents * sizeof(int));
    if (grades == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        while (1) {
            printf("Enter the grade for Student %d (0-100): ", i + 1);
            if (scanf("%d", &grades[i]) != 1 || grades[i] < MIN_GRADE || grades[i] > MAX_GRADE) {
                printf("Invalid input. Please enter a grade between 0 and 100.\n");
                while (getchar() != '\n');
            } else {
                break;
            }
        }
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Calculate Average\n");
        printf("2. Find Highest Score\n");
        printf("3. Find Lowest Score\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nAverage Grade: %.2f\n", calculateAverage(grades, numStudents));
                break;
            case 2:
                printf("\nHighest Score: %d\n", findHighest(grades, numStudents));
                break;
            case 3:
                printf("\nLowest Score: %d\n", findLowest(grades, numStudents));
                break;
            case 4:
                printf("\nExiting Student Grade Book.\n");
                free(grades);
                return 0;
            default:
                printf("Invalid choice. Please select a number between 1 and 4.\n");
        }
    }

    return 0;
}
