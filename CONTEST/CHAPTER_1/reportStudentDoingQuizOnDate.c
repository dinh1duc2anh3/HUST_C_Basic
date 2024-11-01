#include <stdio.h>
#include <string.h>

#define MAX_DATE_LENGTH 11 // Length of the date format "yyyy-mm-dd"

// Structure to represent a date
struct Date {
    int year, month, day;
};

// Function to compare two dates
int compareDates(struct Date date1, struct Date date2) {
    if (date1.year != date2.year)
        return date1.year - date2.year;
    if (date1.month != date2.month)
        return date1.month - date2.month;
    return date1.day - date2.day;
}

int main() {
    char dateStr[MAX_DATE_LENGTH + 1]; // Buffer to store date string
    struct Date currentDate, lastDate;

    int count = 0;

    while (1) {
        scanf("%s", dateStr);

        // Check for the end of input
        if (dateStr[0] == '*')
            break;

        scanf("%*s"); // Skip the time part
        scanf("%*s"); // Skip the user_id
        scanf("%*s"); // Skip the question_id

        sscanf(dateStr, "%d-%d-%d", &currentDate.year, &currentDate.month, &currentDate.day);

        // If it's a new date, print the count for the last date and reset the count
        if (count > 0 && compareDates(currentDate, lastDate) != 0) {
            printf("%04d-%02d-%02d %d\n", lastDate.year, lastDate.month, lastDate.day, count);
            count = 0;
        }

        count++;
        lastDate = currentDate;
    }

    // Print the count for the last date if there are any quiz attempts
    if (count > 0) {
        printf("%04d-%02d-%02d %d\n", lastDate.year, lastDate.month, lastDate.day, count);
    }

    return 0;
}
