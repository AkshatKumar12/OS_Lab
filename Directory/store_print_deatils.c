#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int main() {
    FILE *f1, *f2;
    char line1[MAX], line2[MAX];

    // Step 1: Write your details
    f1 = fopen("mydetails.txt", "w");
    if (!f1) { perror("fopen"); exit(1); }
    fprintf(f1, "Name: Akshat\n");
    fprintf(f1, "Roll: 12345\n");
    fprintf(f1, "Course: B.Tech CSE\n");
    fclose(f1);

    // Step 2: Write friend's details
    f2 = fopen("frienddetails.txt", "w");
    if (!f2) { perror("fopen"); exit(1); }
    fprintf(f2, "Name: Rahul\n");
    fprintf(f2, "Roll: 12345\n"); // matching roll
    fprintf(f2, "Course: B.Tech ECE\n");
    fclose(f2);

    // Step 3: Compare files line by line
    f1 = fopen("mydetails.txt", "r");
    f2 = fopen("frienddetails.txt", "r");
    if (!f1 || !f2) { perror("fopen"); exit(1); }

    printf("\nMatching lines in both files:\n");
    while (fgets(line1, MAX, f1)) {
        rewind(f2); // go back to start of friend's file
        while (fgets(line2, MAX, f2)) {
            if (strcmp(line1, line2) == 0) {
                printf("%s", line1);
            }
        }
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
