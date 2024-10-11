#include <stdio.h>
#include <stdlib.h>
int main()
{
    char filename[100];
    FILE *file;
    float monthly_sales[12];
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    printf("Enter your input file: ");
    scanf("%s",filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;   
        }

    printf("Monthly Sales Report for 2024\n\n","%-10s %-10s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        fscanf(file, "%f", &monthly_sales[i]);
        printf("%-10s %-10f\n", months[i], monthly_sales[i]);
    }
    fclose(file);
    return 0;

    }