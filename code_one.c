/* Name: Emma Roy
   Lab number & Section: Lab 05, Friday 1PM
   File Purpose: This file takes an input file and provides the user with every value given with its correlating month,
   a sales summary report, six month moving report, and ordering based on higest to lowest revenue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h> 
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
    float month_max = FLT_MIN;
    float month_min = FLT_MAX;
    float avg = 0;
    float month_avg[7] = {0};
    int max_index=-1, min_index = -1;
    printf("\nMonthly Sales Report for 2024\n\n","%-10s %-10s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        fscanf(file, "%f", &monthly_sales[i]);
        
        if(monthly_sales[i] > month_max){
            month_max = monthly_sales[i];
            max_index = i;
        }
         if(monthly_sales[i] < month_min){
            month_min = monthly_sales[i];
            min_index = i;
         }
        if (i >= 0 && i <= 5) month_avg[0] += monthly_sales[i]; // Jan to June
        if (i >= 1 && i <= 6) month_avg[1] += monthly_sales[i]; // Feb to July
        if (i >= 2 && i <= 7) month_avg[2] += monthly_sales[i]; // March to Aug
        if (i >= 3 && i <= 8) month_avg[3] += monthly_sales[i]; // April to Sept
        if (i >= 4 && i <= 9) month_avg[4] += monthly_sales[i]; // May to Oct
        if (i >= 5 && i <= 10) month_avg[5] += monthly_sales[i]; // June to Nov
        if (i >= 6 && i <= 11) month_avg[6] += monthly_sales[i]; // July to Dec
        printf("%-10s %-10.2f\n", months[i], monthly_sales[i]);
        avg = (avg+ monthly_sales[i]);
        }
    printf("\nSales Summary Report:\n");
    printf("Highest Sales: %.2f (%s)\n", month_max, months[max_index]); 
    printf("Lowest Sales: %.2f (%s)\n", month_min, months[min_index]);
    printf("Average Sales: %.2f\n", avg/12);
    printf("\nSix-Month moving average report:\n\n");
    char mth[50];

    for (int i = 0; i < 6; i++) {
        strcpy(mth, months[i]);
        strcat(mth, "-");
        strcat(mth, months[i + 5]);
        printf("%-15s %.2f\n", mth, month_avg[i] / 6);
    }
    int indices[12];
    for (int i = 0; i < 12; i++) {
        indices[i] = i; // Initialize indices
    }

// Simple selection sort based on monthly_sales
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (monthly_sales[indices[i]] < monthly_sales[indices[j]]) {
                // Swap indices
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
        }
    }
}

// Print sorted sales from highest to lowest
printf("\nSales from Highest to Lowest:\n");
printf("%-10s %-10s\n", "Month", "Sales");
for (int i = 0; i < 12; i++) {
    printf("%-10s %-10.2f\n", months[indices[i]], monthly_sales[indices[i]]);
}
    fclose(file);
    return 0;
    }


